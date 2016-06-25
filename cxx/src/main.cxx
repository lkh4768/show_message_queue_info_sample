#include "MsgQueue.hxx"

#include <cstdio>

int main(int argc, char** argv)
{
	try
	{
		if(argc != 2)
			throw std::runtime_error("usage: ./main keyvalue\n");
	}
	catch(const std::exception& e)
	{
		printf("%s", e.what());
		exit(1);
	}

	MsgQueue msg_queue;

	try
	{
		msg_queue.init(atoi(argv[1]));
	}
	catch(const std::exception& e)
	{
		printf("main - %s", e.what());
		exit(1);
	}

	printf("\nmsg_qid %d\n\n", msg_queue.get_id());
	printf("%d message(s) on queue\n", msg_queue.get_qnum());
	printf("Last send by proc %d at %s\n", msg_queue.get_last_snd_pid(), ctime(&(msg_queue.get_last_snd_time())));
	printf("Last recive by proc %d at %s\n", msg_queue.get_last_rcv_pid(), ctime(&(msg_queue.get_last_rcv_time())));
	return 0;
}
