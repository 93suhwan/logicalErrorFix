#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b, long long md) {
  return (!b ? 1
             : (b & 1 ? a * power(a * a % md, b / 2, md) % md
                      : power(a * a % md, b / 2, md) % md));
}
const int xn = 4e5 + 10;
const int xm = -20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const long long INF = 1e18 + 10;
const long double eps = 1e-15;
const int mod = 1e9 + 7;
const int base = 257;
int n, dp[xn], ans, fen[xn], q, seg[xn << 2], pd[xn], b[xn];
pair<int, int> a[xn];
vector<pair<int, int> > Q[xn];
bool flag[xn];
void mofen(int pos, int val = 1) {
  for (pos += 5; pos < xn; pos += pos & -pos) fen[pos] = (fen[pos] + val) % mod;
}
int gefen(int pos) {
  int res = 0;
  for (pos += 5; pos > 0; pos -= pos & -pos) res = (res + fen[pos]) % mod;
  return res;
}
void modify(int id, int l, int r, int pos, int val) {
  seg[id] = max(seg[id], val);
  if (r - l == 1) return;
  int mid = l + r >> 1;
  if (pos < mid)
    modify(id << 1, l, mid, pos, val);
  else
    modify(id << 1 | 1, mid, r, pos, val);
}
int get(int id, int l, int r, int ql, int qr) {
  if (qr <= l || r <= ql || qr <= ql) return 0;
  if (ql <= l && r <= qr) return seg[id];
  int mid = l + r >> 1;
  return max(get(id << 1, l, mid, ql, qr), get(id << 1 | 1, mid, r, ql, qr));
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int l, r;
    cin >> l >> r;
    a[r] = {l, i};
  }
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    flag[x] = true;
  }
  for (int i = 1; i <= n + n; ++i) {
    if (!a[i].first) continue;
    dp[i] = (gefen(i) - gefen(a[i].first) + mod + 1) % mod;
    mofen(a[i].first, dp[i]);
    if (!flag[a[i].second]) continue;
    int mx = get(1, 0, xn, a[i].first, i);
    b[i] = mx;
    Q[mx].push_back({a[i].first, i});
    modify(1, 0, xn, a[i].first, i);
  }
  int mx = get(1, 0, xn, 0, xn);
  Q[mx].push_back({0, n + n + 1});
  fill(fen, fen + xn, 0);
  for (int i = 1; i <= n + n; ++i) {
    for (pair<int, int> x : Q[i])
      pd[x.second] = (gefen(i) - gefen(x.first) + mod) % mod;
    if (a[i].first) mofen(a[i].first, dp[i]);
  }
  for (int i = 1; i <= n + n; ++i)
    if (flag[a[i].second]) pd[i] = (pd[i] + pd[b[i]] + 1) % mod;
  cout << (pd[n + n + 1] + pd[mx]) % mod << '\n';
  return 0;
}
