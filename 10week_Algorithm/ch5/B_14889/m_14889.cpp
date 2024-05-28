/**
 * 각각 N/2 명씩 링크팀 / 스타트 팀
 *
 * Sij + Sji
 *
 * 스타트팀, 링크팀 능력치 차이 최소
 *
 * N = 20
 * 20C10 = ( 184756 )
 *
 *
 * 1. 2팀으로 분리한다. (n1, n2) x
 * 2. 2개씩 묶는다. nC2 = (a,b) => Sab + Sba
 * 3. 뺀다 | Sn1 - Sn2 |
 *
 *
 * n 입력
 * 0 ~ (n-1)
 */

#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
int n, mi=INF;
int graph[24][24];
int visited[24];

int result (vector<int> &v) {
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            // 여기를 수정해야 합니다.
            sum += graph[v[i]][v[j]] + graph[v[j]][v[i]]; // 수정된 부분
        }
    }
    return sum;
}

void makeTeam(int start, int depth) {

    if (depth == n / 2) {
        vector<int> team1;
        vector<int> team2;
        
        // 1. 팀 구성 
        for(int i = 0; i< n; i++){
            if(visited[i]){
                team1.push_back(i);
            }else{
                team2.push_back(i);
            }
        }


        // 2. 계산 
        int ret1 = result(team1);
        int ret2 = result(team2);

        mi = min(mi, abs(ret1-ret2));

        return;
    }

    for (int i = start; i < n; i++) { // i+1 ~ n 까지 확인
            visited[i] = true;
            makeTeam(i + 1, depth + 1); // 현재점 포함 
            visited[i] = false;         // 현재점 포함 x
    }

}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    // 1. 팀 구성 
    makeTeam(0, 0);

    cout << mi << '\n';


    return 0;
}