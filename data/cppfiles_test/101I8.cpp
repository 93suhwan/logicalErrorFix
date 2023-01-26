#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> arr(n);
  vector<long long> check(n + 1, 0);
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] >= 1 && arr[i] <= n) check[arr[i]] = 1;
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
  long long id = 1;
  for (long long i = 0; i < blue.size(); i++) {
    while (id <= n) {
      if (check[id] == 0) break;
      id++;
    }
    if (id > n) break;
    if (blue[i] >= id) {
      check[id] = 1;
      id++;
    }
  }
  id = n;
  for (long long i = 0; i < red.size(); i++) {
    while (id >= 1) {
      if (check[id] == 0) break;
      id--;
    }
    if (id < 1) break;
    if (red[i] <= id) {
      check[id] = 1;
      id--;
    }
  }
  for (long long i = 1; i <= n; i++) {
    if (check[i] == 0) {
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
