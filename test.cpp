#include <iostream>
#include <vector>
#include <algorithm> // 추가된 헤더

using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6};
    vector<int> temp;

    auto it = find(v.begin(), v.end(), 3);
    
    if (it != v.end()) {
        cout << "position: " << distance(v.begin(), it) << endl;
        cout << "차이 : " << v.end() - it << endl;

        int size = v.end() - it;
        for(int i = 0 ; i< size; i++){
            cout << "back : " << v.back() << endl;
            temp.push_back(v.back());
            v.pop_back();
        }

    } else {
        cout << "not found" << endl;
    }

    cout << "v : ";
    for(int a : v){
        cout << a << " ";
    }

    cout << endl;
    cout << "temp : ";

    for(int a : temp){
        cout << a << " ";
    }
    cout << endl;

    return 0;
}
