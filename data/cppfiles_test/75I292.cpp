#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<pair<long long int, vector<long long int> > > arr(n);
  for (int i = 0; i < n; i++) {
    long long int m;
    cin >> m;
    vector<long long int> v(m);
    long long int sum = 0;
    for (int j = 0; j < m; j++) {
      cin >> v[j];
      sum += v[j];
    }
    arr[i] = {sum, v};
  }
  sort(arr.begin(), arr.end());
  long long int ans = 0;
  long long int cnt = 0;
  for (int i = 0; i < n; i++) {
    vector<long long int> a = arr[i].second;
    for (int j = 0; j < a.size(); j++) {
      if (a[j] - cnt > ans) {
        ans = a[j] - cnt;
      }
      cnt++;
    }
  }
  cout << ans + 1 << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
