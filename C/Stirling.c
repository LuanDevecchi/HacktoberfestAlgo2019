#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ERRO 0.000000001
#define nep 2.7118282
#define pi 3.14159265359
	
double Raiz_2(double x){
	double app = 1.0;
	while (fabs(x-app*app)>ERRO)
	app = (x/(app+app))/2.0;
	system ("pause");
	return(app);
}

long int Coef_Bin(int N, int K){
	if ((K == 0) || (K == N)){if(K==0)printf("k==0 funcionei \n");else printf("k==n uncionei \n"); return(1);}
	else return(Coef_Bin(N-1,K-1) + Coef_Bin(N-1,K));	
}

int main(){
	int n; double result_1, result_2, final_result;
	printf("Digite o valor de n: "); scanf("%d",n);
	
	result_1 = Raiz_2(n*pi*2);
	printf("result_1 = %lf \n",result_1);
	
	//resultado_binomio = Coef_Bin(n,nep);
	 //printf("resultado_binomio = %lf)
	
	result_2 = pow((n/nep),n);
	printf("result_2 = %lf \n",result_2);
	
	final_result = result_1 * result_2;
	printf("Final Result = %lf \n",final_result);
	
	
	system("pause");
	return 0;
}
