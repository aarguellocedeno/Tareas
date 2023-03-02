/*Ana Gabriela Argüello Cedeño
8976713*/


#include <stdio.h>
#include <stdlib.h>
int main(){
	int i,a,m;
	int k = 0;
	int j = 0;
	int cant = 0;  
	int flag = 1;    
	int cnt = 0; 
	int nojo = 0;      
	int res = 0;
	int joll[3000];
	int num[3000];
	while((scanf("%d",&cant)) != EOF){
		flag = 1;
		scanf("%d",&num[0]); 
		for (i = 1; i < cant; i++){
			scanf("%d",&num[i]);
			res = abs(num[i-1] - num[i]);
			if (res < cant){
				joll[i-1] = res;
				cnt += 1;
			}
		}
		while((flag != 0)&&(k<cant-1)){
			a = joll[k];
			m = k+1;
			while ((flag != 0)&&(m<cant-1)){
				if (a==joll[m]){
					nojo += 1;
					flag = 0;
				}
			m++;
			}
		k++;
		}
		if ((cnt == cant-1)&&(nojo == 0)){
			printf("Jolly\n");
			nojo = 0;
		}else{
			printf("Not jolly\n");
			nojo = 0;
		}	
	k = 0;
	cant = 0;  
	flag = 1;    
	cnt = 0; 
	nojo = 0;      
	res = 0;
	}
	return 0;
}
