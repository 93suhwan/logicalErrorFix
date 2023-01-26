#include <bits/stdc++.h>
using namespace std;
using db = double;
using ll = long long;
using ld = long double;
using vint = vector<int>;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using ull = unsigned long long;
inline int read() {
  int x = 0;
  char s = getchar();
  while (!isdigit(s)) s = getchar();
  while (isdigit(s)) x = x * 10 + s - '0', s = getchar();
  return x;
}
const int N = 3e3 + 5;
int n, a[N], f[N][N];
vector<int> buc[N];
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++) buc[i].clear();
    for (int i = 1; i <= n; i++) cin >> a[i], buc[a[i]].push_back(i);
    for (int i = n; i; i--)
      for (int j = i; j <= n; j++) {
        f[i][j] = (i == j ? 1 : f[i + 1][j] + 1);
        for (int it : buc[a[i]])
          if (it > i && it <= j) {
            int cur = (i + 1 <= it - 1 ? f[i + 1][it - 1] : 0);
            f[i][j] = min(f[i][j], f[it][j] + cur);
          }
      }
    cout << f[1][n] - 1 << endl;
  }
  return 0;
}
