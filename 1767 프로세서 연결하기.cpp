#include<iostream>
 
using namespace std;
int maxcore;
int dfs(int realcell[][12], int size){
    int cell[12][12];
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            cell[i][j] = realcell[i][j];
        }
    }
    int cnt[5] = {0, 0, 0, 0, 0};
    int count = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(cell[i][j] == 1 && (i * j == 0 || i == size-1 || j == size-1)){
                cell[i][j] = 2;
                count += 1000;
            }
            else if(cell[i][j] == 1){
                bool checkN = 1, checkS = 1, checkW = 1, checkE = 1;
                cell[i][j] = -1;
                //core 남쪽 확인
                int k = i+1;
                while(k < size){
                    if(cell[k][j] != 0) {
                        checkS = 0;
                        break;
                    }
                    k++;
                }
                if(checkS){
                    int anothercell[12][12];
                    for(int a = 0; a < 12; a++){
                        for(int b = 0; b < 12; b++){
                            anothercell[a][b] = cell[a][b];
                        }
                    }
                    anothercell[i][j] = 2;
                    for(int a = i+1; a < size; a++){
                        anothercell[a][j] = 3;
                    }
                    cnt[0] = dfs(anothercell, size);
                }
                 
                //core 북쪽 확인
                k = i-1;
                while(k >= 0){
                    if(cell[k][j] != 0) {
                        checkN = 0;
                        break;
                    }
                    k--;
                }
                if(checkN){
                    int anothercell[12][12];
                    for(int a = 0; a < 12; a++){
                        for(int b = 0; b < 12; b++){
                            anothercell[a][b] = cell[a][b];
                        }
                    }
                    anothercell[i][j] = 2;
                    for(int a = 0; a < i; a++){
                        anothercell[a][j] = 3;
                    }
                    cnt[1] = dfs(anothercell, size);
                }
                 
                //core 동쪽확인
                k = j+1;
                while(k < size){
                    if(cell[i][k] != 0) {
                        checkE = 0;
                        break;
                    }
                    k++;
                }
                if(checkE){
                    int anothercell[12][12];
                    for(int a = 0; a < 12; a++){
                        for(int b = 0; b < 12; b++){
                            anothercell[a][b] = cell[a][b];
                        }
                    }
                    anothercell[i][j] = 2;
                    for(int a = j+1; a < size; a++){
                        anothercell[i][a] = 3;
                    }
                    cnt[2] = dfs(anothercell, size);
                }
                 
                //core 서쪽 확인
                k = j-1;
                while(k >= 0){
                    if(cell[i][k] != 0) {
                        checkW = 0;
                        break;
                    }
                    k--;
                }
                 
                if(checkW){
                    int anothercell[12][12];
                    for(int a = 0; a < 12; a++){
                        for(int b = 0; b < 12; b++){
                            anothercell[a][b] = cell[a][b];
                        }
                    }
                    anothercell[i][j] = 2;
                    for(int a = 0; a < j; a++){
                        anothercell[i][a] = 3;
                    }
                    cnt[3] = dfs(anothercell, size);
                }

                //연결 안 했을 때 + 이미 maxcore가 나온 경우 안함.
                if(checkN + checkS + checkE + checkW == 0){
                    int anothercell[12][12];
                    for(int a = 0; a < 12; a++){
                        for(int b = 0; b < 12; b++){
                            anothercell[a][b] = cell[a][b];
                        }
                    }
                    cnt[4] = dfs(anothercell, size);
                }
 
                int result = 0;
                for(int k = 0; k < 5; k++){
                    if(result / 1000 < cnt[k] / 1000){
                        result = cnt[k];
                    }
                    else if(result / 1000 == cnt[k] / 1000 && result % 1000 > cnt[k] % 1000){
                        result = cnt[k];
                    }
                }
                return result;
            }
            else if(cell[i][j] == 2){
                count += 1000;
            }
            else if(cell[i][j] == 3){
                count++;
            }
        }
    }
    return count;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
 
    int test_case;
    int T;
 
    cin>>T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for(test_case = 1; test_case <= T; ++test_case)
    {
        maxcore = 0;
        int size;
        int x, y;
        cin >> size;
        int cell[12][12]; // 0은 빈 cell, 1은 아직 연결되지 않은 코어 2는 연결된 코어, 3은 전선을 의미, -1은 연결 안함.
        for(y = 0; y < size; y++){
            for(x = 0; x < size; x++){
                cin >> cell[y][x];
                if(cell[y][x] == 1){
                    maxcore++;
                }
            }
        }
        cout << '#' << test_case << ' ' << dfs(cell, size) % 1000<< '\n';
 
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}