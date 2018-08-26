# Code Style Check

check: check-cpp check-java

check-cpp:
	@echo "====================C++ Checking==================="
	cpplint leetcode/cpp/*
	cppcheck --enable=all --platform=unix64 --std=c11 --inline-suppr --suppress=unusedFunction --suppress=missingInclude leetcode/cpp/

check-java:
	@echo "====================Java Checking==================="
	java -jar checkstyle.jar -c /google_java_style_revised.xml  leetcode/java/

install-c++:
	pip install cpplint
	brew install cppcheck

install-java:
	rm -f checkstyle.jar
	wget https://s3.amazonaws.com/cmucc-public/utils/checkstyle/checkstyle.jar
