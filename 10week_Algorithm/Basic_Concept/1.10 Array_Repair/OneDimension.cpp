#include<bits/stdc++.h>
using namespace std;
int a[3] = {1, 2, 3};

void go(int a[]){
    a[2] = 100;
}

void go2(int a[3]){
    a[2] = 1000;
}

void go3(int * a){
    a[2] = 10000;
}

int main(){
    go(a); cout << a[2] << '\n';
    go2(a); cout << a[2] << '\n';
    go3(a); cout << a[2] << '\n';
    
}