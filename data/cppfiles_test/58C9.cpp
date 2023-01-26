#include <bits/stdc++.h>
using namespace std;
const int M = 998244353;
int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}
int mul(int a, int b) { return a * (long long)b % M; }
int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) r = mul(r, a);
    a = mul(a, a);
    b /= 2;
  }
  return r;
}
int dv(int a, int b) { return mul(a, pw(b, M - 2)); }
const int N = (int)2e5 + 7;
int n, m, x[N], y[N], fact[2 * N], ifact[2 * N], aib[N];
int comb(int n, int k) { return mul(fact[n], mul(ifact[k], ifact[n - k])); }
void addAib(int i, int x) {
  while (i < N) {
    aib[i] += x;
    i += i & (-i);
  }
}
int getAib(int i) {
  int sol = 0;
  while (i > 0) {
    sol += aib[i];
    i -= i & (-i);
  }
  return sol;
}
bool luat[N];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  fact[0] = 1;
  for (int i = 1; i < 2 * N; i++) {
    fact[i] = mul(fact[i - 1], i);
  }
  ifact[2 * N - 1] = dv(1, fact[2 * N - 1]);
  for (int i = 2 * N - 2; i >= 0; i--) {
    ifact[i] = mul(ifact[i + 1], i + 1);
  }
  for (int i = 1; i < N; i++) {
    addAib(i, +1);
  }
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
      cin >> x[i] >> y[i];
    }
    int cnt = 0;
    vector<int> kek;
    for (int j = m; j >= 1; j--) {
      int i = x[j], what = y[j];
      int sol = 0, step = (1 << 20), cur = 0;
      while (step) {
        if (sol + step < N && cur + aib[sol + step] < what) {
          sol += step;
          cur += aib[sol];
        }
        step /= 2;
      }
      cnt += luat[sol];
      luat[sol + 1] = 1;
      addAib(sol + 1, -1);
      kek.push_back(sol + 1);
    }
    for (auto &i : kek) {
      if (i < n) {
        cnt += 1 - luat[i + 1];
      }
    }
    for (auto &i : kek) {
      addAib(i, +1);
      luat[i] = 0;
    }
    cout << comb(2 * n - 1 - cnt, n) << "\n";
  }
  return 0;
}
