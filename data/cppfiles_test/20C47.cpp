#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) { cout << endl; }
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << " ";
  err(++it, args...);
}
template <typename T>
inline void read(T& x) {
  x = 0;
  T f = 1;
  char ch = getchar();
  while (!isdigit(ch)) f = (ch == '-') ? -1 : 1, ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
  x *= f;
}
template <typename T, typename... Args>
inline void read(T& x, Args&... args) {
  read(x), read(args...);
}
template <typename T>
inline void write(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
template <typename T, typename... Args>
inline void write(T& x, Args&... args) {
  write(x), putchar('\n'), write(args...);
}
constexpr int MAXN = 404, MOD = 1e9 + 7;
int n, m;
int sum[MAXN][MAXN], g[MAXN][MAXN];
int mx[MAXN];
string s[MAXN];
void work(int ncase) {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) sum[i][j] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    for (int j = 1; j <= m; j++) {
      g[i][j] = s[i][j - 1] - '0';
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + g[i][j];
    }
  }
  int ans(1e9);
  for (int low = 1; low < n; low++)
    for (int high = low + 4; high <= n; high++) {
      mx[0] = -1e9;
      for (int c = 1; c <= m; c++) {
        int center1 = sum[high - 1][c - 1] - sum[low][c - 1];
        int center2 = sum[high - 1][c] - sum[low][c];
        int down1 = c - 1 - (sum[low][c - 1] - sum[low - 1][c - 1]);
        int down2 = c - (sum[low][c] - sum[low - 1][c]);
        int up1 = c - 1 - (sum[high][c - 1] - sum[high - 1][c - 1]);
        int up2 = c - (sum[high][c] - sum[high - 1][c]);
        int r = high - low - 1 - (center2 - center1);
        mx[c] = max(mx[c - 1], center2 - r + down2 + up2);
        if (c >= 4) {
          int tmp = center1 + r + up1 + down1 - mx[c - 3];
          ans = min(ans, center1 + r + up1 + down1 - mx[c - 3]);
        }
      }
    }
  cout << ans << "\n";
}
signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  int testcase = 1;
  cin >> testcase;
  for (int i = 1; i <= testcase; i++) work(i);
  return 0;
}
