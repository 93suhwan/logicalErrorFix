#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int fpow(int a, int b) {
  int ret = 1;
  while (b) {
    if (b & 1) ret = 1ll * ret * a % mod;
    a = 1ll * a * a % mod;
    b >>= 1;
  }
  return ret;
}
int add(int a, int b) { return (a += b) >= mod ? a - mod : a; }
int sub(int a, int b) { return (a -= b) >= 0 ? a : a + mod; }
int mul(long long a, int b) { return a * b % mod; }
int inv(int a) { return fpow(a, mod - 2); }
int k, A, h;
int num[7] = {1, 2, 3, 5, 9, 17};
int f[7];
int a[1 << 5];
map<int, vector<int>> vis[3];
void solve(int st, int status) {
  for (int i = 0; i < (1 << k - 1); i++) a[i + st] = k;
  for (int i = k; i >= 2; i--) {
    int ok = -1;
    for (int j = 0; j < (1 << k - 1); j++) {
      if (a[j + st] != i) continue;
      if (ok == -1)
        ok = j + st;
      else {
        if (status & 1)
          a[j + st]--;
        else
          a[ok]--;
        status >>= 1;
        ok = -1;
      }
    }
  }
}
void add1(int st, int status) {
  solve(st, status);
  int win = 0, u = 0;
  for (int i = 0; i < (1 << k - 1); i++) {
    if (a[i + st] == 1)
      win = i + st;
    else
      u = add(u, mul(f[a[i + st]], (i + st + 1)));
  }
  if (!st) {
    vector<int> res;
    for (int i = 0; i < (1 << k - 1); i++) res.push_back(num[a[i]]);
    int u2 = add(u, mul(win + 1, f[a[win]]));
    int u1 = add(u, mul(win + 1, f[a[win] - 1]));
    vis[2][u2] = res;
    res[win] = 1;
    vis[1][u1] = res;
  } else {
    int u2 = add(u, mul(win + 1, f[a[win]]));
    int u1 = add(u, mul(win + 1, f[a[win] - 1]));
    if (vis[1].count(sub(h, u2))) {
      vector<int> res = vis[1][sub(h, u2)];
      for (auto i : res) cout << i << " ";
      for (int i = 0; i < (1 << k - 1); i++) cout << num[a[i + st]] << " ";
      exit(0);
    }
    if (vis[2].count(sub(h, u1))) {
      vector<int> res = vis[2][sub(h, u1)];
      for (auto i : res) cout << i << " ";
      a[win] = 0;
      for (int i = 0; i < (1 << k - 1); i++) cout << num[a[i + st]] << " ";
      exit(0);
    }
  }
}
int main() {
  cin >> k >> A >> h;
  for (int i = 0; i <= k; i++) {
    f[i] = A;
    for (int j = 1; j < num[i]; j++) {
      f[i] = mul(f[i], A);
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 1 << (1 << k - 1); j++) {
      add1(i * (1 << k - 1), j);
    }
  }
  cout << -1 << endl;
}
