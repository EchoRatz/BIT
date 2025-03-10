#include <stdio.h>  
#include <math.h>  
  
int main(){  
    int i,j,low,high,operate,digitNum,armNum,sum,counter = 0;  
      
    scanf("%d", &digitNum);  
      
    high = pow(10,digitNum);  
    low = pow(10,digitNum-1);  
  
      
    for(i = low; i < high;i++){  
          
         armNum = i;  
         sum = 0;  
           
         for(j = digitNum - 1;armNum != 0;j --){  
              
            operate = pow(10,j);  
            sum += pow(armNum/operate,digitNum);  
            armNum %= operate;  
         }  
           
         if(sum == i){  
            printf("%d\n", i);  
            counter ++;  
         }  
}  
if (counter == 0){  
    printf("No output.\n");  
}  
}  