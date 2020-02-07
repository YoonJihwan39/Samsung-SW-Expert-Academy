#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

bool desc(int a, int b){
    return a > b;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n, m;

        cin >> n >> m;

        int price[n+1]; //각 주차장 별 가격
        vector<int> available; // 빈 주차장(내림차순)
        queue<int> waiting;
        int weight[m+1]; //차 무게
        int parked[m+1]; //차를 주차한 곳
        int result = 0;
        

        for(int i = 1; i <= n; i++){
            cin >> price[i];
            available.push_back(i);
        }

        for(int i = 1; i <= m; i++){
            cin >> weight[i];
            parked[i] = 0;

        }

        sort(available.begin(), available.end(), desc);

        for(int i = 0; i < 2 * m; i++){
            int input;
            cin >> input;
            if(input > 0 && !available.empty()){ //빈 주차장이 있을 때
                int place = available.back(); //가장 낮은 주차장
                available.pop_back();
                result += price[place] * weight[input]; //요금 계산
                parked[input] = place;
            }
            else if(input > 0 && available.empty()){ // 빈 주차장이 없을 때
                waiting.push(input);
            }
            else if(input < 0){
                input *= -1;
                int place = parked[input];
                if(waiting.empty()){ //기다리는 차가 없다면
                    available.push_back(place);
                    sort(available.begin(), available.end(), desc);
                }
                else { //기다리는 차가 있다면
                    int firstCar = waiting.front(); // 기다리는 차 중 첫번째
                    waiting.pop();
                    result += price[place] * weight[firstCar];
                    parked[firstCar] = place;
                }
                
            }
        }
        cout << '#' << test_case << ' ' << result << '\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}