/**
 * 0 : �� ĭ
 * 1 : ��
 * 2 : ġŲ ��
 *
 * N = 50, M = 13
 * �� ���� 2N �� ����
 *
 * ġŲ �Ÿ� : ���� ����� ġŲ�� ������ �Ÿ�
 * ���� ġŲ �Ÿ� : ��� ���� ġŲ �Ÿ��� ��
 *
 * ������ ġŲ�� M�� ��
 * ������ ġŲ �Ÿ��� �󸶳� �۰� �ɱ�
 *
 */

/**
 * ��(1)
 * ġ(2) ���� ����
 *
 */

#include <bits/stdc++.h>

using namespace std;

int N, M, mi = 1e9, rc, cc, rh, ch, inmi, sm;
int rt, ct;
int graph[51][51];

vector<pair<int, int>> chic;  // () () () ()
vector<pair<int, int>> home;

// ������ �Ÿ�
void cal(vector<int> b) {
    sm = 0;
    for (int j = 0; j < home.size(); j++) {
        inmi = 1e9;
        for (int i = 0; i < b.size(); i++) {
            tie(rc, cc) = chic[b[i]];  // 0 , 1 , 2
            tie(rh, ch) = home[j];
            inmi = min(inmi, abs(rc - rh) + abs(cc - ch));
        }
        sm += inmi;
    }
    mi = min(mi, sm);
}

void combi(int idx, vector<int> b) {
    if (b.size() == M) {
        cout << "( ";
        for (int i : b) {
            cout << i << " ";
        }
        cout << " )" << endl;
        cal(b);
        return;
    }

    for (int i = idx + 1; i < chic.size(); i++) {  // () () ()
        b.push_back(i);
        combi(i, b);
        b.pop_back();
    }
}

int main(void) {
    cin >> N >> M;

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cin >> graph[row][col];
            if (graph[row][col] == 2)
                chic.push_back({row, col});
            else if (graph[row][col] == 1)
                home.push_back({row, col});
        }
    }

    vector<int> v;      // combi �����ҋ�
    combi(-1, v);

    cout << mi << endl;

    return 0;
}