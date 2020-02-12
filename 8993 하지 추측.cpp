#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
	int test_case;
	int T;
    long long N;
    bool result;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> N;
        result = true;
        while(N > 1){
            if(N % 2){
                result = false;
                break;
            }
            N = N / 2;
        }
        if(result){
            cout << '#' << test_case << ' ' << "YES" << '\n';
        }
        else {
            cout << '#' << test_case << ' ' << "NO" << '\n';
        }
        
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}