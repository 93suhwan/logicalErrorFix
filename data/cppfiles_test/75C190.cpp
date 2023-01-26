#include <bits/stdc++.h>
using namespace std;
bool cond(vector<long long int> a, vector<long long int> b) {
  long long int mn1 = a[0];
  for (int i = 0; i < a.size(); i++) {
    mn1 = max(mn1, a[i] - i);
  }
  long long int mn2 = b[0];
  for (int i = 0; i < b.size(); i++) {
    mn2 = max(mn2, b[i] - i);
  }
  return mn1 < mn2;
}
void solve() {
  int n;
  cin >> n;
  vector<vector<long long int>> arr(n);
  for (int i = 0; i < n; i++) {
    long long int m;
    cin >> m;
    vector<long long int> v(m);
    long long int sum = 0;
    for (int j = 0; j < m; j++) {
      cin >> v[j];
      sum += v[j];
    }
    arr[i] = v;
  }
  sort(arr.begin(), arr.end(), cond);
  long long int ans = 0;
  long long int cnt = 0;
  for (int i = 0; i < n; i++) {
    vector<long long int> a = arr[i];
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
