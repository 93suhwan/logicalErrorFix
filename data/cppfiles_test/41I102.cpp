#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int inf = 1e9 + 10;
const int N = 1e3 + 10;
int read() {
  int x = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) x = (x << 1) + (x << 3) + c - '0', c = getchar();
  return x;
}
inline int add(int x, int y) {
  x += y;
  (x >= mod && (x -= mod));
  return x;
}
inline int sub(int x, int y) {
  x -= y;
  (x < 0 && (x += mod));
  return x;
}
inline int mul(int x, int y) { return 1ll * x * y % mod; }
int qpow(int x, int y, int p = mod) {
  int res = 1;
  while (y) {
    if (y & 1) res = mul(res, x);
    x = mul(x, x);
    y >>= 1;
  }
  return res;
}
int dp[N], col[N][N];
int n, k, ans;
void adde(vector<int> x, vector<int> y, int col) {
  assert(col);
  for (int X : x) {
    for (int Y : y) ::col[X][Y] = ::col[Y][X] = col;
  }
}
void solve(int n, vector<vector<int> > dots, vector<int> dye) {
  int cnt = (int)dye.size();
  assert(n == (int)dots.size());
  if (n <= k) {
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++) adde(dots[i], dots[j], dye[0]);
    return;
  }
  vector<int> tmp;
  vector<vector<int> > newdots;
  vector<vector<int> > tmpdots;
  for (int i = 0; i < n; i += k - 1) {
    int id = (i / (k - 1)) % cnt;
    for (int p = i; p < n && p < i + k - 1; p++) {
      for (int q = p + 1; q < n && q < i + k - 1; q++) {
        adde(dots[p], dots[q], dye[id]);
      }
    }
    tmp.clear();
    for (int j = i; j < n && j < i + k - 1; j++) {
      for (int x : dots[j]) tmp.push_back(x);
    }
    newdots.push_back(tmp);
  }
  for (int i = 0; i < (int)newdots.size(); i++) {
    int id = i % cnt;
    for (int j = i + 1; j < (int)newdots.size(); j++) {
      if ((j % cnt) != (i % cnt)) {
        adde(newdots[i], newdots[j], dye[id]);
      }
    }
  }
  for (int i = 0; i < cnt; i++) {
    tmpdots.clear();
    for (int j = i; j < (int)newdots.size(); j += cnt) {
      tmpdots.push_back(newdots[j]);
    }
    int d = dye.back();
    swap(dye[i], dye.back());
    dye.pop_back();
    solve((int)tmpdots.size(), tmpdots, dye);
    dye.push_back(d);
    swap(dye[i], dye.back());
  }
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= k; i++) {
    dp[i] = 1;
  }
  dp[k + 1] = 2;
  for (int i = k + 2; i <= n; i++) {
    int ans = dp[i - 1], big = ((i - 1) / (k - 1)) + 1;
    while (!(dp[((big - 1) / ans) + 1] <= ans - 1)) ans++;
    dp[i] = ans;
  }
  cout << dp[n] << endl;
  vector<int> tmp;
  vector<vector<int> > dots;
  for (int i = 1; i <= n; i++) {
    tmp.clear();
    tmp.push_back(i);
    dots.push_back(tmp);
  }
  tmp.clear();
  for (int i = 1; i <= dp[n]; i++) tmp.push_back(i);
  solve(n, dots, tmp);
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) printf("%d ", col[i][j]);
  return 0;
}
