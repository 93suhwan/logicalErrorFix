#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
static inline void amn(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
static inline void amx(T &x, U y) {
  if (x < y) x = y;
}
const long long MOD = 1e9 + 7;
const long long INF = 2e18;
const long long N = 5e5 + 5;
long long n, k, x;
string s, t;
void solve() {
  cin >> n >> k >> x;
  cin >> s;
  t = "";
  vector<long long> v, vec;
  for (long long i = 0; i < n; i++) {
    t.push_back(s[i]);
    if (s[i] == '*') {
      long long j = i;
      while (j < n and s[j] == '*') {
        j++;
      }
      v.push_back(j - i);
      vec.push_back(0);
      i = j - 1;
    }
  }
  long long m = v.size();
  vector<long long> product(m + 1, 1);
  if (m > 0) product[m - 1] = v[m - 1] * k + 1;
  for (long long i = m - 2; i >= 0; i--) {
    long long p = (INF / product[i + 1]) + 1;
    if ((v[i] * k + 1) > p) {
      product[i] = INF;
    } else {
      product[i] = product[i + 1] * (v[i] * k + 1);
    }
    amn(product[i], INF);
  }
  for (long long i = 0; i < m; i++) {
    if (product[i + 1] >= x) {
      continue;
    }
    long long tmp = product[i + 1];
    vec[i] = (x - 1) / tmp;
    x -= vec[i] * tmp;
  }
  n = t.size();
  string ans;
  long long c = 0;
  for (long long i = 0; i < n; i++) {
    if (t[i] == 'a') {
      ans.push_back('a');
    } else {
      for (long long j = 1; j <= vec[c]; j++) {
        ans.push_back('b');
      }
      c++;
    }
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long test_case = 1;
  cin >> test_case;
  while (test_case--) {
    solve();
  }
  return 0;
}
