#include<bits/stdc++.h>

using namespace std;

int n;
double input;
priority_queue<double,vector<double>, greater<double>> pq; // pq 내림차순 방법

int main(){

    cin >> n;
    for(int i = 0; i< n; i++){
        cin >> input;
        pq.push(input);
    }

    for(int i = 0; i<7 ; i++){
        printf("%.3f\n",pq.top());
        pq.pop();
    }

    return 0;
}