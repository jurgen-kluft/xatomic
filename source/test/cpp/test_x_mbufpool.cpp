#include "xbase\x_types.h"
#include "xbase\x_allocator.h"

#include "xunittest\xunittest.h"

#include "xatomic\x_mbufpool.h"
#include "xatomic\x_mbuf.h"

extern xcore::x_iallocator* gAtomicAllocator;

// #include <iostream>
// using namespace std;

using namespace xcore;
using namespace atomic;
using namespace mbuf;

UNITTEST_SUITE_BEGIN(mbufpool)
{
	inline s32 alignUp(s32 integer, s32 alignment = 4) {
		return ((integer + (alignment-1)) & (~(alignment-1)));
	}

	UNITTEST_FIXTURE(main)
	{
		UNITTEST_FIXTURE_SETUP() { }
		UNITTEST_FIXTURE_TEARDOWN() { }

		UNITTEST_TEST(constructor1)
		{
			pool pl(gAtomicAllocator, 0xff, 0xee);
			CHECK_TRUE(pl.valid());
		}
	}
}
UNITTEST_SUITE_END