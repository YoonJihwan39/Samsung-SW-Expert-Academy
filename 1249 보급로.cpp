#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

char map[100][100];
int min_time[100][100];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int N;

int bfs(){
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(0, 0), 0));
    int result = 987654321;

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int time = q.front().second;

        q.pop();

        if(x == N-1 && y == N-1){ //목적지에 도착한 경우
            if(time < result){
                result = time;
            }
            continue;
        }

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= N){ //map 범위를 벗어나면
                continue;
            }
            if(nx == 0 && ny == 0){ //출발지점으로는 못 돌아감
                continue;
            }
            int estimated_time = time + (map[ny][nx] - '0'); //해당 방향으로 진행할 경우 예측되는 시간
            if(estimated_time < min_time[ny][nx]) { //예측된 시간이 해당 지역에 도착한 최소 시간보다 작은 경우에만 push
                min_time[ny][nx] = estimated_time;
                q.push(make_pair(make_pair(nx, ny), estimated_time));
            }
        }
    }

    return result;

}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        
        cin >> N;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                min_time[i][j] = 987654321;
            }
        }
        for(int i = 0; i < N; i++){
            cin >> map[i];
        }
        int result = bfs();
        cout << '#' << test_case << ' ' << result << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}