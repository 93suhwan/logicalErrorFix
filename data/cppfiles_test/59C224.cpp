#include <bits/stdc++.h>
using namespace std;
int n, m;
void solve() {
  cin >> n;
  vector<vector<int> > a(5, vector<int>());
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      int x;
      cin >> x;
      if (x == 1) {
        a[j].push_back(i);
      }
    }
  }
  for (int i = 0; i < 5; i++) {
    if (a[i].size() < n / 2) {
      continue;
    }
    for (int j = i + 1; j < 5; j++) {
      int cnt = 0;
      vector<int> hash(n);
      if (a[j].size() < n / 2) {
        continue;
      }
      for (int k = 0; k < a[i].size(); k++) {
        if (!hash[a[i][k]]) {
          cnt++;
          hash[a[i][k]] = 1;
        }
      }
      for (int k = 0; k < a[j].size(); k++) {
        if (!hash[a[j][k]]) {
          cnt++;
          hash[a[j][k]] = 1;
        }
      }
      if (cnt == n) {
        cout << "yes" << endl;
        return;
      }
    }
  }
  cout << "no" << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
