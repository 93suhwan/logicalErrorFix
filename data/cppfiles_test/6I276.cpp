#include <bits/stdc++.h>
using namespace std;
long long oll = 0;
bool comp(const pair<int, int> &a, const pair<int, int> &b) {
  return a.first < b.first;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<bool> state(n + 1, 1);
  for (long long i = (int)0; i < (int)m; i++) {
    int u, v;
    cin >> u >> v;
    int mx = max(u, v);
    int mn = min(u, v);
    state[mn] = 0;
  }
  int sum = 0;
  for (long long i = (int)1; i < (int)n + 1; i++) sum += state[i];
  int q;
  cin >> q;
  while (q--) {
    int mod, u, v, mx, mn;
    cin >> mod;
    if (mod == 1) {
      cin >> u >> v;
      int mx = max(u, v);
      int mn = min(u, v);
      sum -= state[mn];
      state[mn] = 0;
    }
    if (mod == 2) {
      cin >> u >> v;
      int mx = max(u, v);
      int mn = min(u, v);
      if (state[mx] == 1 && state[mn] == 0) {
        sum -= state[mn];
        state[mn] = 1;
        sum += state[mn];
      }
    }
    if (mod == 3) {
      cout << sum << "\n";
    }
  }
  return 0;
}
