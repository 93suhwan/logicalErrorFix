#include <bits/stdc++.h>
#pragma GCC optimize("O3", "Ofast", "no-stack-protector", "unroll-loops", \
                     "omit-frame-pointer", "inline")
#pragma GCC option("arch=native", "tune=native", "no-zero-upper")
using namespace std;
const int MAXN = 1e5 + 100;
int A[MAXN];
const int MOD = 998244353;
int mp1[MAXN];
int mp2[MAXN];
bool mk1[MAXN];
bool mk2[MAXN];
vector<int> v1, v2;
void limpiar1() {
  for (auto x : v1) {
    mk1[x] = false;
    mp1[x] = 0;
  }
  v1.clear();
}
void limpiar2() {
  for (auto x : v2) {
    mk2[x] = false;
    mp2[x] = 0;
  }
  v2.clear();
}
void sumar1(int x, int v) {
  if (!mk1[x]) mk1[x] = true, v1.push_back(x);
  mp1[x] += v;
}
void sumar2(int x, int v) {
  if (!mk2[x]) mk2[x] = true, v2.push_back(x);
  mp2[x] += v;
}
void copiar() {
  for (auto x : v2) {
    sumar1(x, mp2[x]);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
      cin >> A[i];
    }
    int res = 0;
    for (int i = N; i >= 1; i--) {
      for (auto x : v1) {
        if (A[i] <= x) {
          sumar2(A[i], mp1[x]);
        } else if (A[i] % x == 0) {
          sumar2(x, mp1[x]);
          res += (long long)(A[i] / x - 1) * (long long)mp1[x] % MOD *
                 (long long)i % MOD;
          res %= MOD;
        } else {
          sumar2(A[i] / (A[i] / x + 1), mp1[x]);
          res += (long long)(A[i] / x) * (long long)mp1[x] % MOD *
                 (long long)i % MOD;
          res %= MOD;
        }
      }
      sumar2(A[i], 1);
      limpiar1();
      copiar();
      limpiar2();
    }
    limpiar1();
    cout << res << '\n';
  }
  return 0;
}
