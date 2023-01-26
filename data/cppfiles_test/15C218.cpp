#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000000 + 7;
int ioo = 1000000000;
long long loo = 1000000000000000000;
void add_self(int &x, int y) {
  if ((x += y) >= mod) x -= mod;
}
int add(int x, int y) { return add_self(x, y), x; }
void sub_self(int &x, int y) {
  if ((x -= y) < 0) x += mod;
}
int sub(int x, int y) { return sub_self(x, y), x; }
int mul(int x, int y) { return (long long)x * y % mod; }
long long po(long long k, long long n) {
  long long res = 1;
  while (n) {
    if (n % 2) res *= k;
    k *= k;
    n /= 2;
  }
  return res;
}
long long pom(long long k, long long n) {
  long long res = 1;
  while (n) {
    if (n % 2) res = mul(res, k);
    k = mul(k, k);
    n /= 2;
  }
  return res;
}
char a[15][25];
bool is[15][25];
int n, m, k;
void check(int ci, int cj) {
  int i = ci;
  int cnt = 0;
  while (i - 1 >= 1 && cj - cnt - 1 >= 1 && cj + cnt + 1 <= m) {
    if (a[i - 1][cj - cnt - 1] == '*' && a[i - 1][cj + cnt + 1] == '*') {
      i--;
      cnt++;
    } else
      break;
  }
  if (cnt >= k) {
    int i = ci - 1;
    int jl = cj - 1, jr = cj + 1;
    is[ci][cj] = true;
    while (cnt--) {
      is[i][jl] = true;
      is[i][jr] = true;
      jl--, jr++, i--;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) is[i][j] = false;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) cin >> a[i][j];
    for (int i = n; i >= 1; i--) {
      for (int j = 1; j <= m; j++) {
        if (a[i][j] == '*') check(i, j);
      }
    }
    bool yes = true;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (a[i][j] == '*') yes &= is[i][j];
      }
    }
    if (yes)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
