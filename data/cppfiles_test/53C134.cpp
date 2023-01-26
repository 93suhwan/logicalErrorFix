#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int t;
int tc;
char c;
const int N = 3e5 + 3;
string str;
void clr() { return; }
void solve() {
  cin >> n >> c;
  cin >> str;
  int flag = 0;
  int flag2 = 0;
  int valc = -1;
  for (int i = 0; i < n; i++) {
    if ((i + 1) > n / 2 && c == str[i] && flag2 == 0) {
      valc = i + 1;
      flag2 = 1;
    }
    if (c != str[i]) {
      flag = 1;
    }
  }
  if (flag == 0) {
    cout << 0 << '\n';
    return;
  }
  if (flag2 == 1) {
    cout << 1 << '\n';
    cout << valc << '\n';
    return;
  } else {
    cout << 2 << '\n';
    cout << n / 2 + 1 << " " << n << '\n';
  }
  return;
}
int main() {
  cin >> tc;
  for (t = 0; t < tc; t++) solve();
  return 0;
}
