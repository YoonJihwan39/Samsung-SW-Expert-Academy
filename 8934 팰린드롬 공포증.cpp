#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
    string str;
    bool result;
    int count[3];
    int kinds;
    int length, half_length;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> str;
        count[0] = count[1] = count[2] = 0;
        kinds = 0;
        length = str.size();
        half_length = length / 2;
        if(length == 1){
            result = true;
        }
        else {
            for(int i = 0; i < length; i++){
                if(str[i] == 'a'){
                    count[0]++;
                }
                else if(str[i] == 'b'){
                    count[1]++;
                }
                else {
                    count[2]++;
                }
            }

            for(int i = 0; i < 3; i++){
                if(count[i] != 0){
                    kinds++;
                }
            }
            if(kinds == 1){
                result = false;
            }
            else {
                sort(count, count+3);
                if(count[2] - count[0] < 2){
                    result = true;
                }
                else{
                    result = false;
                }
            }

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