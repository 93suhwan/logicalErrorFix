#include <bits/stdc++.h>
using namespace std;
const long long int mma = 5e5 + 10;
const long long int mod = 1e9 + 7;
long long int par[mma];
vector<long long int> g[mma];
long long int get_par(long long int x) {
  if (x == par[x]) {
    return x;
  }
  return par[x] = get_par(par[x]);
}
void solve() {
  long long int q;
  cin >> q;
  for (int i = 0; i < mma; i++) {
    par[i] = i;
  }
  for (int i = 0; i < q; i++) {
    long long int u;
    cin >> u;
    if (u == 1) {
      long long int x;
      cin >> x;
      g[i].push_back(x);
    } else if (u == 2) {
      long long int x, y;
      cin >> x >> y;
      g[i].push_back(x);
      g[i].push_back(y);
    }
  }
  vector<long long int> v;
  for (int i = q - 1; i >= 0; i--) {
    if (g[i].size() == 2) {
      par[get_par(par[g[i][0]])] = get_par(par[g[i][1]]);
    } else if (g[i].size() == 1) {
      v.push_back(get_par(g[i][0]));
    }
  }
  reverse(v.begin(), v.end());
  for (int j : v) {
    cout << j << " ";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
