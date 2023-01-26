#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6 + 50;
template <typename A, typename B>
istream& operator>>(istream& o, pair<A, B>& a) {
  return o >> a.first >> a.second;
}
template <typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> a) {
  return o << '(' << a.first << ", " << a.second << ')';
}
namespace io {
const long long SIZE = 1e7 + 10;
char inbuff[SIZE];
char *l, *r;
inline void init() {
  l = inbuff;
  r = inbuff + fread(inbuff, 1, SIZE, stdin);
}
inline char gc() {
  if (l == r) init();
  return (l != r) ? *(l++) : EOF;
}
void R(long long& x) {
  x = 0;
  char ch = gc();
  while (!isdigit(ch)) ch = gc();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = gc();
}
}  // namespace io
using io::R;
void solve() {
  long long n, sum = 0;
  cin >> n;
  vector<long long> a(n);
  for (long long& i : a) cin >> i, sum += i;
  long long t = n * (n + 1) / 2;
  if (sum % t) {
    cout << "NO\n";
    return;
  }
  vector<long long> ans;
  sum /= t;
  for (long long i = 0; i <= n - 1; i++) {
    long long j = (i - 1 + n) % n;
    long long t = a[j] - a[i] + sum;
    if (t > 0 and t % n == 0)
      ans.push_back(t / n);
    else {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
  for (auto i : ans) cout << i << ' ';
  cout << '\n';
  ;
}
void input() {}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  ;
  long long tt = 1;
  cin >> tt;
  while (tt--) {
    input();
    solve();
  }
}
