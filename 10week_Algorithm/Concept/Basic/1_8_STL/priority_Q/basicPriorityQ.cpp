#include <bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>,greater<int>> pq1; // ���� ���� ( �ּ� �� )
priority_queue<int> pq2; // ��������
priority_queue<int, vector<int>,less<int>> pq3; // �������� ( �ִ� �� )

int main(){

    for(int i = 5; i >= 1; i--){
        pq1.push(i); pq2.push(i);pq3.push(i);
    }
    
    while(pq1.size()){
        cout << pq1.top() << " | " << pq2.top() << " | " << pq3.top() << '\n';
        pq1.pop(); pq2.pop(); pq3.pop();
    }

    return 0;
}