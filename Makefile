# Code Style Check

install-c++:
	pip install cpplint
	brew install cppcheck

check:
	cpplint leetcode/*
	cppcheck --enable=all --platform=unix64 --std=c11 leetcode/
