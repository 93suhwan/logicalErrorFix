#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    int o;
    cin >> o;
    a[i] = o;
  }
  int mx = 8191;
  vector<bool> can[mx + 1];
  vector<bool> was[mx + 1];
  for (int j = 0; j < mx + 1; ++j) {
    can[j].resize(mx + 1);
    was[j].resize(mx + 1);
  }
  vector<int> cc[mx + 1];
  cc[0].push_back(0);
  for (int m = 0; m < n; ++m) {
    cc[a[m]].push_back(0);
    can[a[m]][0] = true;
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < cc[a[k]].size(); ++i) {
      int f = cc[a[k]][i] ^ a[k];
      for (int j = a[k] + 1; j < mx + 1; ++j) {
        if (can[j][f] || was[j][f]) break;
        cc[j].push_back(f);
        can[j][f] = true;
      }
      was[a[k]][cc[a[k]][i]] = true;
    }
    cc[a[k]].clear();
  }
  vector<bool> used(mx + 1);
  for (int k1 = 0; k1 < mx + 1; ++k1) {
    for (int l = 0; l < mx + 1; ++l) {
      if (can[k1][l]) used[l] = true;
    }
  }
  int ccc = 0;
  for (int l1 = 0; l1 < mx + 1; ++l1) {
    ccc += used[l1];
  }
  cout << ccc << "\n";
  for (int l1 = 0; l1 < mx + 1; ++l1) {
    if (used[l1]) {
      cout << l1 << " ";
    }
  }
  cout << "\n";
}
