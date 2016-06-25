CC = g++
CFLAGS = -Wall -c -g
LFLAGS = -Wall -g -lgtest -lgtest_main
SRCS = ../src/MsgQueue.cxx MsgQueueTest.cxx MainTest.cxx
OBJS = $(SRCS:.cpp=.o) 
EXEC = testAll

$(EXEC) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $@

.cxx.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o $(EXEC)
