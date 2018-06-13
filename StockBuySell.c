/*
make the max profit of stock buy and sell once (Cannot short)
*/ 

#include <stdlib.h> 
#include <stdio.h> 

void SellBuy_1(int sp[], int n)
{
	int dayBuy=0;
	int daySell=1;
	int maxProfit=sp[1]-sp[0];
	
	for(int i=0; i<n; i++){ 
		for(int j=i+1; j<n; j++){ 
			if((sp[j]-sp[i]>maxProfit)){ 
				
				dayBuy=i;
				daySell=j;
				maxProfit=sp[j]-sp[i];
				
			}
		}		
	}
	
	printf("Buy at day %d, and sell at day %d.", dayBuy, daySell);
	printf(" The most profit is %d.\n", maxProfit);
}

void SellBuy_2(int sp[], int n)
{
	int dayBuy=0;
	int daySell=1;
	int maxProfit=0;
	int minPrice=999;
	int diff;

	for(int i=0; i<n; i++){
	
		if(sp[i]<minPrice){
			minPrice=sp[i];
			dayBuy=i;
		}	
	
		diff=sp[i]-minPrice;
		if(sp[i]-minPrice>maxProfit){
			maxProfit=diff;
			daySell=i;
		}	
	}
	
	printf("Buy at day %d, and sell at day %d.", dayBuy, daySell);
	printf(" The most profit is %d.\n", maxProfit);
}

int main()
{
	int stockPrice[]={2,40,6,8,7,1,9};
	int n=sizeof(stockPrice)/sizeof(int);
	
	SellBuy_1(stockPrice, 7); 
	SellBuy_2(stockPrice, 7);
		
}
