#include<iostream>
#include <cstring>
using namespace std;

int height[1000];

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int test_case;
	int T;
	int width;
    int highest;
    int result;
	T = 10;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        result = 0;
        memset(height, 0, sizeof(height));
        cin >> width;
        for(int i = 0; i < width; i++){
            cin >> height[i];
        }

        //왼쪽에서 2칸, 오른쪽에서 2칸 중에서 가장 높은 건물의 높이를 현재 건물의 높이와 빼면 됨.
        for(int i = 2; i < width - 2; i++){
            highest = 0;
            for(int j = i - 2; j <= i + 2; j++){
                if(j == i){ //자기 건물은 제외
                    continue;
                }
                if(height[j] > highest){
                    highest = height[j];
                }
            }
            if(height[i] > highest){
                result = result + height[i] - highest;
            }
        }
        cout << '#' << test_case << ' ' << result << '\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}