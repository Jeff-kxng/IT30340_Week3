// Bài 3.2. Trên bàn cờ vua kích thước n*n có một quân mã đang ở ô (1, 1). Hãy đưa ra một dãy các di chuyển của mã sao cho mỗi ô trên bàn cờ đều được đi qua đúng 1 lần (ô (1, 1) được xem là đã đi qua).

// Sok Sokong 20211005

#include <iostream>
using namespace std;
int n;
int X[100], Y[100];
int mark[100][100];
const int hx[] = {1, 1, 2, 2, -1, -1, -2, -2};
const int hy[] = {2, -2, 1, -1, 2, -2, 1, -1};

void print_sol(){
    for (int j = 1; j <= n * n; ++j)
        printf("(%d %d)\n", X[j], Y[j]);
    exit(0);}
bool check(int xx, int yy){
    if(mark[xx][yy] == 1) return false;
    if(xx < 1 || xx > n || yy < 1 || yy > n) return false;
    return true;}
void TRY(int k){
    for(int i = 0; i < 8; i++){
        int xx = X[k-1] + hx[i];
        int yy = Y[k-1] + hy[i];
        if(check(xx,yy)){
            mark[xx][yy] = 1;
            X[k] = xx;
            Y[k] = yy;
            if(k == n*n)
                print_sol();
            else TRY(k+1);
            mark[xx][yy] = 0;}
    }
}
int main(){
    cin >> n;
    mark[1][1] = 1;
    X[1] = Y[1] = 1;
    TRY(2);
    return 0;
}
