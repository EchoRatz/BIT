#include <stdio.h>  
  
int gcd(num1,num2){  
      
    int i, result;  
      
    for(i = num1; i > 0; i--){  
        if(num1 % i == 0 && num2 % i == 0){  
            result = i;  
            break;  
        }  
    }  
    return result;  
}   
  
int lcm(num1, num2){  
      
    int i, result;  
      
    for( i = num2; i > 0 ; i++){  
        if(i % num1 == 0 && i % num2 == 0){  
            result = i;  
            break;  
        }  
    }  
    return result;  
}  
  
int main(){  
      
    int num1, num2;  
      
    while(1){  
          
        scanf("%d %d", &num1, &num2);  
  
        if(num1 == 0 && num2 == 0) break;  
          
        if(num1 <= 0 || num2 <= 0){  
            printf("Error!\n");  
            continue;  
        }  
  
        printf("The GCD of %d and %d is:%d\n", num1, num2, gcd(num1, num2));  
        printf("The LCM of %d and %d is:%d\n", num1, num2, lcm(num1, num2));  
    }  
}  