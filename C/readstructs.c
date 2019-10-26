#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
int main(int argc, char* argv[]) {
	if(argc < 3) {
    	perror("Invalid Arguments To Main\n");
        return errno;
    }
    int fd, i, n, count = 0;
	double check;
    struct info {
		int id;
		char name[16];
		double score;
	};
	struct info v[n];
	fd = open(argv[1], O_RDWR, S_IRUSR|S_IRUSR);
	if(fd == -1){
		perror("Error opening File\n");
		return errno;
	}
	read(fd, &n, sizeof(int));
	for(i = 0; i < n; i++) {
		read(fd, &v[i].id, (sizeof(int)));
		read(fd, v[i].name, (sizeof(char)*16));
		read(fd, &v[i].score, (sizeof(double)));;
	}
	sscanf(argv[2], "%lf", &check);
	for(i = 0; i < n; i++) {
		if(v[i].score == check) {
			printf("%d %s %lf\n", v[i].id, v[i].name, v[i].score);
			count++;
		}
	}
	if(count == 0) {
		printf("No Data for Entered Score\n");
	}
	close(fd);
	return 0;
}
