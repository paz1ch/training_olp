#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

struct transaction{
    int date; // ngay
    string type; // loai giao dich: thu/chi
    long long amount; // so tien
    string des; // mo ta
    string code; // ma giao dich
};

void addTransaction(vector<transaction> listOfTransaction){
    transaction a;
    int n; cout << "nhap so luong giao dich can them: "; cin >> n;
    for(int i=1;i<=n;i++){
        cout << "nhap thong tin giao dich thu " << i << ": " << endl;
        cout << "Ngay: "; cin >> a.date;
        cout << endl;
        cout << "Loai giao dich(thu/chi): ";
        cin >> a.type;
        cout << endl;
        cout << "So tien: "; cin >> a.amount;
        cout << endl;
        cout << "Mo ta: "; cin >> a.des;
        cout << endl;
        a.code = i;
    }
    listOfTransaction.push_back(a);
}            

void deleteTransaction(vector<transaction> listOfTransaction){
    string ma; // ma giao dich can xoa
    cout << "nhap ma giao dich can xoa: "; cin >> ma;
    bool flag = 0;
    for(int i=0;i<(int)listOfTransaction.size();i++){
        if(listOfTransaction[i].code == ma){
            flag = 1;
            listOfTransaction.erase(listOfTransaction.begin()+i-1);
        }
    }
    if(!flag) cout << "khong tim thay giao dich!" << endl;
    else cout << "giao dich da duoc xoa" << endl;
}

bool comp(transaction a, transaction b){
    return a.date < b.date;
}

void showTransactions(vector<transaction> listOfTransaction){
    sort(listOfTransaction.begin(),listOfTransaction.end(),comp);
    cout << "danh sach giao dich: " << endl;
    for(int i=0;i<(int)listOfTransaction.size();i++){
        cout << "Giao dich thu " << i << ": " << endl; 
        cout << "Ngay: "; cout << listOfTransaction[i].date << endl;
        cout << "Loai giao dich(thu/chi): "; cout << listOfTransaction[i].type << endl;
        cout << "So tien: "; cout << listOfTransaction[i].amount << endl;
        cout << "Mo ta: "; cout << listOfTransaction[i].des << endl;
        cout << "Ma giao dich: "; cout << listOfTransaction[i].code << endl;
        cout << endl;
    }
}


void caculate(vector<transaction> listOfTransaction){
    int start, end;
    cout << "Nhap khoang thoi gian can tinh tong thu/chi. Tu ngay: "; cin >> start;
    cout << " den ngay: "; cin >> end;
    sort(listOfTransaction.begin(),listOfTransaction.end(),comp);
    long long tongThu = 0, tongChi = 0;
    for(int i=0;i<(int)listOfTransaction.size();i++){
        if(listOfTransaction[i].date >= start && listOfTransaction[i].date <= end){
            if(listOfTransaction[i].type == "thu") tongThu += listOfTransaction[i].amount;
            else if(listOfTransaction[i].type == "chi") tongChi += listOfTransaction[i].amount;
        }
    }
    cout << "Tong Thu: " << tongThu << endl << "tongChi: " << tongChi << endl;
}

void showBalance(vector<transaction> listOfTransaction){
    long long balance = 0;
    for(int i=0;i<(int)listOfTransaction.size();i++){
        if(listOfTransaction[i].type == "thu") balance += listOfTransaction[i].amount;
        else if(listOfTransaction[i].type == "chi") balance -= listOfTransaction[i].amount;
    }
    cout << "So du tai khoan: " << balance << endl;
}

signed main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    vector<transaction> listOfTransaction;
    while(true){
        int t; 
        cout << "Nhap lua chon: " << endl;
        cout << "1.Them giao dich" << endl;
        cout << "2.Xoa giao dich" << endl;
        cout << "3.Hien thi danh sach giao dich" << endl;
        cout << "4.Tinh toan tong thu/tong chi" << endl;
        cout << "5.Hien thi so du hien tai dua tren tong thu/tong chi" << endl;
        cin >> t;
        switch(t){
            case 1:
                addTransaction(listOfTransaction);
                break;
            case 2:
                deleteTransaction(listOfTransaction);
                break;
            case 3: 
                showTransactions(listOfTransaction);
                break;
            case 4:
                caculate(listOfTransaction);
                break;
            case 5:
                showBalance(listOfTransaction);
                break;
            default:
                cout << "khong co lua chon. Moi chon lai!" << endl;
                break;
        }
        int temp;
        cout << "ban co muon nhap lai khong? (1 - co/2 - khong): "; cin >> temp;
        if(temp == 2) break;
    }
}