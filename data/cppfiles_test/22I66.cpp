#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-O3")
using namespace std;
const int N = 2e5 + 500;
const int SQ = 450;
int sum[N];
int add[SQ][SQ], del[SQ][SQ];
vector<int> vc[N];
int k[N];
int x[N], y[N], s, ans;
int n, m, last[N], it[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = 0; i < m; i++) {
    int op;
    cin >> op >> k[i];
    k[i]--;
    vc[k[i]].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    if ((int)vc[i].size() & 1) {
      vc[i].push_back(m);
    }
  }
  for (int i = 0; i < m; i++) {
    int a = x[k[i]], b = y[k[i]];
    s = a + b;
    if (!(it[k[i]] & 1)) {
      if (s < SQ) {
        int pl = (i + a) % s;
        int pr = i % s;
        add[s][pl]++;
        del[s][pr]++;
        ans++;
      } else {
        int j = i + a;
        int p = 1;
        while (j <= vc[k[i]][it[k[i]] + 1]) {
          sum[j] += p;
          if (p == 1) {
            j += b;
          } else {
            j += a;
          }
          p *= -1;
        }
      }
    } else {
      if (s >= SQ) {
        continue;
      }
      int pl = (last[k[i]] + a) % s;
      int pr = last[k[i]] % s;
      if (pl > pr) {
        if (i % s > pl || i % s < pr) {
          ans--;
        }
      } else {
        if (i % s > pl && i % s < pr) {
          ans--;
        }
      }
      add[s][pl]--;
      del[s][pr]--;
    }
    last[k[i]] = i;
    it[k[i]]++;
    for (int s = 2; s < SQ; s++) {
      ans += add[s][i % s];
      ans -= del[s][i % s];
    }
    ans += sum[i];
    cout << ans << '\n';
  }
}
