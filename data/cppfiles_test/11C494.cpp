#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
const double pi = acosl(-1);
void solve() {
  long long n;
  cin >> n;
  vector<string> a(n);
  for (long long i = 0; i < (n); i++) {
    cin >> a[i];
  }
  long long ans = 0;
  for (char c : {'a', 'b', 'c', 'd', 'e'}) {
    vector<array<long long, 3>> temp;
    for (long long i = 0; i < (n); i++) {
      long long count = 0;
      for (auto x : a[i]) {
        count += (x == c);
      }
      temp.push_back({(long long)a[i].size() - 2 * count, count, i});
    }
    long long first = 0;
    long long second = 0;
    sort(temp.begin(), temp.end());
    for (long long i = 0; i < (n); i++) {
      first += temp[i][1];
      second += temp[i][0] + temp[i][1];
      if (first > second) ans = max(ans, i + 1);
    }
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
