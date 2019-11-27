#include <fcntl.h>
#include <unistd.h>

main()
{
	int fp;
	ssize_t nread;
	char buf[20];

	fp = open("test.txt", O_RDONLY);

	nread = read(fp, buf, 20);

	close(fp);


	}
