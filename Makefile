test :WillOnce

WillOnce: WillOnce.cpp Greeting.h
	g++ WillOnce.cpp -lgtest -lgtest_main -lgmock
	./a.out