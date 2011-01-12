/*
 args be pushed to stack from right to left
*/
int add(int x, int y)
{
	int a = 0;
	a = x;
	a += y;
	return a;
}

int main(int argc, char *argv[])
{
	int x, y, result;
	x = 0x12;
	y = 0x34;
	result = add(x, y);
	return 0;
}

