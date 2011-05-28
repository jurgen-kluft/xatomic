#include "xbase\x_types.h"
#include "xunittest\xunittest.h"

#include "xmulticore\x_lifo.h"

UNITTEST_SUITE_BEGIN(lifo)
{
    UNITTEST_FIXTURE(main)
    {
        UNITTEST_FIXTURE_SETUP() {}
        UNITTEST_FIXTURE_TEARDOWN() {}

		UNITTEST_TEST(construct1)
		{
			xcore::atomic::lifo f;
		}

		UNITTEST_TEST(construct2)
		{
			xcore::atomic::lifo f(16);

			CHECK_EQUAL(true, f.empty());
			CHECK_EQUAL(16, f.room());
		}

		UNITTEST_TEST(push1_pop1)
		{
			xcore::u32 i, r;
			xcore::atomic::lifo f(16);

			CHECK_EQUAL(true, f.empty());
			CHECK_EQUAL(16, f.room());

			xcore::s32 x = 0;
			for (xcore::s32 y=0; y<100; ++y, ++x)
			{
				if (x == 16) x = 0;

				CHECK_EQUAL(true, f.push(x));
				CHECK_EQUAL(false, f.empty());

				CHECK_EQUAL(true, f.pop(i,r));
				CHECK_EQUAL(x, i);
				CHECK_EQUAL(x, r);
				CHECK_EQUAL(true, f.empty());

			}
		}

		UNITTEST_TEST(push2_pop2)
		{
			xcore::u32 i, r;
			xcore::atomic::lifo f(16);

			CHECK_EQUAL(true, f.empty());
			CHECK_EQUAL(16, f.room());

			xcore::s32 x = 0;
			for (xcore::s32 y=0; y<100; ++y, x+=2)
			{
				// Push 2

				if (x == 16) x = 0;
				CHECK_EQUAL(true, f.push(x));
				CHECK_EQUAL(false, f.empty());

				++x;
				if (x == 16) x = 0;
				CHECK_EQUAL(true, f.push(x));
				CHECK_EQUAL(false, f.empty());

				// Pop 2

				CHECK_EQUAL(true, f.pop(i,r));
				CHECK_EQUAL(x, i);
				CHECK_EQUAL(x, r);
				CHECK_EQUAL(false, f.empty());

				if (x==0) x=15;
				else --x;

				CHECK_EQUAL(true, f.pop(i,r));
				CHECK_EQUAL(x, i);
				CHECK_EQUAL(x, r);
				CHECK_EQUAL(true, f.empty());
			}
		}
	}
}
UNITTEST_SUITE_END