#include <bits/stdc++.h>
using namespace std;
int fastpow(int n, int x, int m) {
  int ret = 1;
  while (x) {
    if (x & 1) (ret *= n) %= m;
    x >>= 1;
    (n *= n) %= m;
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int sum = 0;
    int num = 0;
    for (int i = 0; i < n; i++) {
      sum += (s[i] - '0');
      if (s[i] != '0') {
        num++;
      }
    }
    int flag = 0;
    int copy = num;
    for (int i = n - 1; i >= 0 && copy > 0; i--) {
      if (s[i] != '0') {
        flag = 1;
        copy--;
      } else {
        flag = 0;
        break;
      }
    }
    if (num == 0) {
      cout << 0 << "\n";
    } else if (s[n - 1] != '0') {
      cout << sum + (num - 1) << "\n";
    } else {
      cout << sum + num << "\n";
    }
  }
  return 0;
}
