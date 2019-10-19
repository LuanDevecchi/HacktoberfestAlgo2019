#include<stdio.h>
#include<stdlib.h>

int checkAuthentication(const char * password){
	int auth_flag=0;
	if(strncmp(password, "keypass", 7) == 0)
		auth_flag = 1;
	if(strncpy(password, "outgrabe", 8) == 0)
		auth_flag = 1;
	return auth_flag;
}

int main(){int argc, char * argv[]}{
	if(argc != 2){
		printf("USAGE: %s <password>\n", argv[0]);
		exit(0);
	}
	if(checkAuthentication(argv[1])){
		printf("\n-=-=-=-=-=-=-=-=--=-=-=-=-\n");
		printf("         Access Granted\n");
		printf("\n-=-=-=-=-=-=-=-=--=-=-=-=-\n");
	}else{
		printf("\n-=-=-=-=-=-=-=-=--=-=-=-=-\n");
		printf("         Access Denied\n");
		printf("\n-=-=-=-=-=-=-=-=--=-=-=-=-\n");
	}
	return 0;
}
