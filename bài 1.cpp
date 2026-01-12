#include <iostream>
#include <cmath>
using namespace std;

// Hàm tính giai thừa
long long giaithua(int n) {
    long long gt = 1;
    for (int i = 1; i <= n; i++)
        gt *= i;
    return gt;
}

// 1 S = 1 + 1/2 + 1/3 ... + 1/n
double tong1(int n) {
    double s = 0;
    for (int i = 1; i <= n; i++)
        s += 1.0 / i;
    return s;
}

// 2. S = 1/2 + 1/4 + ... + 1/2n
double tong2(int n) {
    double s = 0;
    for (int i = 1; i <= n; i++)
        s += 1.0 / (2 * i);
    return s;
}

// 3. S = 1 + 3 + 6 + 9 + ... + 3n
int tong3(int n) {
    int s = 0;
    for (int i = 1; i <= n; i++)
        s += 3 * i;
    return s;
}

// 4. S = 1 + 3 + 5 + ... + (2n + 1)
int tong4(int n) {
    int s = 0;
    for (int i = 0; i <= n; i++)
        s += 2 * i + 1;
    return s;
}

// 5. S = 1 + x + x^2 + x^3 + ... + x^n
double tong5(double x, int n) {
    double s = 0, p = 1;
    for (int i = 0; i <= n; i++) {
        s += p;
        p *= x;
    }
    return s;
}

// 6. S = 1 - x^2/2! + x^4/4! - ... + (-1)^n * x^(2n)/(2n)!
double tong6(double x, int n) {
    double s = 0;
    for (int i = 0; i <= n; i++) {
        double term = pow(x, 2 * i) / giaithua(2 * i);
        s += (i % 2 == 0) ? term : -term;
    }
    return s;
}

// 7. S = 1 + x/1! + x^2/2! + ... + x^n/n!
double tong7(double x, int n) {
    double s = 0;
    for (int i = 0; i <= n; i++)
        s += pow(x, i) / giaithua(i);
    return s;
}

int main() {
    int n;
    double x;

    cout << "Nhap n: ";
    cin >> n;
    cout << "Nhap x: ";
    cin >> x;

    cout << "S1 = " << tong1(n) << endl;
    cout << "S2 = " << tong2(n) << endl;
    cout << "S3 = " << tong3(n) << endl;
    cout << "S4 = " << tong4(n) << endl;
    cout << "S5 = " << tong5(x, n) << endl;
    cout << "S6 = " << tong6(x, n) << endl;
    cout << "S7 = " << tong7(x, n) << endl;

    return 0;
}
