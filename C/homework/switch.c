#include <stdio.h>
int main()
{
	int choice,i;
	double price;
	for (i=1;i<=5;i++){
	    printf("[1]select crisps\n");
	    printf("[2]select popcorn\n");
	    printf("[3]select chorolate\n");
	    printf("[4]select cola\n");
	    printf("[0]exit \n");
	    
	    printf("enter choice=");
	    scanf("%d",&choice);
	    
	    if (choice==0){
	        break;
	    }
	    
	    switch(choice){
	        case 1: price=3.0;break;
	        case 2: price=2.5;break;
	        case 3: price=4.0;break;
	        case 4: price=3.5;break;
	        default: price=0.0;break;
	    }
	    printf("price=%.2f\n",price);
	}
	printf("thanks");
	return 0;
}

