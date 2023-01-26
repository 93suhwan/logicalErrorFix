#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int N = 5005;
int n, k;
int a[N], dem = 0;
long long C[N][N];
void pre_calc() {
  C[0][0] = 1;
  for (int i = 1; i <= n + 3; i++) C[0][i] = 1;
  for (int j = 1; j <= n + 3; j++) {
    for (int i = 1; i <= j; i++) {
      C[i][j] = (C[i][j - 1] + C[i - 1][j - 1]) % MOD;
    }
  }
}
long long xx = 1;
long long solve(int x) {
  if (x == 0) {
    return 1;
  }
  int st = 1, cnt = 0;
  long long res = 0;
  for (int i = x; i < dem; i++) {
    int range = (a[i + 1] - 1) - (a[i - x] + 1) + 1;
    res += (C[x][range]);
    res %= MOD;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  pre_calc();
  for (int i = 1; i <= n; i++) {
    char c;
    cin >> c;
    if (c == '1') a[++dem] = i;
  }
  a[++dem] = n + 1;
  long long res = 0;
  int t = 1;
  while (k >= 0) {
    if (t == 1) {
      res += solve(k);
      res %= MOD;
    } else {
      res -= solve(k);
      res = ((res % MOD) + MOD) % MOD;
    }
    dem--;
    t = 1 - t;
    k--;
  }
  cout << res;
  return 0;
}
