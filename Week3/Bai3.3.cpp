// Bài 3.3. Một người xuất phát tại thành phố 1, muốn đi thăm tất cả các thành phố khác, mỗi thành phố đúng 1 lần và quay về 1. Chi phí để đi từ thành phố i sang thành phố j là cij. Hãy tìm tổng chi phí nhỏ nhất có thể
//Dữ liệu vào:
//Dòng 1: Chứa số nguyên n (1 ≤ n ≤ 16)
//n dòng tiếp theo: Chứa ma trận c ( 0 ≤ cij ≤ 10000000)
//Kết quả: Ghi tổng chi phí nhỏ nhất có thể

// Sok Sokong 20211005
#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int n, c[MAX][MAX];
int cmin = INT_MAX;
int best = INT_MAX;
int curr;
int mark[MAX];
int x[MAX];
void input(){
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            cin >> c[i][j];
            if (c[i][j] > 0) cmin = min(cmin, c[i][j]);
        }
    for (int i = 0; i < MAX ; i++)
        mark[i] = 0;
    curr = 0;
}
bool check(int k, int i){
    if(mark[i] == 1) return false;
    return true;
}
void sol(){
    best = min(best,curr);
}
void TRY(int k){
    for(int i = 2; i <= n; i++){
        if(check(k,i)){
            mark[i] = 1;
            curr += c[x[k-1]][i];

            x[k] = i;

            if(k == n){
                curr += c[x[n]][1];
                sol();
                curr -= c[x[n]][1];
            }
            else TRY(k+1);

            mark[i] = 0;
            curr -= c[x[k-1]][i];

        }
    }
}

int main() {
    input();
    x[1] = 1;
    TRY(2);
    cout << best;
    return 0;
}