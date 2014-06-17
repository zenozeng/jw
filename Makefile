build:
	g++ *.cpp lib/hashlibpp/*.cpp -w lib/lib.cpp views/*.cpp models/*.cpp -o a.out
	./a.out

test:
	g++ lib/hashlibpp/*.cpp -w lib/lib.cpp test/test.cpp -o a.out
	./a.out

wintest: 
	g++ -D _WIN32 lib/hashlibpp/*.cpp -w lib/lib.cpp test/test.cpp -o a.exe
	./a.exe

winbuild: *.cpp *.hpp
	g++ -D _WIN32 *.cpp lib/hashlibpp/*.cpp -w lib/lib.cpp views/*.cpp models/*.cpp -o a.exe

.PHONY: build test winbuild wintest
