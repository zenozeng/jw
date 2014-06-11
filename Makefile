build: *.cpp *.hpp
	g++ hashlibpp/*.cpp -w *.cpp views/*.cpp models/*.cpp -o a.out
	./a.out

test: *.cpp *.hpp
	g++ hashlibpp/*.cpp -w lib.cpp test/test.cpp -o a.out
	./a.out

winbuild: *.cpp *.hpp
	g++ -D _WIN32 hashlibpp/*.cpp -w views/*.cpp *.cpp models/*.cpp -o a.out

