#include <bits/stdc++.h>

#define prev hihi

using namespace std;

int N, t, wt = 0, fsc = 0, ssc = 0, fsum = 0, ssum = 0, prev = 0;
string ti;

int main(void) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> t >> ti;

        int min = atoi(ti.substr(0, 2).c_str());
        int sec = atoi(ti.substr(3, 2).c_str());

        if (fsc > ssc) {
            fsum += (min * 60) + sec - prev;
        } else if (fsc < ssc) {
            ssum += (min * 60) + sec - prev;
        }

        if (t == 1)
            fsc++;
        else if (t == 2)
            ssc++;

        prev = (min * 60) + sec;
    }

    // Add the time from the last score change to the end of the game
    if (fsc > ssc) {
        fsum += (48 * 60) - prev;
    } else if (fsc < ssc) {
        ssum += (48 * 60) - prev;
    }

    printf("%02d:%02d\n", fsum / 60, fsum % 60);
    printf("%02d:%02d\n", ssum / 60, ssum % 60);

    return 0;
}