#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long power(long long a, long long b, long long p) {
  if (a == 0) return 0;
  long long res = 1;
  a %= p;
  while (b > 0) {
    if (b & 1) res = (res * a) % p;
    b >>= 1;
    a = (a * a) % p;
  }
  return res;
}
void solve() {
  long long n;
  cin >> n;
  vector<string> v;
  for (long long i = 0; i < n - 2; i++) {
    string tk;
    cin >> tk;
    v.push_back(tk);
  }
  string ans = "";
  cout << v[0][0];
  bool flag = true;
  for (long long i = 1; i < v.size(); i++) {
    if (v[i][0] == v[i - 1][1]) {
      cout << v[i - 1][1];
    } else {
      flag = false;
      cout << v[i - 1][1];
      cout << v[i][0];
    }
  }
  cout << v[v.size() - 1][1];
  if (flag) cout << 'b';
  cout << '\n';
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
