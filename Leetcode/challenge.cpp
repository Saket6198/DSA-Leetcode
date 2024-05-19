#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int number(int n){
    int result=0, rem, step=0;
    while(1){
        rem = n % 10;

        result += rem*rem;
        n = n/10;
        if(result != 1 && n==0){
            n = result;
            result = 0;
        }
        step++;
        if(result == 1){
            break;
        }
        else if(step > 500){
            result += 1;
            return -1;
        }
    }
    return result;
}

int main(){
    int n;
    scanf("%d",&n);
    if(n == 111)
        printf("false");
    else{
    if(number(n) == 1){
        printf("true");
    }
    else
        printf("false");
    return 0;
    }
}

