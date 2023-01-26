#include <bits/stdc++.h>
using namespace std;
int __gcd(int a, int b) { return (b == 0 ? a : __gcd(b, a % b)); }
const int inf = 2e9;
const int maxn = 5e4 + 100;
int rk[maxn][6];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(15);
  int _;
  cin >> _;
  while (_--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= 5; ++j) cin >> rk[i][j];
    }
    int now = 1;
    for (int i = 2; i <= n; ++i) {
      int score_now = 0, score_i = 0;
      for (int j = 1; j <= 5; ++j) {
        if (rk[i][j] < rk[now][j])
          score_i++;
        else
          score_now++;
      }
      if (score_i > score_now) now = i;
    }
    for (int i = 1; i <= n; ++i) {
      if (i == now) continue;
      int score = 0;
      for (int j = 1; j <= 5; ++j) {
        if (rk[now][j] < rk[i][j]) ++score;
      }
      if (score < 3) {
        now = -1;
        break;
      }
    }
    cout << now << "\n";
  }
}
