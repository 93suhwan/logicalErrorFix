#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 19;
const int MOD = 998244353;
const int g = 3;
int W[N];
int n, m;
int fst_pow(int a, int k) {
  int res = 1, t = a;
  while (k) {
    if (k & 1) {
      res = (long long)res * t % MOD;
    }
    t = (long long)t * t % MOD;
    k >>= 1;
  }
  return res;
}
void NTT(vector<int> &A, int ty) {
  for (int i = 0; i < (int)A.size(); ++i) {
    int j = 0, k = i, m = 1;
    while (m < (int)A.size()) {
      m <<= 1;
      j = (j << 1) | (k & 1);
      k >>= 1;
    }
    if (i < j) {
      swap(A[i], A[j]);
    }
  }
  W[0] = 1;
  for (int m = 1; m < (int)A.size(); m <<= 1) {
    int t = fst_pow(g, MOD - 1 + ty * (MOD - 1) / (m << 1));
    for (int i = 1; i < m; ++i) {
      W[i] = 1LL * W[i - 1] * t % MOD;
    }
    for (int k = 0; k < (int)A.size(); k += m << 1) {
      for (int i = k; i < k + m; ++i) {
        int t1 = A[i];
        long long t2 = (long long)A[i + m] * W[i - k] % MOD;
        A[i] = t1 + t2;
        A[i] -= A[i] > MOD ? MOD : 0;
        A[i + m] = t1 - t2;
        A[i + m] += A[i + m] < 0 ? MOD : 0;
      }
    }
  }
  if (ty == 1) {
    return;
  }
  int t = fst_pow((int)A.size(), MOD - 2);
  for (int i = 0; i < (int)A.size(); ++i) {
    A[i] = (long long)A[i] * t % MOD;
  }
}
int getsz(int n) {
  if (n ^ (n & -n)) n <<= 1;
  while (n ^ (n & -n)) n ^= n & -n;
  return n;
}
void poly_resz(vector<int> &a) {
  int n = getsz(a.size());
  a.resize(n, 0);
}
vector<int> poly_mul(vector<int> &a, vector<int> &b) {
  int len = getsz(a.size() + b.size() - 1);
  vector<int> c(len, 0);
  vector<int> d(len, 0);
  copy(a.begin(), a.end(), c.begin());
  copy(b.begin(), b.end(), d.begin());
  NTT(c, 1);
  NTT(d, 1);
  for (int i = 0; i < len; ++i) {
    c[i] = (long long)c[i] * d[i] % MOD;
  }
  NTT(c, -1);
  return c;
}
void poly_mul_inplace(vector<int> &a, vector<int> &b) {
  int len = a.size() + b.size() - 1;
  if (len ^ (len & -len)) len <<= 1;
  while (len ^ (len & -len)) len ^= len & -len;
  a.resize(len, 0);
  b.resize(len, 0);
  NTT(a, 1);
  NTT(b, 1);
  for (int i = 0; i < len; ++i) {
    a[i] = (long long)a[i] * b[i] % MOD;
  }
  NTT(a, -1);
}
vector<int> c(N), d(N);
void poly_inv(vector<int> &f, vector<int> &finv) {
  poly_resz(f);
  int n = f.size();
  finv.assign(n, 0);
  finv[0] = fst_pow(f[0], MOD - 2);
  for (int m = 2; m <= n; m <<= 1) {
    c.assign(m << 1, 0);
    d.assign(m << 1, 0);
    for (int i = 0; i < m / 2; ++i) c[i] = finv[i];
    for (int i = 0; i < m; ++i) d[i] = f[i];
    NTT(d, 1);
    NTT(c, 1);
    for (int i = 0; i < (m << 1); ++i) {
      d[i] = (long long)d[i] * c[i] % MOD * c[i] % MOD;
    }
    NTT(d, -1);
    for (int i = 0; i < m; ++i) {
      finv[i] = (2LL * finv[i] - d[i] + MOD) % MOD;
    }
  }
}
void rev(vector<int> &f) {
  f[0] = (1 - f[0] + MOD) % MOD;
  for (int i = 1; i < f.size(); ++i) {
    f[i] = (MOD - f[i]) % MOD;
  }
}
int inv[N];
vector<int> F(N + 1), G(N + 1), Finv(N + 1), P(N + 1), Q(N + 1);
int solve() {
  if (n & 1) {
    F.assign(n + 1, 0);
    G.assign(n + 1, 0);
    P.assign(n + 1, 0);
    Q.assign(n + 1, 0);
    int cl = m / 2;
    long long h = 1;
    for (int i = 1; i <= n; ++i) {
      int k = i / 2;
      if (i & 1)
        h = 1LL * h * ((cl - k + MOD) % MOD) % MOD;
      else
        h = 1LL * h * (cl + k) % MOD;
      h = 1LL * h * inv[i] % MOD;
      if (i & 1)
        Q[i] = h;
      else
        P[i] = (MOD - h);
    }
    rev(P);
    poly_inv(P, Finv);
    poly_mul_inplace(Q, Finv);
    for (int i = 1; i <= n; i += 2) {
      if (i / 2 % 2) Q[i] = MOD - Q[i];
    }
    if (m & 1) {
      Q[1] = (Q[1] + 1LL) % MOD;
    }
    int sgn = 1;
    for (int i = 1; i <= n; i += 2) {
      F[i] = Q[i] % MOD;
      G[i] = 1LL * i * F[i] % MOD;
    }
    rev(F);
    poly_inv(F, Finv);
    poly_mul_inplace(G, Finv);
    return G[n];
  } else {
    F.assign(n + 1, 0);
    G.assign(n + 1, 0);
    long long c = 1;
    for (int i = 2; i <= n; i += 2) {
      int k = i / 2;
      long long h = 1LL * (m + k) * (m - k + 1) % MOD;
      c = c * h % MOD * inv[2 * k] % MOD * inv[2 * k - 1] % MOD;
      F[i] = MOD - c;
      G[i] = 1LL * k * F[i] % MOD;
    }
    rev(F);
    poly_inv(F, Finv);
    poly_mul_inplace(Finv, G);
    return (Finv[n] * (n / 2 % 2 ? -1LL : 1LL) + MOD) % MOD;
  }
}
int a[100];
int dfs(const int n, const int m, int d) {
  if (d == n) {
    if (a[0] + a[n - 1] < m) {
      return 1;
    }
    return 0;
  }
  long long ans = 0;
  for (int i = 0; i < m; ++i) {
    if (d && i + a[d - 1] >= m) continue;
    a[d] = i;
    ans += dfs(n, m, d + 1);
  }
  return ans;
}
int bf(int n, int m) { return dfs(n, m, 0); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  inv[1] = 1;
  for (int i = 2; i <= n; ++i) {
    inv[i] = fst_pow(i, MOD - 2);
  }
  cout << solve() << endl;
  return 0;
}
