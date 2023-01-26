#include <bits/stdc++.h>
#pragma GCC optimization("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse4.2")
using namespace std;
template <typename T>
istream &operator>>(istream &in, vector<T> &v) {
  for (auto &i : v) cin >> i;
  return in;
}
template <typename T>
ostream &operator<<(ostream &out, vector<T> &v) {
  for (auto &i : v) cout << i << " ";
  return out;
}
void solve() {
  long long int i, j, n, a, b, c, d, m, k, sum = 0, ans = 0, cnt = 0, r = 0,
                                           e = 0, x = 0, y = 0;
  string str, s1, om, s;
  map<long long int, long long int> mp, mp1;
  set<long long int> st;
  cin >> n;
  x = (n + 1) / 3;
  y = n - (2 * x);
  cout << y << " " << x << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
