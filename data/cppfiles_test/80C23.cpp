#include <bits/stdc++.h>
const long double eps = 1e-9;
const long long mod = 1e9 + 7, ll_max = 1e18;
const int MX = 2e6 + 10, int_max = 0x3f3f3f3f;
using namespace std;
template <class T>
void read(T &x) {
  cin >> x;
}
template <class H, class T>
void read(pair<H, T> &p) {
  cin >> p.first >> p.second;
}
template <class T, size_t S>
void read(array<T, S> &a) {
  for (T &i : a) read(i);
}
template <class T>
void read(vector<T> &v) {
  for (T &i : v) read(i);
}
template <class H, class... T>
void read(H &h, T &...t) {
  read(h);
  read(t...);
}
template <class H, class T>
ostream &operator<<(ostream &o, pair<H, T> &p) {
  o << p.first << " " << p.second;
  return o;
}
template <class T, size_t S>
ostream &operator<<(ostream &o, array<T, S> &a) {
  string s;
  for (T i : a) o << s << i, s = " ";
  return o;
}
template <class T>
ostream &operator<<(ostream &o, vector<T> &v) {
  string s;
  for (T i : v) o << s << i, s = " ";
  return o;
}
template <class T>
void write(T x) {
  cout << x;
}
template <class H, class... T>
void write(const H &h, const T &...t) {
  write(h);
  write(t...);
}
void print() { write('\n'); }
template <class H, class... T>
void print(const H &h, const T &...t) {
  write(h);
  if (sizeof...(t)) write(' ');
  print(t...);
}
template <typename T>
void ckmin(T &a, const T &b) {
  a = min(a, b);
}
template <typename T>
void ckmax(T &a, const T &b) {
  a = max(a, b);
}
vector<int> adj[MX];
int a[MX], b[MX], c[MX], BIT[MX], srt[MX];
int n, m;
void U(int k) {
  for (; k <= MX - 1; k += (k & (-k))) BIT[k]++;
}
int S(int k) { return (!k) ? 0 : (BIT[k] + S(k - (k & (-k)))); }
void dnq(int lo, int hi, int l, int r) {
  if (r < l) return;
  if (lo == hi) {
    for (int i = l; i <= r; i++) {
      adj[lo].push_back(i);
    }
    return;
  }
  int mid = (l + r) / 2;
  int suf = 0, pre = 0, ans = int_max, ind = lo;
  for (int i = lo; i <= hi; i++) {
    if (a[i] < b[mid]) suf++;
  }
  for (int i = lo; i <= hi; i++) {
    if (a[i] > b[mid]) pre++;
    if (a[i] < b[mid]) suf--;
    if (pre + suf < ans) {
      ckmin(ans, pre + suf);
      ind = i;
    }
  }
  adj[ind].push_back(mid);
  dnq(lo, ind, l, mid - 1);
  dnq(ind, hi, mid + 1, r);
}
void solve() {
  read(n, m);
  for (int i = 0; i <= (n + m + 5); i++) {
    adj[i].clear();
    a[i] = b[i] = c[i] = BIT[i] = srt[i] = 0;
  }
  for (int i = 1; i <= n; i++) read(i[a]);
  for (int i = 0; i < m; i++) read(b[i]);
  sort(b, b + m);
  a[0] = 0;
  n++;
  dnq(0, n - 1, 0, m - 1);
  int nm = 0;
  for (int i = 0; i < n; i++) {
    c[nm++] = a[i];
    sort(adj[i].begin(), adj[i].end());
    for (int v : adj[i]) {
      c[nm++] = b[v];
    }
  }
  assert(nm == n + m);
  for (int i = 0; i < nm; i++) srt[i] = c[i];
  sort(srt, srt + nm);
  for (int i = 0; i < nm; i++)
    c[i] = lower_bound(srt, srt + nm, c[i]) - srt + 1;
  long long inv = 0;
  for (int i = nm - 1; ~i; i--) {
    inv += (long long)S(c[i] - 1);
    U(c[i]);
  }
  print(inv);
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
