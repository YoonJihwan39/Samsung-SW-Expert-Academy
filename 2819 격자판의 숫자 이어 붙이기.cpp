#include<iostream>
#include<set>
using namespace std;

set<int> s;
int map[4][4];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y, int life, int sum){
    sum = 10 * sum + map[y][x];
    if(life == 0){
        s.insert(sum);
        return;
    }

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= 4 || ny >= 4){
            continue;
        }
        dfs(nx, ny, life-1, sum);
    }


}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                cin >> map[i][j];
            }
        }

        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                dfs(j, i, 6, 0);
            }
        }
        cout << '#' << test_case << ' ' << s.size() << '\n';
        s.clear();
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}