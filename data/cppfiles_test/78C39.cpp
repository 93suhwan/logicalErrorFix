#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int j = 0; j < n; j++) cin >> a[j];
    vector<long long> cnt(40);
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < 40; k++) {
        cnt[k] += ((a[j] >> k) & 1);
      }
    }
    vector<int> ans;
    for (int j = 1; j <= n; j++) {
      bool out_flag = false;
      for (int k = 0; k < 40; k++) {
        if (cnt[k] != 0) {
          if (cnt[k] % j != 0) out_flag = true;
        }
      }
      if (!out_flag) ans.push_back(j);
    }
    for (int j = 0; j < ans.size(); j++) {
      cout << ans[j];
      if (j != ans.size() - 1)
        cout << " ";
      else
        cout << "\n";
    }
  }
  return 0;
}
