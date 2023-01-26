#include <bits/stdc++.h>
using namespace std;
int num[250005];
const long long mod = (119 << 23) + 1, root = 62;
queue<vector<long long> > q1, q2;
long long modpow(long long b, long long e) {
  long long ans = 1;
  for (; e; b = b * b % mod, e /= 2)
    if (e & 1) ans = ans * b % mod;
  return ans;
}
void ntt(vector<long long>& a, vector<long long>& rt, vector<long long>& rev,
         int n) {
  for (int i = 0; i < (n); ++i)
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  for (int k = 1; k < n; k *= 2)
    for (int i = 0; i < n; i += 2 * k)
      for (int j = 0; j < (k); ++j) {
        long long z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
        a[i + j + k] = (z > ai ? ai - z + mod : ai - z);
        ai += (ai + z >= mod ? z - mod : z);
      }
}
vector<long long> conv(const vector<long long>& a, const vector<long long>& b) {
  if (a.empty() || b.empty()) return {};
  int s = (int)(a).size() + (int)(b).size() - 1, B = 32 - __builtin_clz(s),
      n = 1 << B;
  vector<long long> L(a), R(b), out(n), rt(n, 1), rev(n);
  L.resize(n), R.resize(n);
  for (int i = 0; i < (n); ++i) rev[i] = (rev[i / 2] | (i & 1) << B) / 2;
  long long curL = mod / 2, inv = modpow(n, mod - 2);
  for (int k = 2; k < n; k *= 2) {
    long long z[] = {1, modpow(root, curL /= 2)};
    for (int i = k; i < (2 * k); ++i) rt[i] = rt[i / 2] * z[i & 1] % mod;
  }
  ntt(L, rt, rev, n);
  ntt(R, rt, rev, n);
  for (int i = 0; i < (n); ++i)
    out[-i & (n - 1)] = L[i] * R[i] % mod * inv % mod;
  ntt(out, rt, rev, n);
  return {out.begin(), out.begin() + s};
}
vector<long long> getnext() {
  if (q1.empty()) {
    vector<long long> re = q2.front();
    q2.pop();
    return re;
  }
  if (q2.empty()) {
    vector<long long> re = q1.front();
    q1.pop();
    return re;
  }
  if (q1.front().size() <= q2.front().size()) {
    vector<long long> re = q1.front();
    q1.pop();
    return re;
  } else {
    vector<long long> re = q2.front();
    q2.pop();
    return re;
  }
}
long long inv[500005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  inv[0] = 1;
  for (int i = 1; i <= 250000; ++i) inv[i] = inv[i - 1] * i % mod;
  int n;
  cin >> n;
  for (int i = 2; i <= n; ++i) {
    int x, y;
    cin >> x >> y;
    ++num[x], ++num[y], --num[i];
  }
  for (int i = 1; i <= n; ++i) {
    vector<long long> tmp;
    tmp.push_back(1);
    tmp.push_back(num[i]);
    q1.push(tmp);
  }
  for (int i = 1; i < n; ++i) {
    vector<long long> tmp1 = getnext(), tmp2 = getnext();
    q2.push(conv(tmp1, tmp2));
  }
  long long ans = 0;
  vector<long long> f = q2.front();
  for (int i = 0; i < n; ++i)
    ans = (ans + (i % 2 ? -1 : 1) * inv[n - i] * f[i]) % mod;
  cout << (ans + mod) % mod;
  return 0;
}
