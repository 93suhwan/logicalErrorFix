#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
using namespace std;
mt19937_64 rnd;
const int maxn = 4e6 + 10;
const int mod = 998244353;
const int base = 1e15;
const long double eps = 1e-7;
int p[maxn];
int dp[maxn];
int len = 0;
int t[20];
int sl[20];
vector<int> vt;
int nw = 1;
void dosth(int id) {
  if (id == len + 1) {
    vt.push_back(nw);
    return;
  }
  int pre = 1;
  for (int i = 0; i <= sl[id]; i++) {
    nw = nw * pre;
    dosth(id + 1);
    nw = nw / pre;
    pre = pre * t[id];
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (fopen("t.inp", "r")) {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
  }
  for (int i = 2; i < maxn; i++) {
    if (p[i]) continue;
    for (int j = i; j < maxn; j += i) {
      p[j] = i;
    }
  }
  int n, m;
  cin >> n >> m;
  int nw = 0;
  dp[1] = 1;
  for (int i = 2; i <= n; i++) {
    nw = (nw + dp[i - 1]) % m;
    vt.clear();
    len = 0;
    int h = i;
    while (h != 1) {
      len++;
      t[len] = p[h];
      sl[len] = 0;
      while (h % t[len] == 0) h /= t[len], sl[len]++;
    }
    dosth(1);
    for (auto to : vt) {
      if (to == 1 || to == i) continue;
      nw = (nw - dp[(i - 1) / to] + dp[i / to] + m) % m;
    }
    nw = (nw + 1) % m;
    dp[i] = nw;
  }
  cout << dp[n] << endl;
}
