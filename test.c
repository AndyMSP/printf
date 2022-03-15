#include "main.h"

int main(void)
{
	int _len, len;

	_len = _printf("test%");
	len = _printf("test%");

	printf("TEST END LINE: _len = %i, len = %i\n", _len, len);

	return (0);
}
