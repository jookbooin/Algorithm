/**
 * k개 2^k-1개
 * 
 * 1. 루트
 * 2. 왼쪽 방문 x -> 왼쪽 방문
 * 3. 왼쪽 존재 x or 방문 o -> 현재 노드 방문 ( 종이에 저장 )
 * 4. 왼쪽 방문 o + 오른쪽 방문 o ->  부모로 이동
 * 
 *
 * 중위 순회..? 
 * 방문한 빌딩의 번호 순서대로 
 * 210 => 1-24 -> 1030?
 * 
 * 2k-1 = 3(1), 7(3), 15(7) --> (2^k - 1) == root 
 * 
 * 1 -> (2,3) -> (4,5) / (6,7)
*/

#include <bits/stdc++.h>

using namespace std;

const int max_len = 1030;
int ch[max_len];
int N ;

vector<int> adj[max_len];

void back(int start, int end,int depth){

    if(start > end) return ; // 종료 조건
    
    if(start == end){
        adj[depth].push_back(ch[start]);
        return;
    }

    int mid = (start + end)/2;

    adj[depth].push_back(ch[mid]);

    back(start, mid-1,depth + 1);
    back(mid+1, end ,depth + 1);
}

int main(void){
    cin >> N;

    for(int i=0; i< pow(2,N); i++){
        cin >> ch[i];
    }

    back(0,pow(2,N)-1,1); // sIdx, eIdx , depth 

    for(int i = 1; i<=N ; i++){
        for(auto a : adj[i]){
            cout << a << " ";
        }
        cout << endl;
    }

    return 0;
}

