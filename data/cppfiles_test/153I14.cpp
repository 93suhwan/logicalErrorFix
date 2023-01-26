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
using pll = pair<long, long>;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
int n;
int cnt[23][26];
ll h[23][26];
int lg2[1 << 23], num[1 << 23], idxsum[1 << 23];
ll g[1 << 23];
ll dfs(int i, int S, int c) {
  if (S == 0) {
    if (c >= 26) return 1;
    return h[i][c];
  }
  if (c >= 26) return 0;
  vector<int> v(num[S]);
  int m = 0;
  for (int T = S; T; T &= (T - 1)) {
    v[m++] = lg2[T & (-T)];
  }
  sort((v).begin(), (v).end(),
       [&](int x, int y) { return cnt[x][c] < cnt[y][c]; });
  int D = cnt[i][c], d = min(cnt[v[0]][c], D), pred = -1;
  int p = 0;
  int T = S;
  ll sum = 0;
  while (true) {
    sum += (d - pred) * dfs(i, T, c + 1);
    if (d == D) break;
    pred = d;
    while (p < m && cnt[v[p]][c] == d) {
      T ^= (1 << v[p]);
      p++;
    }
    if (p == m)
      d = D;
    else
      d = min(cnt[v[p]][c], D);
  }
  return sum % mod;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (auto c : s) cnt[i][c - 'a']++;
    h[i][25] = cnt[i][25] + 1;
    for (int j = 24; j >= 0; j--) h[i][j] = h[i][j + 1] * (cnt[i][j] + 1) % mod;
  }
  lg2[1] = 0;
  num[1] = 1;
  idxsum[1] = 1;
  for (int i = 2; i < (1 << n); i++) {
    lg2[i] = lg2[i - 1] + ((i & (i - 1)) == 0);
    num[i] = num[i & (i - 1)] + 1;
    idxsum[i] = idxsum[i & (i - 1)] + lg2[i & (-i)] + 1;
  }
  g[0] = 0;
  for (int S = 1; S < (1 << n); S++) {
    int i = lg2[S & (-S)];
    int T = S & (S - 1);
    g[S] = (g[T] + dfs(i, T, 0)) % mod;
    cout << S << " " << g[S] << "\n";
  }
  ll ans = 0;
  for (int S = 1; S < (1 << n); S++) {
    ans ^= g[S] * num[S] * idxsum[S];
  }
  cout << ans << "\n";
  return 0;
}
