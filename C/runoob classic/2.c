#include <stdio.h>
int main()
{
    int profit;
    double bouns;
    printf("profit=");
    scanf("%d",&profit);
    if (profit<=10){
        bouns=profit*0.1;
    }
    else if (profit<=20){
        bouns=1+(profit-10)*0.075;
    }
    else if (profit<=40){
        bouns=1.75+(profit-20)*0.05;  // 1.75=10*0.1+10*0.075（可以写式子） 
    }
    else if (profit<=60){
        bouns=2.75+(profit-40)*0.03;
    }
    else if (profit<=100){
        bouns=3.35+(profit-60)*0.015;
    }
    else{
        bouns=3.95+(profit-100)*0.01;
    }
    printf("bouns=%f",bouns);
	return 0;
}

