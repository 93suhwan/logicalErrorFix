#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    vector<int> vec[n + 1];
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (vec[x].size() < k) {
        vec[x].push_back(i);
        cnt++;
      }
    }
    cnt = (cnt / k) * k;
    vector<int> ans(n);
    int color = 1;
    for (int i = 1; i <= n; i++) {
      for (auto j : vec[i]) {
        ans[j] = color++;
        if (color % (k + 1) == 0) {
          color = 1;
        }
        cnt--;
        if (cnt == 0) {
          break;
        }
      }
      if (cnt == 0) {
        break;
      }
    }
    for (auto i : ans) {
      cout << i << " ";
    }
    cout << endl;
  }
}
