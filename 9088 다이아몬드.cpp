#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

vector<int> v;
queue<int> gift;
int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int test_case;
	int T;
    int N, K;
    int input;
    int max_num, num;
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
        max_num = 0;
        num = 0;
        cin >> N >> K;
        for(int i = 0; i < N; i++){
            cin >> input;
            v.push_back(input);
        }

        sort(v.begin(), v.end()); // 크기 오름차순 정렬, queue에도 오름차순으로 넣어짐.

        for(int i = 0; i < N; i++){
            gift.push(v[i]);
            num++;
            if(gift.empty() || v[i] - gift.front() <= K){ 
                //gift가 비어있거나 맨 앞 원소와 차이가 K보다 작거나 같으면 skip
                if(num > max_num){
                    max_num = num;
                }
                continue;
            }
            else{
                while(v[i] - gift.front() > K){ //맨 앞과 차이가 K보다 클때까지 맨 앞을 pop
                    gift.pop();
                    num--;
                }
            }   
        }
        cout << '#' << test_case << ' ' << max_num << '\n';

        v.clear();
        while( !gift.empty() ) gift.pop(); //queue clear
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}