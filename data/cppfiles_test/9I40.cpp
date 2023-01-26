#include <bits/stdc++.h>
using namespace std;
const int N = 1003, INF = 0x3f3f3f3f;
long long qpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a;
    a = a * a;
    b >>= 1;
  }
  return ans;
}
int n, m, k;
int a[N][N];
int ans = 0;
void dfs(int first, int second) {
  if (first == n) {
    ans = second;
    return;
  }
  if (a[first][second] == 1) {
    a[first][second] = 2;
    dfs(first, second + 1);
  } else if (a[first][second] == 2) {
    dfs(first + 1, second);
  } else {
    a[first][second] = 2;
    dfs(first, second - 1);
  }
}
int main() {
  ios::sync_with_stdio;
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= k; i++) {
    int first;
    cin >> first;
    ans = 0;
    dfs(1, first);
    cout << ans << ' ';
  }
  cout << "\n";
  return 0;
}
