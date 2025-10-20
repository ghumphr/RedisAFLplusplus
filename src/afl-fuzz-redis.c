#ifdef USE_REDIS

#include "afl-fuzz.h"
#include <hiredis/hiredis.h>

u8 *calc_redis_hashstring(afl_state_t *afl, struct queue_entry *q)
{
	return sha1_hex(queue_testcase_get(afl, q), q->len);
}

u8 *get_redis_hashstring(afl_state_t *afl, struct queue_entry *q)
{
	if(q->redis_hashstring)
	{
		return q->redis_hashstring;
	}
	q->redis_hashstring = calc_redis_hashstring(afl, q);
	return q->redis_hashstring;
}

unsigned int redis_inc_fuzz_level(afl_state_t *afl, struct queue_entry *q)
{
	u8 *hashstring = get_redis_hashstring(afl, q);
	redisReply *reply = redisCommand(afl->redis_context, "INCR fuzz_level/%s", hashstring);
	unsigned int rv = reply->integer;
	freeReplyObject(reply);
	return rv;
}

unsigned int redis_get_fuzz_level(afl_state_t *afl, struct queue_entry *q)
{
	u8 *hashstring = get_redis_hashstring(afl, q);
	redisReply *reply = redisCommand(afl->redis_context, "GET fuzz_level/%s", hashstring);
	unsigned int rv = reply->integer;
	freeReplyObject(reply);
	return rv;
}



#endif
