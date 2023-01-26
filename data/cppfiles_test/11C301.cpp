#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e18;
void solve() {
  long long int n;
  cin >> n;
  vector<string> v(n);
  vector<vector<long long int> > arr(5);
  vector<long long int> num(5, 0);
  for (long long int i = 0; i < n; i++) {
    cin >> v[i];
    for (long long int k = 0; k < 5; k++) num[k] = 0;
    for (long long int j = 0; j < v[i].size(); j++) {
      long long int p = v[i][j] - 'a';
      num[p]++;
    }
    for (long long int k = 0; k < 5; k++) {
      arr[k].push_back(2 * num[k] - v[i].size());
    }
  }
  long long int ans = 0;
  for (long long int i = 0; i < 5; i++) {
    long long int nums = 0;
    vector<long long int> bp = arr[i];
    sort(bp.rbegin(), bp.rend());
    long long int sum = bp[0];
    if (sum > 0) nums = 1;
    long long int j = 1;
    while (sum > 0 && j < bp.size()) {
      sum += bp[j];
      j++;
      if (sum > 0) nums++;
    }
    ans = max(ans, nums);
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
