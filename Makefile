build:
	g++ hashlibpp/*.cpp -w *.cpp views/*.cpp models/*.cpp -o a.out
	./a.out

test:
	g++ hashlibpp/*.cpp -w lib.cpp test/test.cpp -o a.out
	./a.out

winbuild:
	g++ -D _WIN32 hashlibpp/*.cpp -w views/*.cpp *.cpp models/*.cpp -o a.out

.PHONY: build test winbuild
