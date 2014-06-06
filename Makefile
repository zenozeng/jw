build: *.cpp *.hpp
	g++ hashlibpp/*.cpp -w *.cpp -o a.out
	./a.out

test: *.cpp *.hpp
	g++ hashlibpp/*.cpp -w lib.cpp test/test.cpp -o a.out
	./a.out

.PHONY: test build
