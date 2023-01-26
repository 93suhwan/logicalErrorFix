#include <bits/stdc++.h>
using namespace std;
namespace mypoly {
const int MOD = 998244353;
const int g = 3;
int qmul(int x, int y) { return 1ll * x * y - 1ll * x * y / MOD * MOD; }
int qadd(int x, int y) { return x + y >= MOD ? x + y - MOD : x + y; }
int G[21][(1 << 20) + 1], R[21][(1 << 20) + 1], inver[(1 << 20) + 1];
int quick(int A, int B) {
  int res = 1;
  while (B) {
    if (B & 1) res = qmul(res, A);
    A = qmul(A, A);
    B >>= 1;
  }
  return res;
}
int inv(int x) { return quick(x, MOD - 2); }
struct POLY {
  int len;
  int rev[1 << 20];
  POLY() {
    for (int i = 1; i <= (1 << 20); ++i) inver[i] = inv(i);
    for (int i = 1; i <= 20; ++i) {
      G[i][0] = 1;
      R[i][0] = 1;
      int tmp2 = inv(quick(g, (MOD - 1) >> i));
      int tmp = quick(g, (MOD - 1) >> i);
      for (int j = 1; j <= (1 << i); ++j) {
        G[i][j] = qmul(G[i][j - 1], tmp);
        R[i][j] = qmul(R[i][j - 1], tmp2);
      }
    }
  }
  void butterfly(vector<int>& v) {
    for (int i = 0; i < len; ++i) {
      rev[i] = rev[i >> 1] >> 1;
      if (i & 1) rev[i] |= len >> 1;
    }
    for (int i = 0; i < len; ++i)
      if (rev[i] > i) swap(v[i], v[rev[i]]);
  }
  vector<int> ntt(vector<int> v) {
    butterfly(v);
    vector<int> nex;
    int lg = 1;
    for (int l = 2; l <= len; l <<= 1, ++lg) {
      nex.clear();
      nex.resize(len);
      for (int j = 0; j < len; j += l) {
        for (int k = 0; k < l / 2; ++k) {
          int A, B;
          A = v[j + k];
          B = v[j + l / 2 + k];
          B = qmul(B, G[lg][k]);
          nex[j + k] = qadd(A, B);
          nex[j + k + l / 2] = qadd(A, MOD - B);
        }
      }
      v = nex;
    }
    return v;
  }
  vector<int> intt(vector<int> v) {
    butterfly(v);
    vector<int> nex;
    int lg = 1;
    for (int l = 2; l <= len; l <<= 1, ++lg) {
      nex.clear();
      nex.resize(len);
      for (int j = 0; j < len; j += l) {
        for (int k = 0; k < l / 2; ++k) {
          int A, B;
          A = v[j + k];
          B = v[j + l / 2 + k];
          B = qmul(R[lg][k], B);
          nex[j + k] = qadd(A, B);
          nex[j + k + l / 2] = qadd(A, MOD - B);
        }
      }
      v = nex;
    }
    return v;
  }
  void getlen(int x) {
    len = 1;
    while (len < x) {
      len <<= 1;
    }
  }
  vector<int> mul(vector<int> A, vector<int> B) {
    if (A.size() + B.size() <= 25) {
      vector<int> ret(A.size() + B.size() - 1);
      for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < B.size(); ++j)
          ret[i + j] = qadd(ret[i + j], qmul(A[i], B[j]));
      return ret;
    }
    getlen(A.size() + B.size());
    A.resize(len);
    B.resize(len);
    A = ntt(A);
    B = ntt(B);
    for (int i = 0; i < len; ++i) A[i] = qmul(A[i], B[i]);
    A = intt(A);
    int iv = inver[len];
    for (int i = 0; i < len; ++i) {
      A[i] = qmul(A[i], iv);
    }
    while (!A.empty() && A.back() == 0) A.pop_back();
    return A;
  }
  vector<int> inverse(vector<int> A, int n) {
    vector<int> ret(n);
    if (n == 1) {
      ret[0] = quick(A[0], MOD - 2);
    } else {
      vector<int> oth = inverse(A, (n + 1) >> 1);
      ret = oth;
      ret.resize(n);
      for (int i = 0; i < n; ++i) ret[i] = (ret[i] + ret[i]) % MOD;
      getlen((oth.size() << 1) + A.size());
      oth.resize(len);
      A.resize(len);
      oth = ntt(oth);
      A = ntt(A);
      for (int i = 0; i < len; ++i) oth[i] = qmul(qmul(oth[i], oth[i]), A[i]);
      oth = intt(oth);
      oth.resize(n);
      int iv = inver[len];
      for (int i = 0; i < n; ++i) {
        oth[i] = qmul(oth[i], iv);
      }
      for (int i = 0; i < n; ++i) ret[i] = qadd(ret[i], MOD - oth[i]);
    }
    return ret;
  }
} poly;
vector<int> operator*(vector<int> A, vector<int> B) { return poly.mul(A, B); }
vector<int> operator+(vector<int> A, vector<int> B) {
  int Sz = max(A.size(), B.size());
  A.resize(Sz);
  for (int i = 0; i < B.size(); ++i) A[i] = qadd(A[i], B[i]);
  return A;
}
vector<int> operator-(vector<int> A, vector<int> B) {
  int Sz = max(A.size(), B.size());
  A.resize(Sz);
  for (int i = 0; i < B.size(); ++i) A[i] = qadd(A[i], MOD - B[i]);
  return A;
}
vector<int> operator/(vector<int> A, vector<int> B) {
  return A * poly.inverse(B, A.size() - B.size() + 1);
}
vector<int> operator%(vector<int> A, vector<int> B) {
  while (A.size() != 1 && A.back() == 0) A.pop_back();
  while (B.size() != 1 && B.back() == 0) B.pop_back();
  if (B.size() > A.size()) return A;
  vector<int> rem, mod;
  int n, m;
  n = A.size() - 1;
  m = B.size() - 1;
  reverse(A.begin(), A.end());
  reverse(B.begin(), B.end());
  rem = A / B;
  reverse(A.begin(), A.end());
  reverse(B.begin(), B.end());
  rem.resize(n - m + 1);
  reverse(rem.begin(), rem.end());
  mod = A - rem * B;
  mod.resize(m);
  return mod;
}
vector<int> der(vector<int> A) {
  while (A.size() != 1 && A.back() == 0) A.pop_back();
  vector<int> ret(A.size() - 1);
  for (int i = 0; i < ret.size(); ++i) ret[i] = 1ll * (i + 1) * A[i + 1] % MOD;
  if (ret.empty()) return vector<int>(1, 0);
  return ret;
}
}  // namespace mypoly
using namespace mypoly;
const int INF = 0x3f3f3f3f;
const int MAXN = 6e5 + 1;
int n, m, k;
vector<int> A[MAXN];
vector<int> Z[MAXN];
int fa[MAXN];
bool ba[MAXN];
vector<int> belong[MAXN];
int root(int x) { return fa[x] = (fa[x] == x ? x : root(fa[x])); }
void merge(int u, int v) { fa[root(u)] = root(v); }
void add(int& A, int B) {
  A += B;
  if (A >= MOD) A -= MOD;
}
int nex[MAXN];
int main() {
  for (int i = 0; i < MAXN; ++i) fa[i] = i, nex[i] = -1;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) {
    int ci;
    scanf("%d", &ci);
    A[i].resize(ci);
    for (int j = 0; j < ci; ++j) scanf("%d", &A[i][j]);
    map<int, int> app;
    bool bad = 0;
    for (auto it : A[i]) {
      if (app.find(it) != app.end()) {
        bad = 1;
        break;
      }
      app[it] = 1;
    }
    if (bad) {
      ba[i] = 1;
    }
    for (auto it : A[i]) Z[it].push_back(i);
  }
  for (int i = 1; i <= k; ++i) {
    A[++n] = {i};
    Z[i].push_back(n);
  }
  for (int i = 1; i <= k; ++i) {
    if (Z[i].size() > 1) {
      for (int j = 0; j < Z[i].size() - 1; ++j) {
        merge(Z[i][j], Z[i][j + 1]);
      }
    }
  }
  for (int i = 1; i <= n; ++i) ba[root(i)] |= ba[i];
  for (int i = 1; i <= n; ++i) ba[i] |= ba[root(i)];
  for (int i = 1; i <= n; ++i) belong[root(i)].push_back(i);
  vector<int> Tmp(m + 1, 0);
  vector<int> orz;
  for (int i = 1; i <= n; ++i)
    if (root(i) == i && !ba[i]) {
      vector<int>& now = belong[i];
      map<int, int> app;
      bool bad = 0;
      for (auto it : now) {
        for (auto itt : A[it]) {
          app[itt] = 1;
        }
        if (A[it].size() > 1) {
          for (int j = 0; j < A[it].size() - 1; ++j) {
            if (nex[A[it][j]] != A[it][j + 1] && nex[A[it][j]] != -1) {
              bad = 1;
            }
            nex[A[it][j]] = A[it][j + 1];
          }
        }
      }
      if (bad) continue;
      map<int, int> app2 = app;
      int sz = app2.size();
      for (auto ite = app2.begin(); ite != app2.end(); ite++)
        if (app.find(nex[ite->first]) != app.end()) app.erase(nex[ite->first]);
      if (app.size() != 1) {
        continue;
      }
      int fi = app.begin()->first;
      app2.clear();
      while (true) {
        if (fi == -1) break;
        if (app2.find(fi) != app2.end()) {
          bad = 1;
          break;
        }
        app2[fi] = 1;
        fi = nex[fi];
      }
      if (!bad && sz <= m && app2.size() == sz) {
        Tmp[sz]++;
        orz.push_back(sz);
      }
    }
  for (auto& it : Tmp) it = (MOD - it) % MOD;
  Tmp[0] = 1;
  Tmp = poly.inverse(Tmp, m + 1);
  cout << Tmp[m] << endl;
  return 0;
}
