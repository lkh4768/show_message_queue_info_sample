#include "MsgQueue.hxx"

void MsgQueue::init(const key_t& key)
{
	if((id = msgget(key, 0)) == -1){
		std::string what = "MsgQueue init() error - ";
		what += strerror(errno);
		what += "\n";
		throw std::runtime_error(what);
	}

	this->key = key;

	try
	{
		update_msq_status();
	}
	catch(const std::exception& e)
	{
		printf("MsgQueue init() -> %s", e.what());
	}
}

void MsgQueue::update_msq_status()
{
	if(msgctl(id, IPC_STAT, &msq_status) == -1)
	{
		std::string what = "MsgQueue get_msq_status() error - ";
		what += strerror(errno);
		what += "\n";
		throw std::runtime_error(what);
	}
}

int MsgQueue::get_id()
{
	return id;
}

msgqnum_t& MsgQueue::get_qnum()
{
	return msq_status.msg_qnum;
}

pid_t& MsgQueue::get_last_snd_pid()
{
	return msq_status.msg_lspid;
}

time_t& MsgQueue::get_last_snd_time()
{
	return msq_status.msg_stime;
}

pid_t& MsgQueue::get_last_rcv_pid()
{
	return msq_status.msg_lrpid;
}

time_t& MsgQueue::get_last_rcv_time()
{
	return msq_status.msg_rtime;
}
