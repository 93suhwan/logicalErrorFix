#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
int n, L, R;
struct nd {
  unsigned long long f1, f2;
} tmp;
unsigned long long f1, f2;
vector<nd> f[2];
vector<int> v[104];
unsigned long long st;
int now, nxt, k, K, i, x, j, ee, u[123], l[123];
int main() {
  cin >> n >> K;
  if (n == 1) return cout << "ACCEPTED", 0;
  for (i = 1; i <= K; ++i) {
    cin >> l[i];
    for (j = 1; j <= l[i]; ++j)
      cin >> x, --x, v[i].push_back(x), st |= (1ll << x);
  }
  if (st != (1ll << n) - 1) return cout << "REJECTED\n", 0;
  tmp.f1 = (1ll << n) - 1;
  tmp.f2 = 0;
  f[0].push_back(tmp);
  for (i = 1; i <= K; ++i) {
    nxt = now ^ 1;
    for (j = 0; j < f[now].size(); ++j) {
      f1 = f[now][j].f1;
      f2 = f[now][j].f2;
      L = 0;
      R = l[i];
      for (k = 0; k < l[i]; ++k) {
        if (((f1 >> v[i][k]) & 1) ^ 1) {
          if (((f2 >> v[i][k]) & 1) ^ 1)
            u[L++] = 0;
          else
            u[--R] = 1, f2 ^= (1ll << v[i][k]);
        } else
          f1 ^= 1ll << v[i][k];
      }
      for (k = R; k < l[i]; ++k) f2 |= (1ll << v[i][k]);
      tmp.f1 = f1;
      tmp.f2 = f2;
      f[nxt].push_back(tmp);
      for (k = R - 1; k >= L; --k) {
        tmp.f2 |= 1ll << v[i][k];
        f[nxt].push_back(tmp);
      }
    }
    f[now].clear();
    now = nxt;
  }
  for (i = 0; i < f[now].size(); ++i) {
    f1 = f[now][i].f2;
    f2 = 0;
    while (f1) {
      if (f1 & 1)
        f2 = 1, f1 >>= 1;
      else if (f2)
        return cout << "REJECTED", 0;
      else
        f1 >>= 1;
    }
  }
  cout << "ACCEPTED";
}
