#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  vector<int> res(n);
  for (int &x : a) cin >> x;
  vector<vector<int>> pos(n + 1);
  for (int i = 0; i < n; i++) {
    pos[a[i]].push_back(i);
  }
  vector<vector<int>> b;
  for (int i = 1; i <= n; i++) {
    if (pos[i].size() > 0) {
      vector<int> x = {int(pos[i].size()), i};
      b.push_back(x);
    }
  }
  sort(b.begin(), b.end(), greater<vector<int>>());
  int times = 0;
  int total = 0;
  for (vector<int> x : b) {
    if (x[0] >= k)
      times += 1;
    else
      total += x[0];
  }
  times += total / k;
  int j = 1;
  for (vector<int> x : b) {
    int num = x[1];
    int occurrence = x[0];
    if (occurrence >= k) {
      times--;
      for (int i = 0; i < k; i++) {
        res[pos[num][i]] = i + 1;
      }
    } else {
      if (times > 0) {
        for (int i : pos[num]) {
          res[i] = j;
          if (j == k) {
            times--;
            j = 1;
          } else {
            j++;
          }
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << res[i] << " ";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
