#include <bits/stdc++.h>
using namespace std;
const long long remi = 1000000007;
const long long remi2 = 998244353;
const long long inf = 1e18 + 1e17 + 1e16;
void XORing() {
  string s;
  cin >> s;
  long long n = s.size();
  long long c0 = 0, c1 = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      c1++;
    } else {
      c0++;
    }
  }
  if (c0 == 0) {
    cout << 0 << "\n";
    return;
  }
  if (c1 == 0) {
    cout << 1 << "\n";
    return;
  }
  long long l, r;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      l = i;
      break;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '0') {
      r = i;
      break;
    }
  }
  for (int i = l; i <= r; i++) {
    if (s[i] == '1') {
      cout << 2 << "\n";
      return;
    }
  }
  cout << 1 << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  for (int i = 1; i < T + 1; i++) {
    XORing();
  }
  return 0;
}
