#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<pair<int, int>> HW; // first에는 마감시간, second에는 걸리는 시간

bool available (int mid) {
    int time = mid;
    for(int i = 0; i < N; i++){
        time = time + HW[i].second;
        if(time > HW[i].first){ //제한시간을 초과한다면
            return false;
        }    
    }
    return true;
}


int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);

	int test_case;
	int T;
    int time, deadline;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int result = 0;
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> time >> deadline;
            HW.push_back(make_pair(deadline, time));
        }
        sort(HW.begin(), HW.end()); //마감시간 오름차순 정렬

        //이진 탐색으로 만족하는 X를 찾음.
        int start = 0;
        int end = HW[N-1].first - HW[N-1].second;
        int mid = (start + end)/2;

        while(start <= end){
            if(available(mid)){
                if(mid > result){
                    result = mid;
                }
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
            mid = (start + end)/2;
        }
        cout << '#' << test_case << ' ' << result << '\n';
        HW.clear();
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}