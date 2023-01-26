#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
const long long inf = 1e9 + 10;
const long long inf2 = 1e18 + 99LL;
const long double inf3 = 1e17;
const long long mod = 1e9 + 7, mod2 = 998244353;
const long double eps = 1e-9;
const bool local = false;
const int logn = 18, maxn = 300005, maxk = 2500, maxn2 = 3;
const long long maxm = 2;
long long t1[maxn * 2], t2[maxn * 2];
void build() {
  for (int i = maxn - 1; i > 0; --i) {
    t1[i] = t2[i] = 0;
  }
}
long long query1(int l, int r) {
  r = min(r, maxn);
  long long res = 0;
  for (l += maxn, r += maxn; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res += t1[l++];
    if (r & 1) res += t1[--r];
  }
  return res;
}
long long query2(int l, int r) {
  r = min(r, maxn);
  long long res = 0;
  for (l += maxn, r += maxn; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res += t2[l++];
    if (r & 1) res += t2[--r];
  }
  return res;
}
void update1(int p) {
  for (t1[p += maxn]++; p > 1; p >>= 1) t1[p >> 1] = t1[p] + t1[p ^ 1];
}
void update2(int p) {
  int tp = p;
  for (t2[p += maxn] += tp; p > 1; p >>= 1) t2[p >> 1] = t2[p] + t2[p ^ 1];
}
long long ans = 0, a;
void f1() {
  for (int i = 0; i * a < maxn; i++) {
    int l = i * a, r = (i + 1) * a;
    ans += query2(l, r) - i * a * query1(l, r);
  }
}
void f2() {
  for (int i = 2; i <= maxm; i++) {
    ans += t1[maxn + i] * (a % i);
  }
  for (long long i = 1;; i++) {
    int l = max(maxm + 1, a / i + 1);
    int r = maxn;
    if (i > 1) r = a / (i - 1);
    if (l > r) break;
    r += 1;
    ans += query1(l, r) * a - (i - 1) * query2(l, r);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  build();
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    f1();
    f2();
    update1(a);
    update2(a);
    cout << ans << ' ';
  }
  cout << nl;
}
