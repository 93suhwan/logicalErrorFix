#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int INF = 1e9;
const long long mod = 1e9 + 7;
int n, k, ans[N], arr[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    queue<pair<int, int> > q;
    for (int i = 1; i <= n; i++) ans[i] = INF;
    for (int i = 1; i <= n; i++) {
      cin >> arr[i];
      if (arr[i] == 1) continue;
      q.push({0, i});
      ans[i] = 0;
    }
    while (q.empty() == false) {
      int x = q.front().first;
      int idx = q.front().second;
      q.pop();
      int nx = idx + k;
      if (nx > n) nx = nx - n;
      if (ans[nx] <= x + 1) continue;
      ans[nx] = x + 1;
      q.push({x + 1, nx});
    }
    bool g = 1;
    int maxi = -1;
    for (int i = 1; i <= n; i++) {
      if (ans[i] == INF) {
        g = 0;
        break;
      }
      maxi = max(ans[i], maxi);
    }
    if (g)
      cout << maxi << '\n';
    else
      cout << -1 << '\n';
  }
}
