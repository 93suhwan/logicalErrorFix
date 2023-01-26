#include <bits/stdc++.h>
using namespace std;
long long MOD = 998244353;
double eps = 1e-12;
const int M = 1e9 + 7;
long long mod(long long x) { return ((x % M + M) % M); }
long long add(long long a, long long b) { return mod(mod(a) + mod(b)); }
long long mul(long long a, long long b) { return mod(mod(a) * mod(b)); }
void solve() {
  long long n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  bool check = true;
  for (long long i = 0; i < n; i++) {
    if (s1[i] == '1' && s2[i] == '1') {
      check = false;
    }
  }
  if (check) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  for (int it = 1; it <= t; it++) {
    solve();
  }
  return 0;
}
