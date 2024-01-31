#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll max_n = 1e9;  // �ִ� �Է� ����

int N;
ll C;
int arr[1001];
map<int,pair<int,int>> mp;  // <�� , < ó������ idx , value> > 

bool comp(pair<int, pair<int,int>> &a, pair<int, pair<int,int>> &b){

    if(a.second.second == b.second.second){
        return a.second.first < b.second.first;  // �ε��� ���� ���� ������ 
    }

    return a.second.second > b.second.second; // Ƚ�� ���� ���� ������
}

int main(void) {
    cin >> N >> C;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];

        if(mp[arr[i]].second == 0 ){
            mp[arr[i]] = make_pair(i,1);
        }else{
            mp[arr[i]].second +=1;
        }
    }

    vector<pair<int, pair<int,int>>> vmp(mp.begin(),mp.end());
    sort(vmp.begin(),vmp.end(),comp);

    for(auto result : vmp){
        for(int i = 0 ; i< result.second.second ; i ++){
            cout << result.first << " ";
        }
    }


    return 0;
}

