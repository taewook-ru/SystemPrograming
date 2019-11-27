#include <stdio.h> 
#include <termios.h> 
#include <sys/types.h> 
#include <fcntl.h> 
#include <unistd.h> 
#include <time.h>
#include <sys/time.h>


#define PASSWORDSIZE 12

int main(void) 
{ 
	int fd; 
	int nread, cnt=0, errcnt=0;
       	time_t start =0, end =0;	
	int typing =0;
	char ch; 
	char text[] = "I know that listening and talking to native speakers of english are really difficult, which is why I strongly suggest you read the blog is writing"; 
	struct termios init_attr, new_attr;

	fd = open(ttyname(fileno(stdin)), O_RDWR); 
	
	tcgetattr(fd, &init_attr);

	new_attr = init_attr; 
	new_attr.c_lflag &= ~ICANON; new_attr.c_lflag &= ~ECHO; 
	/* ~(ECHO | ECHOE | ECHOK | ECHONL); */ 
	new_attr.c_cc[VMIN] = 1; new_attr.c_cc[VTIME] = 0; 
	if (tcsetattr(fd, TCSANOW, &new_attr) != 0) 
	{ fprintf(stderr, "터미널 속성을 설정할 수 없음.\n"); }

	printf("다음 문장을 그대로 입력하세요.\n%s\n", text);

	time(&start);	
	while ((nread=read(fd, &ch, 1)) > 0 && ch != '\n') {

		
		if (ch == text[cnt++]) write(fd, &ch, 1); 
		
		else { write(fd, "*", 1); errcnt++; } 
		typing++;
	} 
	time(&end);
	float gap= end - start;
	float tasu = 60 * (typing / gap);

	printf("\n타이핑 오류의 횟수는 %d\n", errcnt);
       	tcsetattr(fd, TCSANOW, &init_attr); close(fd);
       printf("타수는 %d \n", (int)tasu);	
}
