#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int weight[1000];

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    
	int test_case;
	int T;
    int N, M;
    int max_weight, current_weight;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        memset(weight, 0, sizeof(weight));
        max_weight = -1;

        cin >> N >> M;
        for(int i = 0; i < N; i++){
            cin >> weight[i];
        }

        sort(weight, weight+N); //오름차순 정렬

        for(int i = 0; i < N-1; i++){ //1개를 이미 선택한 상태에서 다른 과자를 선택
            current_weight = weight[i] + weight[i+1]; //현재 과자 i와 그 다음으로 무거운 과자를 들었을 때
            if(current_weight > M){
                break;
            }
            current_weight = weight[i] + weight[N-1]; //현재 과자 i와 제일 무거운 과자를 들었을 때
            if(current_weight <= M){ 
                if(current_weight > max_weight){
                    max_weight = current_weight;
                }
                continue;
            }  
            // 이진탐색
            int start = i+1;
            int end = N;
            int mid; 
            
            while(start <= end){
                mid = (start + end) / 2;
                current_weight = weight[i] + weight[mid];
                if(current_weight <= M){
                    if(current_weight > max_weight){
                        max_weight = current_weight;
                    }
                    start = mid + 1;
                }
                else{
                    end = mid - 1;
                } 
            }

            if(max_weight == M){
                break;
            }
        }

        cout << '#' << test_case << ' ' << max_weight << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}