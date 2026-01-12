#include <iostream>     // Thư viện nhập xuất
#include <cmath>        // Thư viện toán học (sqrt)
using namespace std;    // Sử dụng không gian tên std

// 1. Hàm nhập ma trận vuông cấp n
void nhapMaTran(int a[][50], int &n) {
    cout << "Nhap cap n cua ma tran: ";
    cin >> n;                           // Nhập kích thước ma trận

    for (int i = 0; i < n; i++)         // Duyệt từng hàng
        for (int j = 0; j < n; j++) {   // Duyệt từng cột
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];             
        }
}

// 2. Hàm in ma trận
void xuatMaTran(int a[][50], int n) {
    cout << "Ma tran:\n";
    for (int i = 0; i < n; i++) {      
        for (int j = 0; j < n; j++)     
            cout << a[i][j] << "\t";    
        cout << endl;                   // Xuống dòng sau mỗi hàng
    }
}

// 3. Hàm tính tổng các phần tử của ma trận
int tongMaTran(int a[][50], int n) {
    int s = 0;                          // Biến lưu tổng
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            s += a[i][j];             
    return s;                           
}

// 4. Hàm tìm phần tử lớn nhất của hàng k
int maxHangK(int a[][50], int n, int k) {
    int max = a[k][0];                  // Giả sử phần tử đầu là lớn nhất
    for (int j = 1; j < n; j++)
        if (a[k][j] > max)             
            max = a[k][j];
    return max;                         
}

// 5. Hàm đếm số âm của cột k
int demAmCotK(int a[][50], int n, int k) {
    int dem = 0;                       
    for (int i = 0; i < n; i++)
        if (a[i][k] < 0)                
            dem++;
    return dem;
}

// Hàm kiểm tra số chính phương
bool laSoChinhPhuong(int x) {
    if (x < 0) return false;            // Số âm không là chính phương
    int t = sqrt(x);                    // Lấy căn bậc hai
    return t * t == x;                  // Kiểm tra chính phương
}

// 6. In các số chính phương trên đường chéo chính
void inChinhPhuongCheoChinh(int a[][50], int n) {
    cout << "So chinh phuong tren duong cheo chinh: ";
    for (int i = 0; i < n; i++)
        if (laSoChinhPhuong(a[i][i]))   // Đường chéo chính a[i][i]
            cout << a[i][i] << " ";
    cout << endl;
}

// 7. Tính trung bình cộng các ước của 150 trên đường chéo phụ
double tbUoc150CheoPhu(int a[][50], int n) {
    int tong = 0, dem = 0;              // Biến tổng và đếm
    for (int i = 0; i < n; i++) {
        int x = a[i][n - 1 - i];        
        if (x != 0 && 150 % x == 0) {   // Kiểm tra x là ước của 150
            tong += x;
            dem++;
        }
    }
    return (dem == 0) ? 0 : (double)tong / dem; // Tránh chia 0
}

// 8. Sắp xếp các phần tử của mỗi hàng theo chiều giảm dần
void sapXepHangGiamDan(int a[][50], int n) {
    for (int i = 0; i < n; i++)         // Duyệt từng hàng
        for (int j = 0; j < n - 1; j++)
            for (int k = j + 1; k < n; k++)
                if (a[i][j] < a[i][k]) { // Nếu sai thứ tự
                    int temp = a[i][j]; // Hoán đổi
                    a[i][j] = a[i][k];
                    a[i][k] = temp;
                }
}

int main() {
    int a[50][50], n, k;                // Khai báo ma trận và biến

    nhapMaTran(a, n);                  
    xuatMaTran(a, n);                   

    cout << "Tong cac phan tu = "
         << tongMaTran(a, n) << endl;   // In tổng

    cout << "Nhap hang k: ";
    cin >> k;
    cout << "Max hang " << k << " = "
         << maxHangK(a, n, k) << endl;  // In max hàng k

    cout << "Nhap cot k: ";
    cin >> k;
    cout << "So am cot " << k << " = "
         << demAmCotK(a, n, k) << endl; // In số âm cột k

    inChinhPhuongCheoChinh(a, n);        // In SCP đường chéo chính

    cout << "TBC cac uoc cua 150 tren cheo phu = "
         << tbUoc150CheoPhu(a, n) << endl;

    sapXepHangGiamDan(a, n);             // Sắp xếp giảm dần từng hàng
    cout << "Ma tran sau khi sap xep:\n";
    xuatMaTran(a, n);

    return 0;                           
}
