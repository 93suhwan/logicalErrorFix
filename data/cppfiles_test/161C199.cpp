#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
void solve() {
  int n, l, r;
  cin >> n;
  vector<pair<int, int> > V(n);
  for (int i = 0; i < n; i++) {
    cin >> V[i].first >> V[i].second;
  }
  for (int i = 0; i < n; i++) {
    int l = V[i].first - 1;
    for (int j = 0; j < n; j++) {
      if (j == i) continue;
      if (V[j].first == V[i].first && V[j].second < V[i].second)
        l = max(l, V[j].second);
    }
    cout << V[i].first << ' ' << V[i].second << ' ' << l + 1 << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
