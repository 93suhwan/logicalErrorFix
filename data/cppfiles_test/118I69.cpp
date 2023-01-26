#include <bits/stdc++.h>
using namespace std;
const long long M = 998244353;
const long long inf = 0x3f3f3f3f3f3f3f3f;
using cd = complex<double>;
const double PI = acos(-1);
void fft(vector<cd>& a, bool invert) {
  int n = a.size();
  for (int i = 1, j = 0; i < n; i++) {
    int bit = n >> 1;
    for (; j & bit; bit >>= 1) j ^= bit;
    j ^= bit;
    if (i < j) swap(a[i], a[j]);
  }
  for (int len = 2; len <= n; len <<= 1) {
    double ang = 2 * PI / len * (invert ? -1 : 1);
    cd wlen(cos(ang), sin(ang));
    for (int i = 0; i < n; i += len) {
      cd w(1);
      for (int j = 0; j < len / 2; j++) {
        cd u = a[i + j], v = a[i + j + len / 2] * w;
        a[i + j] = u + v;
        a[i + j + len / 2] = u - v;
        w *= wlen;
      }
    }
  }
  if (invert) {
    for (cd& x : a) x /= n;
  }
}
vector<long long> multiply(vector<long long> const& a,
                           vector<long long> const& b) {
  vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  long long n = 1;
  while (n < a.size() + b.size()) n <<= 1;
  fa.resize(n);
  fb.resize(n);
  fft(fa, false);
  fft(fb, false);
  for (long long i = 0; i < n; i++) fa[i] *= fb[i];
  fft(fa, true);
  vector<long long> result(n);
  for (long long i = 0; i < n; i++)
    result[i] = (long long)round(fa[i].real()) % M;
  return result;
}
vector<int> g[250001];
int children[250001];
int parent[250001];
void dfs(int u) {
  for (int x : g[u]) {
    if (parent[x]) continue;
    parent[x] = u;
    children[u]++;
    dfs(x);
  }
}
void go() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));
  parent[1] = -1;
  dfs(1);
  vector<vector<long long>> inter;
  sort(children + 1, children + n + 1);
  for (int i = 1; i <= n; i++) {
    inter.push_back({1, children[i]});
  }
  while (inter.size() > 1) {
    vector<vector<long long>> ninter;
    for (int i = 0; i < inter.size(); i += 2) {
      if (i + 1 < inter.size())
        ninter.push_back(multiply(inter[i], inter[i + 1]));
      else
        ninter.push_back(inter[i]);
    }
    inter = ninter;
  }
  vector<long long> c = inter[0];
  long long ans = 0;
  vector<long long> fac(n + 1);
  fac[0] = 1;
  for (long long i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % M;
  for (int i = 0; i < n; i++) {
    ans += c[i] * (i % 2 == 0 ? 1 : (M - 1)) % M * fac[n - i] % M;
    ans %= M;
  }
  cout << ans << endl;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int t = 1;
  while (t--) go();
}
