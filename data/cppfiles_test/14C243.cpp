#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> vec(n);
  vector<long long int> vec1;
  for (long long int i = 0; i < n; i++) {
    cin >> vec[i];
    vec1.push_back(vec[i]);
  }
  sort(vec1.begin(), vec1.end());
  long long int count = 0;
  vector<pair<long long int, long long int>> ans;
  for (long long int i = 0; i < n; i++) {
    long long int pos;
    long long int temp = 0;
    for (long long int j = i; j < n; j++) {
      if (vec1[i] == vec[j] && temp == 0) {
        pos = j;
        if (i != pos) ans.push_back({i, pos});
        temp = 1;
      }
      if (temp == 1) {
        long long int flag = vec[pos];
        for (long long int k = pos; k > i; k--) {
          vec[k] = vec[k - 1];
        }
        vec[i] = flag;
        break;
      }
    }
  }
  cout << ans.size() << "\n";
  for (long long int i = 0; i < ans.size(); i++) {
    cout << ans[i].first + 1 << " " << ans[i].second + 1 << " "
         << ans[i].second - ans[i].first << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t > 0) {
    solve();
    --t;
  }
  return 0;
}
