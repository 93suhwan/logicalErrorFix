#include <bits/stdc++.h>
using namespace std;
bool np(int n) {
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) return true;
  return false;
}
void solve() {
  int k;
  string s;
  vector<int> f(10);
  cin >> k;
  cin >> s;
  for (int i = 0; i < k; i++) {
    int digit = s[i] - '0';
    if (digit == 1 || digit == 4 || digit == 6 || digit == 8 || digit == 9) {
      cout << 1 << endl;
      cout << digit << endl;
      return;
    }
    f[digit]++;
  }
  for (int d = 1; d <= 9; d++)
    if (f[d] >= 2) {
      cout << 2 << endl;
      cout << d << d << endl;
      return;
    }
  int m = 1 << k;
  for (int b = 1; b < m; b++) {
    int num = 0;
    int kk = 0;
    for (int i = 0; i < k; i++) {
      if (b >> i & 1) {
        int digit = s[i] - '0';
        num *= 10;
        num += digit;
        kk++;
      }
    }
    if (np(num)) {
      cout << kk << endl;
      cout << num << endl;
      return;
    }
  }
}
int main() {
  int t;
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) solve();
  return 0;
}
