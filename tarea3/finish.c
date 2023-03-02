/*Ana Gabriela Argüello Cedeño
8976713*/


#include <stdio.h>
int main() {
	int casos = 0, gasEst= 0, flag = 1, gas= 0, si=0, flag2= 1;
	int cntTanque = 0, cnt1 = 0, cnt2 = 0, cnt = 0,cant = 0;
	int t= 0,dispo= 0,need= 0;
	int pis[10000], qis[10000];
	scanf("%d",&casos);
	for (t = 1; t <= casos; t++) {
		scanf("%d",&gasEst);
		scanf("%d",&pis[0]);
		cnt1 += pis[0];
		for(dispo = 1; dispo<=gasEst-1; dispo++) {
			scanf("%d",&pis[dispo]);
			cnt1 += pis[dispo];
		}
		scanf("%d",&qis[0]);
		cnt2 += qis[0];
		for(need = 1; need<=gasEst-1; need++) {
			scanf("%d",&qis[need]);
			cnt2 += qis[need];
		}
		if (cnt1 >= cnt2) {
			while((flag2 != 0)&&(cnt <= gasEst-1)) {
				cant = gas;
				si = gas+1;
				flag = 1;
				while((cnt <= gasEst-1)&&(flag !=0)) {
					cntTanque += pis[cant]-qis[cant];
					if(cnt == gasEst-1) {
						printf("Case %d: Possible from station %d\n",t,si);
						flag2 = 0;
						flag = 0;
					}
					if (cntTanque >= 0 ) {
						cnt += 1;
					} else {
						cntTanque = 0;
						flag = 0;
					}
					cant++;
					if ((cnt <= gasEst-1)&&(cant == gasEst)) {
						cant = 0;
					}
				}
			gas++;
			cnt = 0;
			}
		}else {
			printf("Case %d: Not possible\n",t);
		}
		cntTanque = 0;
		gas = 0;
		si = 0;
		dispo = 0;
		need = 0;
		cnt = 0;
		cnt1 = 0;
		cnt2 = 0;
		cant = 0;
		gasEst= 0;
		flag = 1;
		flag2 = 1;
	}
	return 0;
}