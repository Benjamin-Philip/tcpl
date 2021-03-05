#include <stdio.h>

main()
{
	print_v();
	print_f();
	print_d();
}

print_v()
{
	printf("Printing \\v:");
	printf("\v");
	printf("end\n");
}

print_f()
{
	printf("Printing \\f:");
	printf("\f");
	printf("end\n");
}

print_d()
{
	printf("Printing \\d:");
	printf("\d");
	printf("end\n");
}
