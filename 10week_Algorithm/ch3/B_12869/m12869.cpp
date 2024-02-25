/**
 * 9 3 1
 * ��Ż����ũ�� ������ �� ��, �� ���� �� ���� SCV�� ����
 * ��� scb �ı��ϱ����� �����ؾ��ϴ� �ּڰ�
 */

/**
 * 9 1 3
 * 3 9 1
 */

#include <bits/stdc++.h>

using namespace std;

int N, cnt = 1e9;
int val[3], hp[64][64][64];
int a, b, c;

// vector<tuple<int,int,int>> ���� �ٷ�� ���ٰ� �Ѵ�
int graph[6][3] = {{9, 1, 3},
                   {9, 3, 1},
                   {1, 9, 3},
                   {3, 9, 1},
                   {1, 3, 9},
                   {3, 1, 9}};

struct HP {  // 3���� �ٷ궧 ������ �ٷ�� ���ؼ�
    int o, s, t;
};

// 0 0 0 �� ���� �ּ� ��
void back(int one, int second, int third) {

    hp[one][second][third] = 1;     // ó�� 
    queue<HP> q;
    q.push({one, second, third});

    while (q.size()) {
        int co = q.front().o;
        int cs = q.front().s;
        int ct = q.front().t;
        q.pop();

        if (hp[0][0][0]) break;    // ���� ����

        for (int i = 0; i < 6; i++) {
            int no = max(0, co - graph[i][0]);
            int ns = max(0, cs - graph[i][1]);
            int nt = max(0, ct - graph[i][2]);

            if (hp[no][ns][nt]) continue;  // �ش� ���� �������� �ִٸ� pass

            hp[no][ns][nt] = hp[co][cs][ct] + 1;
            q.push({no, ns, nt});
        }
    }
}

int main(void) {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> val[i];
    }

    back(val[0], val[1], val[2]);

    cout << hp[0][0][0] - 1 << endl;

    return 0;
}
