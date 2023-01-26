#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<vector<int> > count(n, vector<int>(5, 0));
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    for (auto &it : str) count[i][it - 'a']++;
  }
  vector<vector<int> > total(5);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < n; j++) {
      int sum1 = count[j][i];
      int sum2 = 0;
      for (int k = 0; k < 5; k++) {
        if (k != i) sum2 += count[j][k];
      }
      total[i].push_back(sum1 - sum2);
    }
  }
  for (int i = 0; i < 5; i++) sort(total[i].rbegin(), total[i].rend());
  int mx = 0;
  for (int i = 0; i < 5; i++) {
    long long sum = 0;
    int j;
    for (j = 0; j < n; j++) {
      sum += total[i][j];
      if (sum <= 0) break;
    }
    mx = max(mx, j);
  }
  cout << mx << "\n";
}
int main(void) {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
