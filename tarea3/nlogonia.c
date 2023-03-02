/*Ana Gabriela Argüello Cedeño
8976713*/


#include <stdio.h>

int main(){
	int i,j,a;
	int coord = 0;
	int resid[2];
	int num = 0;
	int coordy = 0;
	int coordx = 0;
	scanf("%d",&num);
	while (num != 0){
		for (i = 1;i <= 2; i++){
			scanf("%d",&coord);
			if (i == 1){
				coordx = coord;
			}else if(i == 2){
				coordy = coord;
			}
			
			}
		for (j = 1;j <= num; j ++){
			for (a = 0;a<= 1;a ++){
				scanf("%d",&resid[a]);
			}
			if ((resid[0] > coordx ) && (resid[1] > coordy) ){
				printf("NE\n");
			}else if ((resid[0] < coordx ) && (resid[1] < coordy)){
				printf("SO\n");
			}else if((resid[0] < coordx) && (resid[1] > coordy)){
				printf("NO\n");
			}else if((resid[0] > coordx) && (resid[1] < coordy)){
				printf("SE\n");
			}else if((resid[0] == coordx ) || (resid[1] == coordy)){
				printf("divisa\n");
			}
			}
		num = 0;
		scanf("%d",&num);
		coord = 0;
		coordx = 0;
		coordy = 0;
		}

		return 0;
		}


