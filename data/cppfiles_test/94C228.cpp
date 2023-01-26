#include <bits/stdc++.h>
using namespace std;
int a[11];
int b[11];
int cnt1;
int cnt2;
int main() {
  int _;
  cin >> _;
  while (_--) {
    cnt1 = 0;
    cnt2 = 0;
    string n;
    cin >> n;
    int a1 = 0;
    int b1 = 0;
    for (int i = 0; i < n.size(); i++)
      if (i % 2 == 0)
        a1 = a1 * 10 + n[i] - '0';
      else
        b1 = b1 * 10 + n[i] - '0';
    a1++;
    b1++;
    cout << 1ll * a1 * b1 - 2 << endl;
  }
}
