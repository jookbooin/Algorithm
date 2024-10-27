#include <stdio.h>
int perfect_number(int n) {
    int i, sum = 0;

    for (i = 1; i <= n / 2; i++) {
        if (n % i == 0) 
            sum += i;
    }
    if (n == sum) return 1;
    return 0;
}

int main() {
    int i;
    
    int k=3;


    int k_cnt = 0, s= 2;
    while(1){
        
        if (perfect_number(s)){
            k_cnt++;
        }

        if(k_cnt == k){
            printf("%d\n",s);
            break;
        }
        s++;
    }

    printf("\n");

    return 0;
}