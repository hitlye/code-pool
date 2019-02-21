# Makefile to automate build & test
# Author: Leo

.PHONY: test

all:
	@echo "Please specify an argument: test"

test:
	@echo "Start compiling tests..."
	mkdir -p output
	clang++ -std=c++11 -Wall src/fast_json_test.cpp -o output/fast_json_test
	@echo "Start running test..."
	./output/fast_json_test
