#include<bits/stdc++.h>
using namespace std; 
int n, k, a[14][14], y, x, dir;
struct Point{
    int y, x, dir;
}; 
vector<int> v[14][14];
vector<Point> status;

const int dy[] = {0, 0, -1, 1};
const int dx[] = {1, -1, 0, 0};

bool check_blue(int ny, int nx){
    return ny < 0 || ny >= n || nx < 0 || nx >= n || a[ny][nx] == 2;
}

void move(int y, int x, int dir, int i){
    int ny = y + dy[dir];
    int nx = x + dx[dir];

    if(check_blue(ny,nx)){
        
        // 반대 방향 
        status[i].dir ^= 1;

        ny = y + dy[status[i].dir];
        nx = x + dx[status[i].dir];

        // 움직이지 않음
        if(check_blue(ny,nx)) return;
    }

    // 현재 위치
    vector<int>& cur_v = v[y][x];

    // 다음 위치ㄹ
    vector<int>& next_v = v[ny][nx];

    // 쌓여있는 위치 확인
    auto pos = find(cur_v.begin(), cur_v.end(), i);

    // 빨강
    if(a[ny][nx] == 1) reverse(pos, cur_v.end());

    for(auto it = pos; it != cur_v.end(); it++){
        // 1. 값 추가
        next_v.push_back(*it); 
        status[*it].y = ny;
        status[*it].x = nx;
    }

    // 2. 값 삭제
    cur_v.erase(pos,cur_v.end());
    return;
}

bool isOver(){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(v[i][j].size() >= 4){
                return 1;
            }
        }
    }
    return 0;
}

bool simul(){
    for(int i = 0; i < status.size(); i++){ 
        int y = status[i].y;
        int x = status[i].x;
        int dir = status[i].dir;

        // 움직임
        move(y, x, dir, i);

        // 말 4개 있는 순간
        if(isOver()) return 1;
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < k; i++){
        cin >> y >> x >> dir;
         y--; x--; dir--;

        // 1. 말 순서
        status.push_back({y, x, dir});

        // 2. 말 위치
        v[y][x].push_back(i);
    }

    int cnt = 0;
    bool flag = 0;

    while(cnt <= 1000){
        cnt++;
        if(simul()){
            flag = 1;
            break;
        }
    }

    if(flag) cout << cnt << '\n';
    else cout << -1 << '\n';


    return 0;
}