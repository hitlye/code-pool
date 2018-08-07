# Code Style Check
CHECKSTYLE_VERSION=8.11

check: check-cpp check-java

check-cpp:
	@echo "====================C++ Checking==================="
	cpplint leetcode/cpp/*
	cppcheck --enable=all --platform=unix64 --std=c11 --inline-suppr --suppress=unusedFunction --suppress=missingInclude leetcode/cpp/

check-java:
	@echo "====================Java Checking==================="
	java -jar checkstyle.jar -c /google_checks.xml  leetcode/java/

install-c++:
	pip install cpplint
	brew install cppcheck

install-java:
	rm -f checkstyle.jar
	wget https://github.com/checkstyle/checkstyle/releases/download/checkstyle-${CHECKSTYLE_VERSION}/checkstyle-${CHECKSTYLE_VERSION}-all.jar -O checkstyle.jar
