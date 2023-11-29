// Bài tập 12: Đếm đường đi
//Cho đồ thị vô hướng  G, hãy đếm số đường đi đi qua  k cạnh và không đi qua đỉnh nào quá một lần.
#include<bits/stdc++.h>
using namespace std;
const int MAX = 100;
int n, k;
int m;//so luong canh
vector<vector<int> > vt; // chuyen tu luu tru cac canh sang luu tru danh sach ke
int x[MAX];//day luu tru duong di
bool visited[MAX];//mang kiem tra da tham
int res;//so luong duong di

void input(){
    cin >> n >> k;
    cin >> m;
    vt.resize(n+1);
    for(int i=0; i<m; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;

        vt[tmp1-1].push_back(tmp2-1); // dinh tmp2 ke voi dinh tmp1
        vt[tmp2-1].push_back(tmp1-1); // dinh tmp1 ke voi dinh tmp2
    }

    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    res = 0;
}
//Ham kiem tra xem viec con dinh i lam dinh tiep theo co hop ly khong
bool check(int a, int i){
    if(a == 0) return true;
    if(visited[i]) return false;

    int index = 0;
    for(int j=0; j<vt[x[a-1]].size(); j++){
        if(i == vt[x[a-1]][j]) index++;
    }
    if(index == 0) return false;


    return true;
}

void solution(){
    res++;
}
//de quy thu tat ca cac cach chon dinh tu 0 den n-1 de tao duong di k
void TRY(int a){
    for(int i=0; i<n; i++){
        if(check(a, i)){
            visited[i] = true;
            x[a] = i;

            if(a == k) solution();
            else TRY(a+1);

            visited[i] = false;
        }
    }
}

int main(){
    input();
    TRY(0);
    cout << res / 2;
}
// Sok Sokong 20211005