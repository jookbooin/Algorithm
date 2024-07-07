/**
 * 플러그를 빼는 횟수 최소화
 * 구멍 수, 총 사용횟수
 *
 * 구멍수 : N
 * 총 사용횟수 : K
 *
 * 2개, 7번
 * 2 3 2 3 1 2 7
 *        (3) (1)
 *
 * -> 이후 나올 것 예상하고 있어야 함
 * 2 : 3
 * 3 : 2
 * 1 : 1
 * 7 : 1
 *
 * -> 이름 = N
 * -> 사용 (빈도)가 높으면 안뽑는게 낫지 않나?
 *
 * 1. 현재 코드에 있는 것 : 2, 3
 * 2. 이후에 남은 상태를 저장하는 배열 (2:2번 남음), (3: 1번 남음)
 *    -> 현재 코드에서 적게 남은 것 제거
 * 3. 순서는 stack에 저장
 *
 */

#include <bits/stdc++.h>

using namespace std;

int n, k, input, cnt = 0;
vector<int> v;


int ch[104];       // 뒤에 나올 개수
int visited[104];  // 현재 코드에 존재하는지 확인

struct compare{
    bool operator()(int a, int b){
        return ch[a] > ch[b];       // 최소 
    }
};

priority_queue<int, vector<int>, compare> pq; // ch[] 작은 것pop

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> input;
        ch[input]++;
        v.push_back(input);
    }

    for(int i =0; i< v.size(); i++){
        int next = v[i];

        if(pq.size() < n && !visited[next]){ // 1. pq에 더 들어갈 수 있을때
            cout << "1" <<'\n';
            pq.push(next);
            visited[next] = 1;
            ch[next] --;
            continue;
        }

        if(visited[next]) { // 2. 같은 숫자 이미 존재할 때
            cout << "2" <<'\n';
            ch[next] --;
            continue;
        }
        

        // 3. 교체
        cout << "3" <<'\n';
        cnt++; 
        int pp = pq.top(); pq.pop();
        cout << "pp : " << pp <<'\n';
        visited[pp] = 0;

        pq.push(next);
        visited[next] = 1;
        ch[next]--;

    }

     cout << cnt << '\n';

    return 0;
}

