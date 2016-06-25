#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <limits.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include "gtest/gtest.h"
#include "../src/MsgQueue.hxx"

key_t msq_id = 0105;

class MsgQueueTest : public ::testing::Test
{
	public:
		static MsgQueue msg_queue;
	protected:
		static void SetUpTestCase()
		{
			try
			{
				msg_queue.init(msq_id);
			}
			catch(const std::exception& e)
			{
				printf("SetUp -> %s", e.what());
				exit(1);
			}

		}
};

MsgQueue MsgQueueTest::msg_queue;

TEST_F(MsgQueueTest, init_test)
{
	ASSERT_GT(msg_queue.get_id(), -1); 
};

TEST_F(MsgQueueTest, get_qnum_test)
{
	ASSERT_EQ(msg_queue.get_qnum(), 0);
}
