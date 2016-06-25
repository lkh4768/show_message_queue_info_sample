#ifndef MSG_QUEUE_H
#define MSG_QUEUE_H

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stdexcept>

class MsgQueue
{
	private:
		int id;
		key_t key;
		struct msqid_ds msq_status;
		void update_msq_status();
	public:
		void init(const key_t&);
		int get_id();
		msgqnum_t& get_qnum();
		pid_t& get_last_snd_pid();
		time_t& get_last_snd_time();
		pid_t& get_last_rcv_pid();
		time_t& get_last_rcv_time();
};

#endif
