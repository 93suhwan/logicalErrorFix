#include <bits/stdc++.h>
using namespace std;
void fun() {
  int_fast32_t n;
  cin >> n;
  vector<int_fast32_t> a(n);
  for (int_fast32_t i = 0; i < n; ++i) cin >> a[i];
  string s;
  cin >> s;
  vector<int_fast32_t> bl, red;
  for (int_fast32_t i = 0; i < n; ++i) {
    if (s[i] == 'B')
      bl.push_back(a[i]);
    else
      red.push_back(a[i]);
  }
  int_fast32_t l = bl.size(), r = red.size();
  sort(bl.begin(), bl.end());
  for (int_fast32_t i = 0; i < l; ++i) {
    if (bl[i] < (i + 1)) {
      cout << "NO" << '\n';
      return;
    }
  }
  sort(red.begin(), red.end());
  for (int_fast32_t i = 0; i < r; ++i) {
    if (red[i] > (i + 1 + l)) {
      cout << "NO" << '\n';
      return;
    }
  }
  cout << "YES" << '\n';
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int_fast32_t t;
  cin >> t;
  ++t;
  while (--t) fun();
}
