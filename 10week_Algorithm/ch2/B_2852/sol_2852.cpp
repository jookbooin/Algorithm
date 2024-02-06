#include <bits/stdc++.h>
using namespace std;

#define prev kundol

int N, team, fs, ss, fsum, ssum;
string ti, prev;

string print(int a){
    string d = "00" + to_string(a/60);
    string e = "00" + to_string(a % 60);
    return d.substr(d.size()-2,2)+":"+ e.substr(e.size()-2,2);
}

int chageToInt(string ti){
    return atoi(ti.substr(0,2).c_str()) * 60 + atoi(ti.substr(3,2).c_str());
}

void cal(int &sum, string s) {
    sum += (chageToInt(s) - chageToInt(prev));
}

int main(void) {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> team >> ti;
        if (fs > ss) {
            cal(fsum, ti);
        } else if (ss > fs) {
            cal(ssum, ti);
        }

        team == 1 ? fs++ : ss++;
        prev = ti;
    }

    if(fs > ss)
        cal(fsum, "48:00");
    else if(ss > fs)
        cal(ssum, "48:00");

    cout << print(fsum)<< '\n';
    cout << print(ssum)<< '\n';

    return 0;
}