#include "main.h"

int main()
{
	int _len, len;

	_len = _printf(NULL);
	len = printf(NULL);

	printf("TEST END LINE: _len = %i, len = %i\n", _len, len);

	return (0);
}
