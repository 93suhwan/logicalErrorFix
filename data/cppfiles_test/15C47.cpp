#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using _ii = pair<int, int>;
const int N = 107;
int t, n, k;
i64 dp_in[N][N], dp_out[N][N], C[N][N], f[N][N], ans, mod = 1e9 + 7;
vector<vector<int>> a;
void Pre() {
  for (int n = 0; n <= 100; n++) {
    for (int k = 0; k <= n; k++) {
      if (k == n) {
        C[k][n] = 1;
        continue;
      }
      if (k == 0) {
        C[k][n] = 1;
        continue;
      }
      if (k == 1) {
        C[k][n] = n;
        continue;
      }
      C[k][n] = (C[k - 1][n - 1] + C[k][n - 1]) % mod;
    }
  }
}
void Test(int h, int le, vector<int> &a) {
  cerr << '\n' << "Node " << h << " distance " << le << '\n';
  for (auto &i : a) cerr << i << ' ';
}
void DFS(int h, int legacy) {
  for (auto &i : a[h]) {
    if (i == legacy) continue;
    DFS(i, h);
    for (int j = 1; j <= n; j++)
      dp_in[h][j] = (dp_in[h][j] + dp_in[i][j - 1]) % mod;
  }
  ++dp_in[h][0];
}
void Cal(vector<int> &a, int cnt) {
  int m = a.size();
  vector<i64> f(cnt + 1);
  f[0] = 1;
  for (auto &i : a) {
    for (int j = cnt; j >= 1; j--) {
      f[j] += f[j - 1] * i;
      f[j] %= mod;
    }
  }
  i64 temp = f[cnt];
  ans = (ans + temp) % mod;
}
void Run(int h, int legacy) {
  for (int j = 1; j <= n; j++) {
    vector<int> d;
    d.push_back(dp_out[h][j]);
    for (auto &i : a[h]) {
      if (i == legacy) continue;
      d.push_back(dp_in[i][j - 1]);
    }
    Cal(d, k);
  }
  for (auto &i : a[h]) {
    if (i == legacy) continue;
    for (int j = 1; j <= n; j++) {
      int temp = dp_in[h][j - 1] - (j - 2 >= 0 ? dp_in[i][j - 2] : 0);
      dp_out[i][j] = temp + dp_out[h][j - 1];
    }
    Run(i, h);
  }
}
void Test() {
  for (int i = 1; i <= n; i++) {
    cerr << '\n' << "Node " << i << '\n';
    for (int j = 0; j <= n; j++)
      cerr << j << ' ' << dp_in[i][j] << ' ' << dp_out[i][j] << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    a.resize(n + 1);
    for (auto &i : a) i.clear();
    for (int i = 1; i <= n - 1; i++) {
      int x, y;
      cin >> x >> y;
      a[x].push_back(y);
      a[y].push_back(x);
    }
    ans = 0;
    memset(dp_in, 0, sizeof(dp_in));
    memset(dp_out, 0, sizeof(dp_out));
    Pre();
    DFS(1, 0);
    Run(1, 0);
    if (k == 2) ans = (n * (n - 1) / 2) % mod;
    cout << ans << '\n';
  }
}
