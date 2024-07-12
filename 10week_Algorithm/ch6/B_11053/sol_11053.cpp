#include <bits/stdc++.h>
using namespace std; 
int n, len, num;
int lis[1004];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
        scanf("%d", &num);

        auto lowerPos = lower_bound(lis, lis + len, num); // 0 ~ len 위치까지 num이 올 수 있는 순서를 반환 ( 이터레이터 )

        if(*lowerPos == 0) len++; // 반환받은 위치의 값이 0이다 ? → 더 큰수를 발견한 것이므로
        *lowerPos = num;          // 추가한다.

        for(int i = 0; i<n; i++){
            cout << lis[i] << ' ';
        }
        cout << '\n';
    }
	printf("%d\n", len); 
	return 0;
} 