#include"fcntl.h"
#include"user.h"
#include"stat.h"
int main(int argc, char *argv[]) {
	if(argc < 2) {
		printf(1, "not enough argument\n");
		exit();
	}
	int n, len, n2;
	n = open(argv[1], O_RDONLY);
	if( n < 0) {
		printf(1,"Not open"); 
	}
//	n2 = open("copy", O_WRONLY | O_CREATE);
	len = -1;
	while(!lseek(n,1)) {
		len++;
	}

	char string[len+1];
	n = open(argv[1], O_RDONLY);
	n2 = open("copy", O_WRONLY | O_CREATE);

	read(n, string, len);
	write(n2, string, len);
	
	close(n);
	close(n2);
	exit();

}
