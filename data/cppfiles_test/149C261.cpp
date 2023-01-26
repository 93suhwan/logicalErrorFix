#include <bits/stdc++.h>
using namespace std;
using namespace __detail;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug &operator<<(const c &) {
    return *this;
  }
};
void solve() {
  int n, k;
  long long x;
  cin >> n >> k >> x, x--;
  string s;
  cin >> s;
  reverse((s).begin(), (s).end());
  string ans;
  int i = 0;
  while (i < n) {
    if (s[i] == '*') {
      int j = i;
      while (j + 1 < n && s[j + 1] == '*') j++;
      long long cur = (j - i + 1) * k + 1;
      ans += string(x % cur, 'b');
      x /= cur;
      i = j;
    } else {
      ans += 'a';
    }
    i++;
  }
  reverse((ans).begin(), (ans).end());
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
