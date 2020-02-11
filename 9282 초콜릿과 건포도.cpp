#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int chocolate[51][51];
int cumulative_sum[51][51];
int cache[51][51][51][51];

int divide(int x, int y, int height, int width){
    if(height == 1 && width == 1){ //더이상 나눠질 수 없으면 재귀 종료
        return 0;
    }
    if(cache[y][x][height][width] != -1){ //memorization
        return cache[y][x][height][width];
    }

    int result = 99999999;
    
    // 현재 큰 초콜릿에 있는 건포도 수 (누적합)
    int sum;
    int dx = x+width-1;
    int dy = y+height-1;
    if(x == 0 && y == 0){
        sum = cumulative_sum[dy][dx];
    }
    else if(x == 0){
        sum = cumulative_sum[dy][dx] - cumulative_sum[y-1][dx];
    }
    else if(y == 0){
        sum = cumulative_sum[dy][dx] - cumulative_sum[dy][x-1];
    }
    else{
        sum = cumulative_sum[dy][dx] - cumulative_sum[dy][x-1] - cumulative_sum[y-1][dx] + cumulative_sum[y-1][x-1];
    }

    //가로로 나누는 경우
    for(int i = 1; i < width; i++){
        result = min(result, sum + divide(x, y, height, i) + divide(x+i, y, height, width - i));
    }
    //세로로 나누는 경우
    for(int i = 1; i < height; i++){
        result = min(result, sum + divide(x, y, i, width) + divide(x, y+i, height - i, width));
    }

    return cache[y][x][height][width] = result;

}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
 
	int test_case;
	int T;
    int n, m;
    int result, sum;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        memset(cumulative_sum, 0, sizeof(cumulative_sum));
        memset(cache, -1, sizeof(cache));
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            sum = 0;
            for(int j = 0; j < m; j++){
                cin >> chocolate[i][j];
                sum += chocolate[i][j];
                cumulative_sum[i][j] = sum; 
            }
        }
        for(int i = 0; i < m; i++){
            sum = 0;
            for(int j = 0; j < n; j++){
                sum += cumulative_sum[j][i];
                cumulative_sum[j][i] = sum;
            }
        }
        result = divide(0, 0, n, m);
        cout << '#' << test_case << ' ' << result << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}