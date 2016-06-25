CC = g++
CFLAGS = -Wall -c -g
LFLAGS = -Wall -g -lgtest -lgtest_main
SRCS = MsgQueue.cxx main.cxx
OBJS = $(SRCS:.cpp=.o) 
EXEC = show_msg_queue_info

$(EXEC) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $@

.cxx.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o $(EXEC)
