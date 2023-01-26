#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,fma,avx,avx2")
using namespace std;
using namespace std::chrono;
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
int fastscan() {
  bool negative = false;
  int c, number = 0;
  for (c = getchar(); !(c > 47 && c < 58) && c != '-'; c = getchar())
    ;
  if (c == '-') c = getchar(), negative = true;
  for (; (c > 47 && c < 58); c = getchar())
    number = (number << 1) + (number << 3) + (c ^ 48);
  if (negative) return -number;
  return number;
}
void write(int x) {
  if (x < 0) {
    putchar('-');
    write(-x);
    return;
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 ^ 48);
}
int fact[200001], ifact[200001];
void Cinit() {
  fact[0] = 1;
  for (int i = 1; i < 200001; ++i) fact[i] = 1LL * fact[i - 1] * i % 1000000007;
  ifact[200001 - 1] = power(fact[200001 - 1], 1000000007 - 2, 1000000007);
  for (int i = 200001 - 2; i >= 0; --i)
    ifact[i] = 1LL * ifact[i + 1] * (i + 1) % 1000000007;
}
int nCr(int n, int r) {
  if (r < 0 || r > n) return 0;
  return (1LL * fact[n] * ifact[r] % 1000000007 * ifact[n - r] % 1000000007) %
         1000000007;
}
struct segtree {
  vector<long long> t = vector<long long>(200001),
                    lazy = vector<long long>(200001);
  void push(int v) {
    t[v * 2] += lazy[v];
    lazy[v * 2] += lazy[v];
    t[v * 2 + 1] += lazy[v];
    lazy[v * 2 + 1] += lazy[v];
    lazy[v] = 0;
  }
  void update(int v, int tl, int tr, int l, int r, int addend) {
    if (l > r) return;
    if (l == tl && tr == r) {
      t[v] += addend;
      lazy[v] += addend;
    } else {
      push(v);
      int tm = (tl + tr) / 2;
      update(v * 2, tl, tm, l, min(r, tm), addend);
      update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, addend);
      t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
  }
  int query(int v, int tl, int tr, int l, int r) {
    if (l > r) return -1;
    if (l <= tl && tr <= r) return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    return max(query(v * 2, tl, tm, l, min(r, tm)),
               query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
  }
};
int spf[5000001];
void sieve() {
  spf[1] = 1;
  for (int i = 2; i < 200001; i++) spf[i] = i;
  for (int i = 4; i < 200001; i += 2) spf[i] = 2;
  for (int i = 3; i * i < 200001; i++)
    if (spf[i] == i)
      for (int j = i * i; j < 200001; j += i)
        if (spf[j] == j) spf[j] = i;
}
vector<int> getFactorization(int x) {
  vector<int> ret;
  while (x != 1) ret.push_back(spf[x]), x = x / spf[x];
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << setprecision(10);
  int _, n, m, k, l = 0, r = 0, i, j, tt = 1, x, y, z = 1;
  bool flag = 0;
  string s, second;
  cin >> tt;
  for (_ = 1; _ <= tt; ++_) {
    int q;
    long long w, h;
    cin >> w >> h;
    vector<int> a, b, c, d;
    cin >> k;
    while (k--) {
      cin >> n;
      a.push_back(n);
    }
    sort(a.begin(), a.end());
    cin >> k;
    while (k--) {
      cin >> n;
      b.push_back(n);
    }
    sort(b.begin(), b.end());
    cin >> k;
    while (k--) {
      cin >> n;
      c.push_back(n);
    }
    sort(c.begin(), c.end());
    cin >> k;
    while (k--) {
      cin >> n;
      d.push_back(n);
    }
    sort(d.begin(), d.end());
    long long ans = 0;
    long long dx = max(a.back() - a[0], b.back() - b[0]);
    long long dy = max(c.back() - c[0], d.back() - d[0]);
    cout << max(dx * h, w * dy);
    cout << endl;
  }
  return 0;
}
