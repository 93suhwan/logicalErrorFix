#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> arr(n);
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  string s;
  cin >> s;
  vector<long long> blue, red;
  for (long long i = 0; i < n; i++) {
    if (s[i] == 'B') {
      if (arr[i] < 1) {
        cout << "NO" << endl;
        return;
      } else
        blue.push_back(arr[i]);
    } else {
      if (arr[i] > n) {
        cout << "NO" << endl;
        return;
      } else
        red.push_back(arr[i]);
    }
  }
  sort(blue.begin(), blue.end());
  sort(red.rbegin(), red.rend());
  for (long long i = 0; i < blue.size(); i++) {
    if (blue[i] < i + 1) {
      cout << "NO" << endl;
      return;
    }
  }
  for (long long i = 0; i < red.size(); i++) {
    if (red[i] > n - i) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
