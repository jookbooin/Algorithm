/**
 * M = 2^30-1
 * <map1>
 * A = "Messi"
 * B = "Gimossi"
 * 
 * map2 
 * A = 5
 * B = 7;
 * 
 * A
 * B
 * B A
 * B A B
 * B A B B A
 * B A B B A B A B
 * B A B B A B A B B A B B A
 * 
 * 1 1 
 * 
 * 1 1 3 5
 * 
 * 제한이 없어.. << 2^30까지 무한 루프..?
 * 2^30 == 
 * 
 * prev = 5
 * cur = 5 + 7 + 1
 * - (prev = cur / cur = next )
 * - next = cur + prev + 1
 * 
 * --> 이걸로 총 몇번을 해야하는 지 알아냄
 * 현재 단계
 * 
 * while
 *      - prev
 *      - cur 
 *      - next 
 * 
 *      if(cur <= n && n <= next)
 *          break;
 * 
 *      cnt ++; 
 * cnt 알아냄
 * 
 * 
 */
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll a,b,c,n;
vector<int> v;
string ret_str = "Messi Gimossi";

int go(int size, int mm){

    if(mm <= v[1]){
        return mm;
    }else if(v[size - 1] + 1 == mm){ // 공백 
        return 0;
    }else if (mm <= v[size - 1]){
        return go(size - 1, mm);
    }else{
       return go(size - 2, mm - (v[size-1] + 1));
    }
}

int main(){

    cin >> n;
    
    a = 5;
    b = 13;
    v.push_back(a);
    v.push_back(b);

    while(c < n){

        c = a + 1 + b;

        a = b;
        b = c;
        v.push_back(c);

    }

    // f0 f1 f2 f3 f4 f5
    int size = v.size();
    int ret = go(size - 1, n);

    if(ret == 0 || ret == 6){
        cout << "Messi Messi Gimossi" << endl;
    }else{

        cout << ret_str[ret-1] << endl;
    }
    return 0;
}