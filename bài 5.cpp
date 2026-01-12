#include <iostream>
#include <algorithm>
using namespace std;

// 1. Nhap mang dong
void nhapMang(int* &a, int &n) {
    cout << "Nhap so phan tu: "; cin >> n;
    a = new int[n]; // Cap phat bo nho dong
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

// 2. Hien thi
void xuatMang(int* a, int n) {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

// 3. Tim Min
int timMin(int* a, int n) {
    int minVal = a[0];
    for (int i = 1; i < n; i++) if (a[i] < minVal) minVal = a[i];
    return minVal;
}

// 4. Tinh tong
long long tinhTong(int* a, int n) {
    long long tong = 0;
    for (int i = 0; i < n; i++) tong += a[i];
    return tong;
}

// 5. Xoa phan tu tai vi tri k
// Can phai tao mang moi co kich thuoc n-1
void xoaTaiK(int* &a, int &n) {
    int k;
    cout << "Nhap vi tri k can xoa (0 den " << n-1 << "): "; cin >> k;
    if (k < 0 || k >= n) return;

    int* temp = new int[n - 1]; // Tao mang moi be hon
    for (int i = 0, j = 0; i < n; i++) {
        if (i == k) continue; // Bo qua phan tu tai k
        temp[j++] = a[i];
    }
    delete[] a; // Xoa mang cu
    a = temp;   // Tro sang mang moi
    n--;        // Giam kich thuoc
    cout << "Da xoa phan tu tai " << k << endl;
}

// 6. Them x vao sau vi tri k
// Can tao mang moi kich thuoc n+1
void themVaoSauK(int* &a, int &n) {
    int x, k;
    cout << "Nhap gia tri x can them: "; cin >> x;
    cout << "Nhap vi tri k (them sau k): "; cin >> k;
    
    // Luu y: neu k = -1 tuc la them vao dau
    
    int* temp = new int[n + 1];
    int j = 0;
    for (int i = 0; i < n; i++) {
        temp[j++] = a[i];
        if (i == k) {
            temp[j++] = x; // Them x ngay sau khi copy phan tu thu k
        }
    }
    // Truong hop dac biet neu nguoi dung muon them vao cuoi cung ma vong lap chua xu ly het
    // Tuy nhien logic tren da bao quat neu k nam trong khoang hop le.
    
    delete[] a;
    a = temp;
    n++;
    cout << "Da them " << x << " vao sau vi tri " << k << endl;
}

// 7. Sap xep giam dan
void sapXepGiam(int* a, int n) {
    // Su dung sort voi con tro: a la bat dau, a + n la ket thuc
    sort(a, a + n, greater<int>()); 
    cout << "Da sap xep giam dan." << endl;
}

// 8. Xoa cac phan tu co gia tri Lon Nhat
void xoaMax(int* &a, int &n) {
    if (n == 0) return;
    
    // Tim max truoc
    int maxVal = a[0];
    for(int i=1; i<n; i++) if(a[i] > maxVal) maxVal = a[i];

    // Dem so luong phan tu khong phai la max
    int newSize = 0;
    for(int i=0; i<n; i++) if(a[i] != maxVal) newSize++;

    // Tao mang moi
    int* temp = new int[newSize];
    int j = 0;
    for(int i=0; i<n; i++) {
        if(a[i] != maxVal) {
            temp[j++] = a[i];
        }
    }

    delete[] a;
    a = temp;
    n = newSize;
    cout << "Da xoa cac phan tu co gia tri lon nhat (" << maxVal << ")" << endl;
}

int main() {
    int n;
    int* a = NULL; // Khoi tao con tro null

    nhapMang(a, n);
    cout << "Mang ban dau: "; xuatMang(a, n);

    cout << "Min: " << timMin(a, n) << endl;
    cout << "Tong: " << tinhTong(a, n) << endl;

    xoaTaiK(a, n);
    xuatMang(a, n);

    themVaoSauK(a, n);
    xuatMang(a, n);

    sapXepGiam(a, n);
    xuatMang(a, n);

    xoaMax(a, n);
    cout << "Sau khi xoa tat ca so Max: "; 
    xuatMang(a, n);

    // Giai phong bo nho khi ket thuc chuong trinh
    delete[] a; 
    return 0;
}
