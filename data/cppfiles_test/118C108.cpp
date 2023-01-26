#include <bits/stdc++.h>
using namespace std;
const int maxn = 250005;
const int mo = 998244353;
namespace NTT {
static const int mo = 998244353;
int qkpow(int x, int y) {
  int re = 1, t = x;
  while (y) {
    if (y & 1) re = 1ll * re * t % mo;
    y >>= 1, t = 1ll * t * t % mo;
  }
  return re;
}
int tt;
int inv(int x) { return qkpow(x, mo - 2); }
void change(vector<int> &y, int len) {
  for (int i = 1, j = len >> 1; i < len - 1; i++) {
    if (i < j) swap(y[i], y[j]);
    int k = len >> 1;
    while (j >= k) j = j - k, k >>= 1;
    if (j < k) j += k;
  }
}
void ntt(vector<int> &y, int len, int on) {
  change(y, len);
  for (int h = 2; h <= len; h <<= 1) {
    int wn = qkpow(3, (mo - 1) / h);
    if (on == -1) wn = inv(wn);
    for (int j = 0; j < len; j += h) {
      int w = 1;
      for (int k = j; k < j + (h >> 1); k++) {
        int u = y[k];
        int v = 1ll * w * y[k + (h >> 1)] % mo;
        y[k] = u + v >= mo ? u + v - mo : u + v;
        y[k + (h >> 1)] = u - v < 0 ? u - v + mo : u - v;
        w = 1ll * w * wn % mo;
        tt++;
      }
    }
  }
  if (on == -1) {
    int invn = inv(len);
    for (int i = 0; i < len; i++) y[i] = 1ll * y[i] * invn % mo;
  }
}
};  // namespace NTT
void nttwork(vector<int> &cx, vector<int> &cy, vector<int> &cz) {
  int len = 1, na = cx.size(), nb = cy.size();
  int tmpa = na, tmpb = nb;
  while (len < na * 2 || len < nb * 2) len <<= 1;
  while (na < len) cx.push_back(0), na++;
  while (nb < len) cy.push_back(0), nb++;
  NTT::ntt(cx, len, 1);
  NTT::ntt(cy, len, 1);
  vector<int> tmp;
  for (int i = 0; i < len; i++) tmp.push_back(1ll * cx[i] * cy[i] % NTT::mo);
  NTT::ntt(tmp, len, -1);
  cz.clear();
  for (int i = 0; i < tmpa + tmpb - 1; i++) cz.push_back(tmp[i]);
}
int N;
struct edge {
  int to, next;
  edge() {}
  edge(int to, int next) { this->to = to, this->next = next; }
} E[maxn << 1];
int first[maxn], np, soncnt[maxn];
int J[maxn], inv[maxn], invj[maxn];
vector<int> f[maxn << 1];
void add_edge(int u, int v) {
  E[++np] = edge(v, first[u]);
  first[u] = np;
}
struct Data {
  int id, v;
  Data() {}
  Data(int id, int v) { this->id = id, this->v = v; }
  bool operator<(const Data &a) const { return v > a.v; }
};
void dfs(int i, int fa) {
  for (int p = first[i]; p; p = E[p].next) {
    int j = E[p].to;
    if (j == fa) continue;
    dfs(j, i);
    soncnt[i]++;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  J[0] = 1;
  for (int i = 1; i <= maxn - 5; i++) J[i] = 1ll * i * J[i - 1] % mo;
  inv[1] = 1;
  for (int i = 2; i <= maxn - 5; i++)
    inv[i] = 1ll * inv[mo % i] * (mo - mo / i) % mo;
  invj[0] = 1;
  for (int i = 1; i <= maxn - 5; i++) invj[i] = 1ll * inv[i] * invj[i - 1] % mo;
  cin >> N;
  for (int i = 1; i < N; i++) {
    int u, v;
    cin >> u >> v;
    add_edge(u, v);
    add_edge(v, u);
  }
  dfs(1, 0);
  int pt = 0;
  priority_queue<Data> pq;
  for (int i = 1; i <= N; i++)
    if (soncnt[i]) {
      pt++;
      f[pt].push_back(1);
      f[pt].push_back(soncnt[i]);
      pq.push(Data(pt, 2));
    }
  while (pq.size() > 1) {
    Data tmp1 = pq.top();
    pq.pop();
    Data tmp2 = pq.top();
    pq.pop();
    nttwork(f[tmp1.id], f[tmp2.id], f[++pt]);
    pq.push(Data(pt, f[pt].size()));
  }
  long long ans = J[N], w = -1;
  int n = f[pt].size();
  for (int k = 1; k < n; k++) {
    ans = ((ans + w * J[N - k] * f[pt][k]) % mo + mo) % mo;
    w *= -1;
  }
  cout << ans << '\n';
  return 0;
}
