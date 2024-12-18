// 6-k 14003 참고 

#include <algorithm>
#include <cstdio>
using namespace std;
int n, lis[1001], len, num;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        auto lowerPos = lower_bound(lis, lis + len, num);
        if (*lowerPos == 0) len++;
        *lowerPos = num;
        for (int j = 0; j < n; j++) {
            printf("%d ", lis[j]);
        }
        printf("\n");
    }
    printf("%d", len);
    return 0;
}

/*
6
10 20 10 30 25 50

6
10 20 5 30 25 50
*/