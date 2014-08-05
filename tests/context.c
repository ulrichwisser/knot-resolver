#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include <libknot/mempattern.h>
#include "lib/context.h"

/* \note Create context and close it. */
static void tests_ctx_create(void **state)
{
	mm_ctx_t mm;
	mm_ctx_init(&mm);
	struct kresolve_ctx ctx;
	assert_int_equal(kresolve_ctx_init(&ctx, &mm), 0);
	assert_int_equal(kresolve_ctx_close(&ctx), 0);
}

int main(void)
{
	const UnitTest tests[] = {
	        unit_test(tests_ctx_create),
	};

	return run_tests(tests);
}