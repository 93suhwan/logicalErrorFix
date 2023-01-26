#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
struct ull {
  int x;
  ull() {}
  ull(int X) { x = X; }
  ull operator+(const ull &A) const { return (x + A.x) % mod; }
  ull operator+=(const ull &A) { return *this = *this + A; }
  ull operator*(const ull &A) const { return 1ll * x * A.x % mod; }
  ull operator-(const ull &A) const { return (x - A.x + mod) % mod; }
  ull operator/(const ull &A) const { return x / A.x; }
  bool operator!=(const ull &A) const { return x != A.x; }
};
const int B = 3;
long long power(long long a, int b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod, b >>= 1;
  }
  return ans;
}
int n, q;
map<int, int> lst;
vector<int> qry[200010];
int L[200010], R[200010], D[200010];
int ans[200010];
int a[200010];
ull Calc(ull s, ull n, ull d, int k) {
  if (k == 0) return n;
  if (k == 1) return s * n + n * (n - 1) / 2 * d;
  if (k == 2)
    return n * s * s + n * (n - 1) * s * d +
           (n - 1) * n / 2 * (n * 2 - 1) / 3 * d * d;
  return 2333;
}
struct BIT {
  ull T[200010];
  void modify(int x, ull v) {
    while (x <= 200005) T[x] += v, x += x & -x;
  }
  ull query(int x) {
    ull res = 0;
    while (x) res += T[x], x -= x & -x;
    return res;
  }
  ull query(int l, int r) { return query(r) - query(l - 1); }
} S[B];
void Modify(int x, int coef) {
  ull val = coef;
  for (int i = (0); i != (B); i++) S[i].modify(x, val), val = val * a[x];
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = (1); i != (n + 1); i++) scanf("%d", &a[i]);
  for (int i = (0); i != (q); i++)
    scanf("%d%d%d", &L[i], &R[i], &D[i]), qry[R[i]].push_back(i), ans[i] = 1;
  for (int i = (1); i != (n + 1); i++) {
    int x = a[i];
    if (lst.count(x)) Modify(lst[x], -1);
    lst[x] = i;
    Modify(i, 1);
    for (auto id : qry[i]) {
      int l = L[id], r = R[id], n = S[0].query(l, r).x, d = D[id];
      int s = (S[1].query(l, r).x % mod -
               1ll * n * (n - 1) / 2 % mod * d % mod + mod) *
              power(n, mod - 2) % mod;
      for (int it = (0); it != (B); it++)
        if (S[it].query(l, r) != Calc(s, n, d, it)) ans[id] = 0;
    }
  }
  for (int i = (0); i != (q); i++) printf(ans[i] ? "Yes\n" : "No\n");
  return 0;
}
