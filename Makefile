build: *.cpp *.hpp
	clang++ hashlibpp/*.cpp -w *.cpp
	./a.out
