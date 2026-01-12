#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <algorithm>
using namespace std;

// 1. Đếm số chữ cái trong xâu
int demChuCai(string s) {
    int dem = 0;
    for (char c : s)
        if (isalpha(c))     // Kiểm tra có phải chữ cái không
            dem++;
    return dem;
}

// 2. Đếm số chữ số trong xâu
int demChuSo(string s) {
    int dem = 0;
    for (char c : s)
        if (isdigit(c))     // Kiểm tra có phải chữ số không
            dem++;
    return dem;
}

// 3. Chèn ký tự @ trước "gmail.com"
string chenAtGmail(string s) {
    string key = "gmail.com";
    int pos = s.find(key);          // Tìm vị trí gmail.com
    if (pos != string::npos)
        s.insert(pos, "@");         // Chèn @ trước gmail.com
    return s;
}

// 4. Chèn '-' giữa hai số chẵn đứng cạnh nhau
string chenGachGiuaSoChan(string s) {
    string kq = "";
    for (int i = 0; i < s.length(); i++) {
        kq += s[i];
        if (isdigit(s[i]) && isdigit(s[i + 1])) {
            int a = s[i] - '0';
            int b = s[i + 1] - '0';
            if (a % 2 == 0 && b % 2 == 0)
                kq += '-';          // Chèn dấu -
        }
    }
    return kq;
}

// 5. Thay "gmail.com" bằng "ctech.edu.vn"
string thayGmail(string s) {
    string oldStr = "gmail.com";
    string newStr = "ctech.edu.vn";
    int pos = s.find(oldStr);
    if (pos != string::npos)
        s.replace(pos, oldStr.length(), newStr);
    return s;
}

// 6. Đưa ra các từ trong xâu
void inCacTu(string s) {
    stringstream ss(s);     // Tách xâu
    string word;
    cout << "Cac tu trong xau:\n";
    while (ss >> word)
        cout << word << endl;
}

// 7. Đổi hoa ↔ thường
string doiHoaThuong(string s) {
    for (char &c : s) {
        if (islower(c)) c = toupper(c);
        else if (isupper(c)) c = tolower(c);
    }
    return s;
}

// 8. Tìm các chữ số và tính tổng
int tongChuSo(string s) {
    int tong = 0;
    for (char c : s)
        if (isdigit(c))
            tong += c - '0';     // Chuyển ký tự thành số
    return tong;
}

// 9. Viết hoa chữ cái đầu mỗi từ
string vietHoaDauTu(string s) {
    bool dauTu = true;
    for (char &c : s) {
        if (isspace(c))
            dauTu = true;
        else {
            if (dauTu) {
                c = toupper(c);
                dauTu = false;
            }
        }
    }
    return s;
}

// 10. Đảo ngược xâu
string daoNguocXau(string s) {
    reverse(s.begin(), s.end());   // Hàm có sẵn
    return s;
}

// 11. Tìm từ dài nhất trong xâu
string tuDaiNhat(string s) {
    stringstream ss(s);
    string word, maxWord = "";
    while (ss >> word)
        if (word.length() > maxWord.length())
            maxWord = word;
    return maxWord;
}

int main() {
    string s;
    cout << "Nhap xau: ";
    getline(cin, s);   // Nhập xâu có khoảng trắng

    cout << "So chu cai: " << demChuCai(s) << endl;
    cout << "So chu so: " << demChuSo(s) << endl;

    cout << "Chen @: " << chenAtGmail(s) << endl;
    cout << "Chen - giua so chan: " << chenGachGiuaSoChan(s) << endl;
    cout << "Thay gmail: " << thayGmail(s) << endl;

    inCacTu(s);

    cout << "Doi hoa thuong: " << doiHoaThuong(s) << endl;
    cout << "Tong cac chu so: " << tongChuSo(s) << endl;
    cout << "Viet hoa dau tu: " << vietHoaDauTu(s) << endl;
    cout << "Dao nguoc xau: " << daoNguocXau(s) << endl;
    cout << "Tu dai nhat: " << tuDaiNhat(s) << endl;

    return 0;
}
