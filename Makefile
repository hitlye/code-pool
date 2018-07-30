# Code Style Check

check:
	cpplint leetcode/*
	cppcheck --enable=all --platform=unix64 --std=c11 --suppress=unusedFunction --suppress=missingInclude leetcode/

install-c++:
	pip install cpplint
	brew install cppcheck
