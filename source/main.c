#include <utility.h>

int main(void)
{
#ifdef MACRO_FORK
	function_fork();
#endif
#ifdef MACRO_WAIT
	function_wait();
#endif
	return 0;
}
