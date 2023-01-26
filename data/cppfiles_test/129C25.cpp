#include <bits/stdc++.h>
using namespace std;
template <class T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { scanf("%d", &x); }
void _R(long long &x) { scanf("%lld", &x); }
void _R(unsigned long long &x) { scanf("%llu", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template <class T, class... U>
void R(T &head, U &...tail) {
  _R(head);
  R(tail...);
}
template <class T>
void _W(const T &x) {
  cout << x;
}
void _W(const int &x) { printf("%d", x); }
void _W(const long long &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template <class T, class U>
void _W(const pair<T, U> &x) {
  _W(x.first);
  putchar(' ');
  _W(x.second);
}
template <class T>
void _W(const vector<T> &x) {
  for (auto i = x.begin(); i != x.end(); _W(*i++))
    if (i != x.cbegin()) putchar(' ');
}
void W() {}
template <class T, class... U>
void W(const T &head, const U &...tail) {
  _W(head);
  putchar(sizeof...(tail) ? ' ' : '\n');
  W(tail...);
}
const int MOD = 1e9 + 7, mod = 998244353;
long long qpow(long long a, long long b) {
  long long res = 1;
  a %= MOD;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
  }
  return res;
}
const int MAXN = 4e5 + 10, MAXM = 1e7 + 10;
const int INF = INT_MAX, SINF = 0x3f3f3f3f;
const long long llINF = LLONG_MAX;
const int inv2 = (MOD + 1) / 2;
const int Lim = 1 << 20;
int a[MAXN];
int n;
int cnt[MAXN];
void solve() {
  R(n);
  memset(cnt, 0, (n + 6) * sizeof(int));
  for (int i = 1; i <= n; i++) R(a[i]);
  vector<int> vec;
  for (int i = 1; i <= n; i++) {
    if (a[i] <= n && !cnt[a[i]])
      cnt[a[i]] = 1;
    else
      vec.push_back(a[i]);
  }
  sort((vec).begin(), (vec).end());
  reverse((vec).begin(), (vec).end());
  int c = 0;
  for (int i = 1; i <= n; i++)
    if (!cnt[i]) {
      c++;
      int p = vec.back();
      vec.pop_back();
      int q = i;
      if (p - q <= q) return W(-1);
    }
  W(c);
}
int main() {
  int T = 1;
  scanf("%d", &T);
  for (int kase = 1; kase <= T; kase++) {
    solve();
  }
  return 0;
}
