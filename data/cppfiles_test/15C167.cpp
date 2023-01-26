#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
const double EPS = (1e-7);
const long long mod = (1e9 + 7), OO = 2e18, N = 2e5 + 100;
long long Ceil(long long x, long long y) { return (x + y - 1) / y; }
long long gcd(long long a, long long b) { return !b ? abs(a) : gcd(b, a % b); }
void run() {}
void fast() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long m = 0, n, k = 0, t = 1, d, test = 1, kk, h, x;
int mat[2000][2000];
int ma2[2000][2000];
int an[2000][2000];
struct str {
  int x, y, z;
};
int main() {
  run();
  fast();
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        mat[i][j] = 0;
        char c;
        cin >> c;
        an[i][j] = mat[i][j] = ma2[i][j] = (c == '*');
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (mat[i][j]) mat[i][j] += mat[i - 1][j - 1];
        if (mat[i][j]) ma2[i][j] += ma2[i - 1][j + 1];
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (mat[i][j] && min(mat[i - 1][j - 1], ma2[i - 1][j + 1]) >= k)
          for (int a = 0; a <= min(mat[i - 1][j - 1], ma2[i - 1][j + 1]); a++) {
            an[i - a][j - a] = an[i - a][j + a] = 0;
          }
      }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) ans += an[i][j];
    if (ans)
      cout << "NO";
    else
      cout << "YES";
    cout << '\n';
  }
}
