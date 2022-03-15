#include "main.h"

int main()
{
	int _len, len;

	_len = _printf("String:[%s]\n", "I am a string !");
	len = printf("String:[%s]\n", "I am a string !");

	printf("TEST END LINE: _len = %i, len = %i\n", _len, len);

	return (0);
}
