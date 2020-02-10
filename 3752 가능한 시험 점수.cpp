#include<iostream>
#include <cstring>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N;

        cin >> N;

        int sum = 0;
        int array [N];

        for(int i = 0; i < N; i++){
            cin >> array[i];
            sum += array[i];
        }
        bool score[sum+1];
        memset(score, 0, sizeof(score));
        score[0] = 1;
        int count = 1;
        for(int i = 0; i < N; i++){
            for(int j = sum; j >= 0; j--){
                if(score[j] == 1 && score[j + array[i]] == 0){
                    score[j + array[i]] = 1;
                    count++;
                }
            }
        }

        cout << '#' << test_case << ' ' << count << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}