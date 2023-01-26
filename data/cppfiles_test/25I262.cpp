#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 998244353;
double eps = 1e-12;
void solve() {
  string s;
  cin >> s;
  string t;
  cin >> t;
  int clip = s.find(t[0]);
  if (t[0] != s[clip]) {
    cout << "NO\n";
    return;
  }
  if (s.size() > 1 && t.size() > 1) {
    if (t[1] == s[clip + 1]) {
      clip += 1;
    } else {
      cout << "NO\n";
      return;
    }
  }
  for (long long i = 2; i < t.size(); i++) {
    if (t[i] == s[clip + 1]) {
      clip += 1;
    } else if (t[i] == s[clip - 1]) {
      clip -= 1;
    } else {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
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
