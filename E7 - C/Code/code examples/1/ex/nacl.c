#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double rand01(){
	return (double)rand()/RAND_MAX;
}

main(){
	// simula la reazione chimica Na + Cl <--> Na+ + Cl-
	int na=1000; 			// atomi iniziali di Na
	int cl=2000; 			// atomi iniziali di Cl
	int nap=0; 				// ioni iniziali di Na+
	int clm=500; 			// ioni iniziali di Cl-
	double ionization=0.6; 	// rate di ionizzazione
	double deionization=0.4;// rate di deionizzazione
	int passi=2000; 		// passi da simulare
	int skip=10; 			// stampare ogni skip passi
	
	int i;					// contatore passi
	double time=0;			// tempo simulazione
	double r1,r2;           // velocità ionizzazione e deionizzazione
	
	for (i=0;i<passi;i++){
		r1=na*cl*ionization;
		r2=nap*clm*deionization;
		time += log(1/rand01())/(r1+r2); // incremento tempo
		if ((r1+r2)*rand01()<r1){		 // ionizzazione
			na--;
			cl--;
			nap++;
			clm++;
		} else {						 // deionizzazione	
			na++;
			cl++;
			nap--;
			clm--;
		}
		if (i%skip==0)
		   printf("%10d\t%10e\t%10d\t%10d\t%10d\t%10d\n",i,time,na,cl,nap,clm);
	}
	
}
