# Code Style Check

install-c++:
	pip install cpplint

check:
	cpplint leetcode/*
	cppcheck leetcode/
