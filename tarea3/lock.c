/*Ana Gabriela Argüello Cedeño
8976713*/

#include <stdio.h>
#include <stdlib.h>
int main(){
	int i;
	int lock[3];
	int posi= 0;
	int cnt = 1080;
	int sum = 0;
	int flag = 1;
	int ceros = 0;
	scanf("%d",&posi);
	ceros += posi;
	while(flag != 0){
		for(i =0; i<= 2; i++){
			scanf("%d",&lock[i]);
			ceros += lock[i] ;
		}
		if (ceros == 0){
			flag = 0;
		}else{
			if((posi-lock[0])<0){
				sum += (40 - abs(posi-lock[0]));
			}else{
				sum += (posi-lock[0]);
			}
			if((lock[0]-lock[1])>0){
				sum += (40-(lock[0]-lock[1]));
			}else if (lock[0]-lock[1]==0){
				sum += 2;
			}
			else{
				sum += abs(lock[0]-lock[1]);
			}
			if((lock[1]-lock[2])<0){
				sum += 40-abs(lock[1]-lock[2]);
			}else if (lock[1]-lock[2]==0){
				sum += 39-abs(lock[1]-lock[2]);
			}else{
				sum += (lock[1]-lock[2]);
			}
			cnt += sum*9;
			printf("%d\n",cnt);
			cnt = 1080;
			posi = 0;
			scanf("%d",&posi);
			sum = 0;
			flag = 1;
			ceros = 0;
		}
	}
	return 0;
}