#include <bits/stdc++.h>
using namespace std;
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v);
template <typename A, typename B>
ostream &operator<<(ostream &cout, pair<A, B> const &p) {
  return cout << "(" << p.first << ", " << p.second << ")";
}
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v) {
  cout << "[";
  for (int i = 0; i < v.size(); i++) {
    if (i) cout << ", ";
    cout << v[i];
  }
  return cout << "]";
}
template <typename A, typename B>
istream &operator>>(istream &cin, pair<A, B> &p) {
  cin >> p.first;
  return cin >> p.second;
}
set<long long> at[3];
long long n, k;
void solve(int tc = 0) {
  cin >> n >> k;
  long long ans = 1e12;
  for (long long i = 1; i <= k; i++) {
    ans = min(ans, *at[i].lower_bound(n));
  }
  cout << ans << '\n';
}
int main() {
  cout << setprecision(15) << fixed;
  for (long long d = 1; d <= 9; d++) {
    long long r = 0;
    for (long long i = 0; i < 12; i++) {
      r = 10 * r + d;
      at[1].insert(r);
    }
  }
  for (long long d = 0; d <= 9; d++) {
    for (long long e = d + 1; e <= 9; e++) {
      for (long long k = 0; k < 11; k++) {
        for (long long i = 0; i < (1 << k); i++) {
          long long r = 0;
          for (long long j = 0; j < k; j++) {
            long long v = (((i >> j) & 1) ? d : e);
            r = 10 * r + v;
          }
          at[2].insert(r);
        }
      }
    }
  }
  int tc = 1;
  cin >> tc;
  for (int t = 0; t < tc; t++) {
    solve(t);
  }
}
