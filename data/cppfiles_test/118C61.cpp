#include <bits/stdc++.h>
using namespace std;
const int M = 998244353;
const int G = 3, Gi = 332748118;
int fc[250005];
int n_, lg, rev[263000], A[263000], B[263000];
int mypow(int x, int t) {
  int ans = 1, res = x;
  for (; t; t >>= 1, res = (long long)res * res % M)
    if (t & 1) ans = (long long)ans * res % M;
  return ans;
}
void ntt(int *A, int typ) {
  for (int i = 0; i < n_; i++)
    if (rev[i] > i) swap(A[i], A[rev[i]]);
  for (int i = 0; i < lg; i++) {
    int mid = (1 << i);
    int Wn = mypow(typ == 1 ? G : Gi, (M - 1) / (mid << 1));
    for (int j = 0; j < n_; j += (mid << 1)) {
      int w = 1;
      for (int k = 0; k < mid; k++, w = (long long)w * Wn % M) {
        int x = A[j + k], y = (long long)w * A[j + mid + k] % M;
        A[j + k] = (x + y) % M, A[j + mid + k] = (x - y + M) % M;
      }
    }
  }
  if (typ < 0) {
    int inv = mypow(n_, M - 2);
    for (int i = 0; i < n_; i++) A[i] = (long long)A[i] * inv % M;
  }
}
vector<int> mul(vector<int> a, vector<int> b) {
  int n = a.size() - 1, m = b.size() - 1;
  n_ = 1, lg = 0;
  while (n_ <= n + m) n_ <<= 1, lg++;
  for (int i = 1; i < n_; i++)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (lg - 1));
  for (int i = 0; i < n_; i++) {
    A[i] = B[i] = 0;
    if (i <= n) A[i] = a[i];
    if (i <= m) B[i] = b[i];
  }
  ntt(A, 1), ntt(B, 1);
  for (int i = 0; i < n_; i++) A[i] = (long long)A[i] * B[i] % M;
  ntt(A, -1);
  vector<int> ans;
  for (int i = 0; i <= n + m; i++) ans.push_back(A[i]);
  return ans;
}
int n, deg[250004];
vector<int> getpoly(int l, int r) {
  if (l == r) return vector<int>{1, deg[l] - (l > 1)};
  int md = (l + r) >> 1;
  return mul(getpoly(l, md), getpoly(md + 1, r));
}
int main() {
  fc[0] = 1;
  for (int i = 1; i < 250005; i++) fc[i] = (long long)fc[i - 1] * i % M;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    deg[u]++, deg[v]++;
  }
  vector<int> v = getpoly(1, n);
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    int tmp = (long long)v[i] * fc[n - i] % M;
    if (i & 1)
      ans = (ans + M - tmp) % M;
    else
      ans = (ans + tmp) % M;
  }
  printf("%d", ans);
}
