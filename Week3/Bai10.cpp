// Bài tập 10: Khoảng cách Hamming
//Khoảng cách Hamming giữa hai xâu cùng độ dài là số vị trí mà ký tự tại vị trí đó là khác nhau trên hai xâu. Cho  S là xâu gồm  n ký tự 0. Hãy liệt kê tất cả các xâu nhị phân độ dài  n, có khoảng cách Hamming với  S bằng  H.Các xâu phải được liệt kê theo thứ tự từ điển.
#include<bits/stdc++.h>
using namespace std;
const int MAX = 20;
int N, H;
int x[MAX];
int S[MAX]; // Xau mac dinh de so sanh
int cnt = 0;

void input(){
    cin >> N >> H;
    for(int i=0; i<N; i++)
        S[i] = 0;
    for(int i=0; i<N; i++)
        x[i] = 0;
}

// Kiem tra 2 co khoang cach Hamming la bnh
int checkHamming(int str1[], int str2[]){
    int lens = N;
    int cnt = 0;
    for(int i=0; i<lens; i++){
        if(str1[i] != str2[i]) cnt++;
    }
    return cnt;
}

void solution(){
    if(checkHamming(x,S) == H){
        for(int i=0; i<N; i++)
            cout << x[i];
        cout << endl;
    }
}
//ham de quy tat ca cac gia tri co the cua bit tai vi tri a trong day nhi phan
void TRY(int a){
    for(int i=0; i<=1; i++){
        x[a] = i;
        if(a == N-1) solution();
        else
            TRY(a+1);
    }
}

int main(){
    int T;
    cin >> T;
    while(T > 0){
        input();
        TRY(0);
        T--;
    }
}
// Sok Sokong 20211005