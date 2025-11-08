#include <iostream>
#include <cstring>
using namespace std;
int n;
int f[5005][5005]; // f[n][高精度数位]
int len; // 当前数的长度

void high_add(int x) {
    int carry = 0;
    len = 0;
    for (int i = 1; i <= 5000 || carry; i++) {
        int sum = f[x-1][i] + f[x-2][i] + carry;
        carry = sum / 10;
        f[x][i] = sum % 10;
        if (sum || carry) len = i; // 更新有效长度
    }
    // 去除前导零，找到最高有效位
    while (len > 0 && f[x][len] == 0) len--;
    // 如果所有位都是零，保留个位
    if (len == 0) len = 1;
}

int main() {
    cin >> n;
    memset(f, 0, sizeof(f));
    f[1][1] = 1;
    f[2][1] = 2;
    len = 1;
    for (int i = 3; i <= n; i++) {
        high_add(i);
    }
    if (n == 1 || n == 2) {
        cout << f[n][1];
    } else {
        for (int i = len; i > 0; i--) {
            cout << f[n][i];
        }
    }
    cout << endl;
    return 0;
}
