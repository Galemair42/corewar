int	main(void)
{
	unsigned sa = 0x90;
	sa = sa << 24;
	printf("%u\n", sa);
	sa = sa << 4;
	sa = sa >> 30;
	printf("%u\n", sa);
}
