#include <bits/stdc++.h>
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const long long INF = 1000000000 + 1e8;
const long long LINF = 2000000000000000000;
const long long N = 1e2 + 10;
const long long MOD = 1e9 + 7;
const long double EPS = 1e-8;
char black0 = 'a';
char black1 = 'b';
char white0 = 'c';
char white1 = 'd';
vector<vector<char>> clr = {{black0, black1}, {white0, white1}};
void make_color(long long i, long long j, long long dir,
                vector<vector<char>> &ans) {
  long long color = 1;
  if (i == 0) {
    if (j == 0) {
      color = 0;
    } else if (ans[i][j - 1] == clr[1][0] || ans[i][j - 1] == clr[1][1]) {
      color = 1;
    }
  } else {
    if (ans[i - 1][j] == clr[1][0] || ans[i - 1][j] == clr[1][1]) {
      color = 0;
    }
  }
  vector<char> cur_cl = clr[color];
  if (dir == 0) {
    ans[i][j] = cur_cl[0];
    ans[i][j + 1] = cur_cl[0];
    ans[i + 1][j] = cur_cl[1];
    ans[i + 1][j + 1] = cur_cl[1];
  } else {
    ans[i][j] = cur_cl[0];
    ans[i + 1][j] = cur_cl[0];
    ans[i][j + 1] = cur_cl[1];
    ans[i + 1][j + 1] = cur_cl[1];
  }
}
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  vector<vector<char>> ans(101, vector<char>(101, '.'));
  if (n % 2 == 0 && m % 2 == 0) {
    if (k & 1) {
      cout << "NO" << '\n';
      return;
    }
    cout << "YES" << '\n';
    long long y = 0;
    long long x = 0;
    for (long long j = 0; j < n * m / 4; j++) {
      if (x >= m) {
        y += 2;
        x = 0;
      }
      if (k) {
        make_color(y, x, 0, ans);
        k -= 2;
      } else {
        make_color(y, x, 1, ans);
      }
      x += 2;
    }
  }
  if (n % 2 == 1 && m % 2 == 0) {
    if (k < m / 2 || (k - m / 2) % 2 == 1) {
      cout << "NO" << '\n';
      return;
    }
    cout << "YES" << '\n';
    long long x = 0;
    long long y = 0;
    for (long long j = 0; j < m / 2; j++) {
      if (j & 1) {
        ans[y][x] = clr[1][0];
        ans[y][x + 1] = clr[1][0];
      } else {
        ans[y][x] = clr[1][0];
        ans[y][x + 1] = clr[1][0];
      }
    }
    k -= m / 2;
    y = 1;
    for (long long j = 0; j < (n - 1) * m / 4; j++) {
      if (x >= m) {
        y += 2;
        x = 0;
      }
      if (k) {
        make_color(y, x, 0, ans);
        k -= 2;
      } else {
        make_color(y, x, 1, ans);
      }
      x += 2;
    }
  }
  if (n % 2 == 0 && m % 2 == 1) {
    swap(n, m);
    k = n * m / 2 - k;
    if (k < m / 2 || (k - m / 2) % 2 == 1) {
      cout << "NO" << '\n';
      return;
    }
    cout << "YES" << '\n';
    long long x = 0;
    long long y = 0;
    for (long long j = 0; j < m / 2; j++) {
      if (j & 1) {
        ans[y][x] = clr[1][0];
        ans[y][x + 1] = clr[1][0];
      } else {
        ans[y][x] = clr[1][0];
        ans[y][x + 1] = clr[1][0];
      }
    }
    k -= m / 2;
    y = 1;
    for (long long j = 0; j < (n - 1) * m / 4; j++) {
      if (x >= m) {
        y += 2;
        x = 0;
      }
      if (k) {
        make_color(y, x, 0, ans);
        k -= 2;
      } else {
        make_color(y, x, 1, ans);
      }
      x += 2;
    }
    return;
  }
}
signed main() {
  srand(time(0));
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long tst = 1;
  cin >> tst;
  while (tst--) solve();
}
