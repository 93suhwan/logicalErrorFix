#include <bits/stdc++.h>
using namespace std;
const int N = 8172;
int can[N];
queue<int> q[N];
bitset<N> dp[N];
void Set(int p, int j) {
  while (p < N) {
    if (dp[p][j]) {
      return;
    }
    dp[p][j] = 1;
    if (p + 1 < N && dp[p + 1][j ^ (p + 1)] == 0) {
      q[p + 1].push(j ^ (p + 1));
    }
    p++;
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  Set(0, 0);
  while (n--) {
    int p;
    cin >> p;
    while (!q[p].empty()) {
      int j = q[p].front();
      q[p].pop();
      Set(p, j);
    }
  }
  int cnt = 0;
  for (int p = 0; p < N; p++) {
    for (int j = 0; j < N; j++) {
      can[j] |= dp[p][j];
    }
  }
  for (int j = 0; j < N; j++) {
    cnt += can[j];
  }
  cout << cnt << '\n';
  for (int j = 0; j < N; j++) {
    if (can[j]) {
      cout << j << ' ';
    }
  }
  cout << '\n';
}
