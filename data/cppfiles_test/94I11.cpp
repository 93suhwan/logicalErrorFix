#include <bits/stdc++.h>
using namespace std;
long long tc = 1;
int main() {
  ios::sync_with_stdio(0);
  long long ten[20];
  ten[0] = 1;
  string nine[20];
  for (int i = 1; i <= 18; i++) {
    ten[i] = ten[i - 1] * 10;
    nine[i] = nine[i - 1] + '9';
  }
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long a[n + 5], seg[n + 5], baki = 19;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = n - 1; i >= 0; i--) {
      seg[i] = baki - a[i];
      baki = a[i];
    }
    string s;
    for (int i = 0; i < n; i++) {
      if (ten[seg[i]] - 1 > k || k == 0) {
        cout << k + 1 << s << "\n";
        break;
      }
      s += nine[seg[i]];
      k -= (ten[seg[i]] - 1);
    }
  }
  return 0;
}
