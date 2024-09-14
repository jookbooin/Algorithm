/**
 * 단, 탄, 지, 비
 * 최소 100, 70, 90, 10
 *
 * 조건 만족하는 최소 비용의 식재료 집합
 * n : 15
 * mp ~ mv : 500
 *
 *
 * < 출력 >
 * 1. 최소 비용
 * 2. 최소 비용 식재료의 번호 (오름 차순)
 *    하나 이상이면 사전순으로 가장 빠른 것
 *
 * 3. 만족하는 것 없을 시
 *      * -1
 *      *  x
 *
 *
 * ------------------------------------
 * 1. 6개 중에 선택
 * 2. 조건 만족하는지 합 확인 ( 100, 70, 90, 10 )
 * 3. 최소 비용인지 확인
 * 4. 최소 비용 -> 자료구조 저장?
 *
 * 만족하지 않는다? -> 값 INF?
 * 4.
 */

#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;

int n, mp, mf, ms, mv, ans = INF, ret;

typedef struct _a {
    int p, f, s, v, c;
} aa;

vector<aa> aav;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    deque<int> dq;

    for(int i = 0; i<10; i++){
        dq.push_back(i+1);
    }

    for(int& a : dq){
        a++;
    }

    for(int a : dq){
        cout << a << " ";
    }

    return 0;
}