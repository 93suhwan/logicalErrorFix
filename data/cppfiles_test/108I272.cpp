#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, i, a, b;
  vector<long long int> v1, v2;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a;
    v1.push_back(a);
  }
  for (i = 0; i < n; i++) {
    cin >> a;
    v2.push_back(a);
  }
  if (*max_element(v1.begin(), v1.end()) !=
      *max_element(v2.begin(), v2.end())) {
    for (i = 0; i < n; i++) {
      cout << 1;
    }
    cout << endl;
  } else {
    auto it = max_element(v1.begin(), v1.end());
    a = it - v1.begin();
    auto it1 = max_element(v2.begin(), v2.end());
    b = it1 - v2.begin();
    for (i = 0; i < n; i++) {
      if (i == a || i == b) {
        cout << 1;
      } else
        cout << 0;
    }
    cout << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
