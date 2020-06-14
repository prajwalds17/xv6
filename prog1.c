#include"fcntl.h"
#include"user.h"
#include"stat.h"
int main(int argc, char *argv[]){
	if(argc < 5){
		printf(1,"not enough argument\n");
		exit();
	}
	int n, off, len;
	n = open(argv[1], O_RDONLY);
	off = atoi(argv[2]);
	len = atoi(argv[3]);
	lseek(n,off);
	char string[len + 1];
	read(n , string, len);
	if(!strcmp(string, argv[4])) {
		printf(1, "Matched \n");
	}
	else {
		printf(1, "Match not found\n");
	}
	exit();

}
