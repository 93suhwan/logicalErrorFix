#include <bits/stdc++.h>
using namespace std;
namespace Combo {
long long *fact;
long long *inv;
long long binexp(long long a, long long b) {
  if (b == 0) return 1ll;
  if (b == 1) return a % 998244353;
  if (b % 2) return (a * binexp(a, b - 1)) % 998244353;
  return binexp((a * a) % 998244353, b / 2);
}
long long choose(long long a, long long b) {
  if (a < b) return 0;
  long long res = (fact[a] * inv[b]) % 998244353;
  res *= inv[a - b];
  res %= 998244353;
  return res;
}
void build(long long n) {
  fact = new long long[n];
  inv = new long long[n];
  fact[0] = 1;
  inv[0] = 1;
  for (int i = 1; i < n; i++) {
    fact[i] = (fact[i - 1] * (long long)i) % 998244353;
    inv[i] = binexp(fact[i], 998244353 - 2);
  }
}
};  // namespace Combo
namespace FFT {
const long long INV2 = 499122177;
vector<long long> pp, ppi, ninv;
long long binexp(long long a, long long b) {
  if (b == 0) return 1ll;
  if (b == 1) return a % 998244353;
  if (b % 2) return (a * binexp(a, b - 1)) % 998244353;
  return binexp((a * a) % 998244353, b / 2);
}
vector<long long> dft(vector<long long> a, bool rev) {
  if (a.size() == 1) return a;
  vector<long long> odd, even;
  for (int i = 0; i < a.size(); i++) {
    if (i % 2)
      odd.push_back(a[i]);
    else
      even.push_back(a[i]);
  }
  odd = dft(odd, rev);
  even = dft(even, rev);
  vector<long long> res;
  long long mul = (rev ? ppi[a.size()] : pp[a.size()]);
  long long cp = 1;
  for (int i = 0; i < a.size(); i++) {
    long long cv = even[i % (a.size() / 2)] + (cp * odd[i % (a.size() / 2)]);
    cv %= 998244353;
    cp *= mul;
    cp %= 998244353;
    res.push_back(cv);
  }
  if (rev) {
    for (long long &i : res) {
      i *= INV2;
      i %= 998244353;
    }
  }
  return res;
}
vector<long long> convolution(vector<long long> a, vector<long long> b) {
  int cs = max(a.size(), b.size());
  int n = 1;
  while (n < cs) n *= 2;
  n *= 2;
  while (a.size() < n) a.push_back(0);
  while (b.size() < n) b.push_back(0);
  pp.resize(n + 1);
  ppi.resize(n + 1);
  ninv.resize(n + 1);
  int cn = 1;
  while (cn <= n) {
    pp[cn] = binexp(3, (998244353 - 1) / (n / (n / cn)));
    ppi[cn] = binexp(pp[cn], 998244353 - 2);
    ninv[cn] = binexp(cn, 998244353 - 2);
    cn *= 2;
  }
  a = dft(a, 0);
  b = dft(b, 0);
  vector<long long> res;
  for (int i = 0; i < a.size(); i++) res.push_back((a[i] * b[i]) % 998244353);
  return dft(res, 1);
}
}  // namespace FFT
int n;
vector<int> g[250250];
long long child[250250];
void dfs(int c, int l) {
  for (int i : g[c]) {
    if (i == l) continue;
    dfs(i, c);
    child[c]++;
  }
}
vector<long long> dnq(int l, int r) {
  if (l == r) return {1, child[l]};
  return FFT::convolution(dnq(l, (l + r) / 2), dnq(1 + (l + r) / 2, r));
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int n1, n2;
    scanf("%d%d", &n1, &n2);
    g[n1].push_back(n2);
    g[n2].push_back(n1);
  }
  dfs(1, -1);
  Combo::build(250250);
  queue<vector<long long>> curr;
  for (int i = 1; i <= n; i++)
    if (child[i]) curr.push({1, child[i]});
  while (curr.size() >= 2) {
    auto v1 = curr.front();
    curr.pop();
    auto v2 = curr.front();
    curr.pop();
    curr.push(FFT::convolution(v1, v2));
  }
  vector<long long> res = curr.front();
  long long ans = 0;
  for (int i = 0; i <= n; i++) {
    long long cv = (Combo::fact[n - i] * res[i]) % 998244353;
    if (i % 2) cv = (998244353 - cv);
    ans += cv;
    ans %= 998244353;
  }
  printf("%lld\n", ans);
}
