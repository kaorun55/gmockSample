test :WillOnce Times

WillOnce: WillOnce.cpp Greeting.h
	g++ WillOnce.cpp -lgtest -lgtest_main -lgmock
	./a.out

Times: Times.cpp Greeting.h
	g++ Times.cpp -lgtest -lgtest_main -lgmock
	./a.out
