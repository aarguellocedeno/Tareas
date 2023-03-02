/*Ana Gabriela Argüello Cedeño
8976713*/


#include <stdio.h>

int main () {
	int i,j;
	int men = 0;
	int may = 0;
	int ans = 0;
	int arr [100];
	int numberStores,testCases;
	scanf("%d",&numberStores);
	for(j= 1; j <= numberStores; j++) {
		scanf("%d",&testCases);
		scanf("%d",&arr[0]);
		may = arr[0];
		men = arr[0];
		for (i=1 ; i <=testCases-1; i++) {
			scanf("%d",&arr[i]);
			if (men > arr[i]){
				men = arr[i];
			}else if (may < arr[i]){
				may = arr[i];
			}
		ans = 2*(may-men);

		}
		printf("%d\n",ans);
		ans = 0;
		men = 0;
		may = 0;
	}
	
	return 0;
}
