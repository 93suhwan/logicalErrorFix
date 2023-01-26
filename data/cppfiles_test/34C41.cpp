#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const int N = (2 << 13);
int can[N];
vector<int> q[N];
int mn[N];
void Set(int p, int j) {
  if (p >= mn[j]) return;
  for (int tp = p; tp < mn[j]; tp++) {
    if (tp + 1 < N && mn[j ^ (tp + 1)] > tp + 1) {
      q[tp + 1].push_back(j ^ (tp + 1));
    }
  }
  mn[j] = p;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  fill(mn, mn + N, N);
  int n;
  cin >> n;
  Set(0, 0);
  while (n--) {
    int p;
    cin >> p;
    for (auto j : q[p]) {
      Set(p, j);
    }
    q[p].clear();
  }
  int cnt = 0;
  for (int j = 0; j < N; j++) {
    can[j] = (mn[j] != N);
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
