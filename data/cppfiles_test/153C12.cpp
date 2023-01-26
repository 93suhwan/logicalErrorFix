#include <bits/stdc++.h>
using namespace std;
template <typename T>
void rd(T& x) {
  int f = 0, c;
  while (!isdigit(c = getchar())) f ^= !(c ^ 45);
  x = (c & 15);
  while (isdigit(c = getchar())) x = x * 10 + (c & 15);
  if (f) x = -x;
}
template <typename T>
void pt(T x, int c = 10) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) pt(x / 10, -1);
  putchar(x % 10 + 48);
  if (c != -1) putchar(c);
}
template <typename T>
void umax(T& x, const T& y) {
  if (x < y) x = y;
}
template <typename T>
void umin(T& x, const T& y) {
  if (x > y) x = y;
}
using vi = vector<int>;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using tpl = tuple<int, int, int>;
using pll = pair<long, long>;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int mod = 998244353;
int n;
int cnt[23][26];
int lg2[1 << 23], num[1 << 23], idxsum[1 << 23], mn[1 << 23];
ll f[1 << 23];
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (auto c : s) cnt[i][c - 'a']++;
  }
  lg2[1] = 0;
  num[1] = 1;
  idxsum[1] = 1;
  for (int i = 2; i < (1 << n); i++) {
    lg2[i] = lg2[i - 1] + ((i & (i - 1)) == 0);
    num[i] = num[i & (i - 1)] + 1;
    idxsum[i] = idxsum[i & (i - 1)] + lg2[i & (-i)] + 1;
  }
  fill(f, f + (1 << n), 1);
  for (int c = 0; c < 26; c++) {
    mn[0] = inf;
    for (int S = 1; S < (1 << n); S++) {
      int k = lg2[S & (-S)];
      mn[S] = min(mn[S & (S - 1)], cnt[k][c]);
      f[S] = f[S] * (mn[S] + 1) % mod;
    }
  }
  for (int i = 0; i < n; i++)
    for (int S = 1; S < (1 << n); S++) {
      if (!(S & (1 << i))) f[S] -= f[S | (1 << i)];
    }
  for (int i = 0; i < n; i++)
    for (int S = 1; S < (1 << n); S++) {
      if (S & (1 << i)) f[S] += f[S ^ (1 << i)];
    }
  int N = (1 << n) - 1;
  ll sum = f[N];
  ll ans = 0;
  for (int S = 1; S < (1 << n); S++) {
    int T = N ^ S;
    ll res = ((sum - f[T]) % mod + mod) % mod;
    ans ^= res * num[S] * idxsum[S];
  }
  cout << ans << "\n";
  return 0;
}
