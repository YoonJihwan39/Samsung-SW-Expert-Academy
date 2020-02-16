#include <iostream>
#include <set>
using namespace std;

int mod(int a, int b){
    int result = a % b;
    if(result < 0){
        result += b;
    }
    return result;
}
int main(void)
{
	int test_case;
	int T, N, K;

	cin >> T;
    set<int> s;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> K;
        char array[N];
        cin >> array;
        int len = N / 4;
        for(int i = 0; i < len; i++){
            for(int j = 0; j < N; j+=len){
                string temp = "";
                for(int k = 0; k < len; k++){
                    temp = temp + array[mod(j+k-i, N)];
                }
                s.insert(stoul(temp, nullptr, 16));
            }
        }
        set<int>::iterator it = s.begin();
        std::advance(it, s.size() - K);
        cout << '#' << test_case << ' ' << *it << '\n';
        s.clear();
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}