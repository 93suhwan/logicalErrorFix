#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1ll) res = (res * x) % p;
    y = y >> 1ll;
    x = (x * x) % p;
  }
  return res;
}
void solve() {
  long long n;
  cin >> n;
  char c;
  cin >> c;
  string s;
  cin >> s;
  vector<int> v;
  int d = 0;
  for (auto a : s) {
    if (a != c) {
      d = 1;
      break;
    }
  }
  if (d == 0) {
    cout << 0 << "\n";
    return;
  }
  if (s[n - 1] != c) {
    int j = n - 1;
    while (n % j == 0 && j > 1) j--;
    for (int i = 1; i <= n; i++)
      if (i % j) s[i - 1] = c;
    v.push_back(j);
  }
  int i = n - 1;
  while (i >= 0) {
    if (s[i] != c) {
      v.push_back(i + 2);
      break;
    }
    i--;
  }
  sort(v.begin(), v.end());
  cout << v.size() << "\n";
  for (auto a : v) cout << a << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
