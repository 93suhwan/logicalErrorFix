#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long power(long long a, int n) {
  long long res = 1;
  while (n) {
    if (n & 1) res = (a * res);
    a *= a;
    n /= 2;
  }
  return res;
}
void item() {
  int n, mi = 18;
  cin >> n;
  string s = to_string(n);
  for (long long i = 0; power(2, i) < long long(1e18); i++) {
    int cnt = 0, l = 0, r = 0;
    string a = to_string(long long(power(2, i)));
    while (l < s.size() && r < a.size()) {
      if (s[l] == a[r])
        r++;
      else
        cnt++;
      l++;
    }
    cnt += a.size() - r + s.size() - l;
    mi = min(mi, cnt);
  }
  cout << mi << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  int T = 1;
  cin >> T;
  while (T--) {
    item();
  }
  return 0;
}
