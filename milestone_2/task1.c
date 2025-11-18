#include<stdio.h>
#define MAX_SIZE 1000
int fib[MAX_SIZE];
int fibonacci(int number){
    if((number==0)||(number==1)) return number;
    if(fib[number]) return fib[number];
    else {
        fib[number] = fibonacci(number - 1) + fibonacci(number - 2);
        return fib[number];
    }
}

int main(){
    int seq=0,guess1=0,guess2=0;
   scanf("%d %d %d",&seq,&guess1,&guess2);
  // printf("%d",fibonacci(12));
  int output= fibonacci(seq);
  if(output==guess1) printf("TRUE");
  else if(output==guess2)printf("TRUE");
  else printf("FALSE");
  //printf("%d",output);

    return 0;
}