#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  long long int arr[n];
  vector<int> v;
  set<int> s;
  for (int i = 1; i <= n; i++) {
    s.insert(i);
  }
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < n; i++) {
    if (s.count(arr[i])) {
      s.erase(arr[i]);
    } else {
      v.push_back(arr[i]);
    }
  }
  sort(v.begin(), v.end());
  int ans = 0;
  for (int i = 0; i < v.size(); i++) {
    int d = *s.begin();
    int x = (v[i] - 1) / 2;
    if (d > x) {
      cout << "-1" << endl;
      return;
    } else {
      s.erase(*s.begin());
      ans++;
    }
  }
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
