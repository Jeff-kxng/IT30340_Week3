// Bài tập 9: Lập lịch cho y tá
//Một y tá cần lập lịch làm việc trong  N ngày, mỗi ngày chỉ có thể là làm việc hay nghỉ ngơi. Một lịch làm việc là tốt nếu không có hai ngày nghỉ nào liên tiếp và mọi chuỗi ngày tối đại làm việc liên tiếp đều có số ngày thuộc đoạn  [K1,K2]. Hãy liệt kê tất cả các cách lập lịch tốt, với mỗi lịch in ra trên một dòng một xâu nhị phân độ dài  n với bit 0/1 tương ứng là nghỉ/làm việc. Các xâu phải được in ra theo thứ tự từ điển
#include<bits/stdc++.h>
using namespace std;
const int  MAX = 200;
int n, k1, k2;
int x[MAX];
int cnt = 0;
int so0 = 0, so1 = 0;

void inputData(){
    cin >> n >> k1 >> k2;
}

bool check(int  a, int  i){
    if(a==1) return true;
    else {
        // neu ngay nay nghi -> kiem tra ngay truoc do, neu da nghi thi khong duoc nghi nua
        if(i==0){
            if(x[a-1] == 0) return false;
            else { // x[a-1] == 1
                if(so1<k1) return false;
            }
        } else { // i == 1
            if(x[a-1] == 0){
                if(n-a+1 < k1) return false;
            } else {
                if(so1>=k2) return false;
            }
        }

        return true;
    }
}

void solution(){
    for(int i=1; i<=n; i++)
        cout << x[i];
    cout << endl;
    cnt++;
}

void TRY(int  a){
    for(int  i=0; i<=1; i++){
        if(check(a,i)){
            x[a] = i; // ngay thu a lam viec hoac khong lam viec
            int pre = so1;
            if(i == 1){
                if(x[a-1] == 1) so1++;
                else so1 = 1;
            } else {
                so1 = 0;
            }
            //de quy
            if(a==n) solution();
            else TRY(a+1);

            so1 = pre;
        }
    }
}

int main(){
    inputData();
    TRY(1);
    return 0;
}
// Sok Sokong 20211005