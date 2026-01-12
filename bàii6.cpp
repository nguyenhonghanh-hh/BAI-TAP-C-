#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 1. Dinh nghia struct Sinhvien
struct SinhVien {
    string maSV;
    string hoTen;
    string lop;
    float diem;
};

// a. Nhap danh sach sinh vien
void nhapDS(vector<SinhVien> &ds) {
    int n;
    cout << "Nhap so luong sinh vien: "; cin >> n;
    for (int i = 0; i < n; i++) {
        SinhVien sv;
        cout << "--- SV thu " << i + 1 << " ---" << endl;
        cout << "Ma SV: "; cin >> sv.maSV;
        cin.ignore(); // Xoa bo nho dem
        cout << "Ho ten: "; getline(cin, sv.hoTen);
        cout << "Lop: "; cin >> sv.lop;
        cout << "Diem: "; cin >> sv.diem;
        ds.push_back(sv);
    }
}

// b. Hien thi danh sach
void xuatDS(const vector<SinhVien> &ds) {
    cout << "\n--- DANH SACH SINH VIEN ---" << endl;
    for (const auto &sv : ds) {
        cout << sv.maSV << " - " << sv.hoTen << " - " << sv.lop << " - " << sv.diem << endl;
    }
}

// d. Tim sinh vien theo Lop va Diem > 5
void timSVTheoLopVaDiem(const vector<SinhVien> &ds, string lopTim, float diemSan) {
    cout << "\nDanh sach lop " << lopTim << " co diem > " << diemSan << ":" << endl;
    for (const auto &sv : ds) {
        if (sv.lop == lopTim && sv.diem > diemSan) {
            cout << sv.hoTen << " (" << sv.diem << ")" << endl;
        }
    }
}

// k. Sap xep giam dan theo diem
bool soSanhDiem(const SinhVien &a, const SinhVien &b) {
    return a.diem > b.diem;
}

// o. Xoa sinh vien cuoi cung
void xoaCuoi(vector<SinhVien> &ds) {
    if (!ds.empty()) {
        ds.pop_back();
        cout << "\nDa xoa sinh vien cuoi cung." << endl;
    }
}

int main() {
    vector<SinhVien> ds;
    nhapDS(ds);
    xuatDS(ds);

    // Test chuc nang
    string lop;
    cout << "\nNhap lop can tim: "; cin >> lop;
    timSVTheoLopVaDiem(ds, lop, 5.0);

    sort(ds.begin(), ds.end(), soSanhDiem);
    cout << "\nSau khi sap xep diem giam dan:";
    xuatDS(ds);

    xoaCuoi(ds);
    xuatDS(ds);

    return 0;
}
