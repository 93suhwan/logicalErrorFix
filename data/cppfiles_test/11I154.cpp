#include <bits/stdc++.h>
using namespace std;
mt19937 mrand(random_device{}());
const long long mod = 1000000007;
int rnd(int x) { return mrand() % x; }
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
const int N = 201000;
int n, a[N], p[N];
struct node {
  int mx;
} nd[8 * N];
void modify(int p, int l, int r, int tl, int x) {
  if (l == r)
    nd[p].mx = max(nd[p].mx, x);
  else {
    int md = (l + r) >> 1;
    if (tl <= md)
      modify(p + p, l, md, tl, x);
    else
      modify(p + p + 1, md + 1, r, tl, x);
    nd[p].mx = max(nd[p + p].mx, nd[p + p + 1].mx);
  }
}
int get(int p, int l, int r, int tl, int tr) {
  if (l > tr || r < tl) return 0;
  if (tl <= l && r <= tr)
    return nd[p].mx;
  else {
    int md = (l + r) >> 1;
    return max(get(p + p, l, md, tl, tr), get(p + p + 1, md + 1, r, tl, tr));
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n + 1; i++) scanf("%d", a + i), p[i] = i;
  sort(p + 1, p + n + 1, [&](int i, int j) { return i - a[i] < j - a[j]; });
  for (int i = 1; i < n + 1; i++)
    if (a[p[i]] >= 1 && a[p[i]] <= p[i]) {
      modify(1, 1, n, a[p[i]], get(1, 1, n, 1, a[p[i]] - 1) + 1);
    }
  printf("%d", nd[1].mx);
}
