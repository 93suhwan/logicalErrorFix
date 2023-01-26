#include <bits/stdc++.h>
using namespace std;
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << H;
  debug_out(T...);
}
const int MAXN = 1e5 + 10;
int T = 1, n, m;
vector<vector<vector<vector<bool>>>> mark;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while (T--) {
    cin >> n >> m;
    mark.resize(n + 1);
    for (int i = 0; i <= n; i++) {
      mark[i].resize(m + 1);
      for (int j = 0; j <= m; j++) {
        mark[i][j].resize(2);
        for (int k = 0; k < 2; k++) {
          mark[i][j][k].resize(2);
        }
      }
    }
  }
  return 0;
}
