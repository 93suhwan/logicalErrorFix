#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test;
  cin >> test;
  while (test--) {
    int64_t n;
    cin >> n;
    vector<int64_t> arr(n);
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }
    string s;
    cin >> s;
    bool ok = true;
    vector<int> red, blue;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'B') {
        blue.push_back(arr[i]);
      } else
        red.push_back(arr[i]);
    }
    int ans = n;
    sort(red.rbegin(), red.rend());
    for (auto x : red) {
      if (x <= ans) ans--;
    }
    sort(blue.rbegin(), blue.rend());
    for (auto x : blue) {
      if (x >= ans) {
        ans--;
      }
    }
    if (ans != 0) ok = false;
    if (ok) {
      cout << "YES\n";
    } else
      cout << "NO\n";
  }
  return 0;
}
