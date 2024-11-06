.DEFAULT_GOAL := all
SHELL         := bash

ifeq ($(shell uname -s), Darwin)
    ASTYLE        := astyle
    BOOST         := /usr/local/include/boost
    CHECKTESTDATA := checktestdata
    CPPCHECK      := cppcheck
    CXX           := clang++
    CXXFLAGS      := --coverage -g -std=c++20 -Wall -Wextra -Wpedantic
    DOXYGEN       := doxygen
    GCOV          := llvm-cov gcov
    GTEST         := /usr/local/include/gtest
    LDFLAGS       := -lgtest -lgtest_main
    LIB           := $(LIBRARY_PATH)
    VALGRIND      :=
else ifeq ($(shell uname -p), x86_64)
    ASTYLE        := astyle
    BOOST         := /lusr/opt/boost-1.82/include/boost
    CHECKTESTDATA := checktestdata
    CPPCHECK      := cppcheck
    CXX           := g++-11
    CXXFLAGS      := --coverage -g -std=c++20 -Wall -Wextra -Wpedantic
    DOXYGEN       := doxygen
    GCOV          := gcov-11
    GTEST         := /usr/include/gtest
    LDFLAGS       := -L/usr/local/opt/boost-1.77/lib/ -lgtest -lgtest_main -pthread
    LIB           := /usr/lib/x86_64-linux-gnu
    VALGRIND      := valgrind-3.17
else
    ASTYLE        := astyle
    BOOST         := /usr/include/boost
    CHECKTESTDATA := checktestdata
    CPPCHECK      := cppcheck
    CXX           := g++
    CXXFLAGS      := --coverage -g -std=c++20 -Wall -Wextra -Wpedantic
    DOXYGEN       := doxygen
    GCOV          := gcov
    GTEST         := /usr/include/gtest
    LDFLAGS       := -lgtest -lgtest_main -pthread
    LIB           := /usr/lib
    VALGRIND      := valgrind
endif

# run/test files, compile with make all
FILES :=               \
    run_Darwin  \
    test_Darwin

# run docker
docker:
	docker run --rm -it -v $(PWD):/usr/gcc -w /usr/gcc gpdowning/gcc

# get git config
config:
	git config -l

# get git log
Darwin.log.txt:
	git log > Darwin.log.txt

# get git status
status:
	make --no-print-directory clean
	@echo
	git branch
	git remote -v
	git status

# download files from the Darwin code repo
pull:
	make --no-print-directory clean
	@echo
	git pull
	git status

# upload files to the Darwin code repo
push:
	make --no-print-directory clean
	@echo
	git add .gitignore
	git add .gitlab-ci.yml
	-git add Darwin.csv
	-git add Darwin.ctd.txt
	git add Darwin.hpp
	-git add Darwin.log.txt
	-git add html
	git add Makefile
	git add README.md
	git add run_Darwin.cpp
	git add test_Darwin.cpp
	git commit -m "another commit"
	git push
	git status

# compile run harness
run_Darwin: Darwin.hpp run_Darwin.cpp
	-$(CPPCHECK) run_Darwin.cpp
	$(CXX) $(CXXFLAGS) run_Darwin.cpp -o run_Darwin

# compile test harness
test_Darwin: Darwin.hpp test_Darwin.cpp
	-$(CPPCHECK) test_Darwin.cpp
	$(CXX) $(CXXFLAGS) test_Darwin.cpp -o test_Darwin $(LDFLAGS)

# compile all
all: $(FILES)

# execute test harness with coverage
test: test_Darwin
	$(VALGRIND) ./test_Darwin
ifeq ($(shell uname -s), Darwin)
	$(GCOV) test_Darwin-test_Darwin.cpp | grep -B 2 "hpp.gcov"
else
	$(GCOV) test_Darwin.cpp | grep -B 2 "hpp.gcov"
endif

# clone the Darwin test repo
../cs371p-darwin-tests:
	git clone https://gitlab.com/gpdowning/cs371p-darwin-tests.git ../cs371p-darwin-tests

# generate a random input file
ctd-generate:
	$(CHECKTESTDATA) -g Darwin.ctd.txt >> Darwin.tmp.txt

test-generate: 
	-$(CPPCHECK) generateTestCases.cpp
	$(CXX) $(CXXFLAGS) generateTestCases.cpp -o darwin $(LDFLAGS)
	./darwin

# execute the run harness against your test files in the Darwin test repo and diff with the expected output
# change gpdowning to your GitLab-ID
run: run_Darwin ../cs371p-darwin-tests
	-$(CHECKTESTDATA) Darwin.ctd.txt ../cs371p-darwin-tests/karahphang-Darwin.in.txt
	./run_Darwin < ../cs371p-darwin-tests/karahphang-Darwin.in.txt > Darwin.tmp.txt
	diff Darwin.tmp.txt ../cs371p-darwin-tests/karahphang-Darwin.out.txt

# execute the run harness against all of the test files in the Darwin test repo and diff with the expected output
run-all: run_Darwin ../cs371p-darwin-tests
	-@for v in `ls ../cs371p-darwin-tests/*.in.txt`;         \
    do                                                              \
        echo $(CHECKTESTDATA) Darwin.ctd.txt $${v};          \
             $(CHECKTESTDATA) Darwin.ctd.txt $${v};          \
        echo ./run_Darwin \< $${v} \> Darwin.tmp.txt; \
             ./run_Darwin  < $${v}  > Darwin.tmp.txt; \
        echo diff Darwin.tmp.txt $${v/.in/.out};             \
             diff Darwin.tmp.txt $${v/.in/.out};             \
    done

# auto format the code
format:
	$(ASTYLE) Darwin.hpp
	$(ASTYLE) run_Darwin.cpp
	$(ASTYLE) test_Darwin.cpp

# you must edit Doxyfile and
# set EXTRACT_ALL     to YES
# set EXTRACT_PRIVATE to YES
# set EXTRACT_STATIC  to YES
# create Doxfile
Doxyfile:
	$(DOXYGEN) -g

# create html directory
html: Doxyfile
	$(DOXYGEN) Doxyfile

# check the existence of check files
check: .gitignore .gitlab-ci.yml Darwin.log.txt html

# remove executables and temporary files
clean:
	rm -f  *.gcda
	rm -f  *.gcno
	rm -f  *.gcov
	rm -f  *.gen.txt
	rm -f  *.tmp.txt
	rm -f  $(FILES)
	rm -rf *.dSYM

# remove executables, temporary files, and generated files
scrub:
	make --no-print-directory clean
	rm -f  Darwin.log.txt
	rm -f  Doxyfile
	rm -rf html
	rm -rf latex

# output versions of all tools
versions:
	uname -p

	@echo
	uname -s

	@echo
	which $(ASTYLE)
	@echo
	$(ASTYLE) --version

	@echo
	which $(CHECKTESTDATA)
	@echo
	$(CHECKTESTDATA) --version | head -n 1

	@echo
	which cmake
	@echo
	cmake --version | head -n 1

	@echo
	which $(CPPCHECK)
	@echo
	$(CPPCHECK) --version

	@echo
	which $(DOXYGEN)
	@echo
	$(DOXYGEN) --version

	@echo
	which $(CXX)
	@echo
	$(CXX) --version | head -n 1

	@echo
	which $(GCOV)
	@echo
	$(GCOV) --version | head -n 1

	@echo
	which git
	@echo
	git --version

	@echo
	which make
	@echo
	make --version | head -n 1

ifneq ($(VALGRIND),)
	@echo
	which $(VALGRIND)
	@echo
	$(VALGRIND) --version
endif

	@echo
	which vim
	@echo
	vim --version | head -n 1

	@echo
	grep "#define BOOST_LIB_VERSION " $(BOOST)/version.hpp

	@echo
	ls -al $(GTEST)/gtest.h
	@echo
	pkg-config --modversion gtest
	@echo
	ls -al $(LIB)/libgtest*.a
