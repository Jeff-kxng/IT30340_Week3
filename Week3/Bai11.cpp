#include<bits/stdc++.h>
using namespace std;
const int MAX = 10000;
int n, r;
int price[MAX][MAX]; //ma tran gia tri canh
int x[MAX];//day luu tru duong di
bool visited[MAX];//mang kiem tra diem da den
vector<int> vt;//vector luu tru cac diem can di qua
int min_price;//tong trong so nho nhat
int sum_price;//tong trong so tam thoi
int start, destination, numberOfPoint;//diem xuat phat, diem dich, so luong diem can di qua

void input(){
    cin >> n >> r;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            cin >> price[i][j];
        }
}
//kiem tra xem viec chon mot dinh moi co hop le hay khong
bool check(int a, int i){
    if(visited[vt[i]]) return false;
    if(price[x[a-1]][vt[i]] == 0) return false;
    return true;
}
//kiem tra neu duong di hien tai hop le thi cap nhat gia tri min moi
void solution(){
    if(price[x[numberOfPoint-2]][destination] == 0) return;
    min_price = min(min_price, sum_price + price[x[numberOfPoint-2]][destination]);
}
//de quy thu tat ca cac canh chon tu dinh tu danh sach vt
void TRY(int a){
    for(int i=1; i<numberOfPoint-1; i++){
        if(check(a, i)){
            visited[vt[i]] = true;
            sum_price += price[x[a-1]][vt[i]];

            x[a] = vt[i];
            if(a == numberOfPoint-2) solution();
            else TRY(a+1);

            visited[vt[i]] = false;
            sum_price -= price[x[a-1]][vt[i]];
        }
    }
}

int main(){
    string str;
    input(); getline(cin,str);

    while(r > 0){
        min_price = INT_MAX;
        sum_price = 0;

        getline(cin, str);

        while (!str.empty()){
            stringstream convert(str.substr(0, str.find(" ")));
            int tmp = 0;
            convert >> tmp;
            vt.push_back(tmp - 1);

            if (str.find(" ") > str.size()){
                break;
            } else {
                str.erase(0, str.find(" ") + 1); // Update string
            }
        }

        // Bat dau khoi tao cac du lieu can thiet truoc khi quay lui
        start = vt[0]; // diem bat dau dau
        destination = vt[vt.size()-1]; // diem dich
        numberOfPoint = vt.size(); // so diem phai di qua
        x[0] = start; x[numberOfPoint-1] = destination;
        for(int i=0; i<n; i++)
            visited[i] = false;

        TRY(1);

        // In ra ket qua
        if(min_price == INT_MAX) cout << "0" << endl;
        else cout << min_price << endl;

        // Xoa vector va chuyen sang khach tiep theo
        vt.erase(vt.begin(), vt.end());
        r--;
    }
}
// Sok Sokong 20211005
