#include "main.h"
#include <limits.h>

int main()
{
	int _len, len;

	_len = _printf("%i\n", 0);
	len = printf("%i\n", 0);

	printf("TEST END LINE: _len = %i, len = %i\n", _len, len);

	return (0);
}
