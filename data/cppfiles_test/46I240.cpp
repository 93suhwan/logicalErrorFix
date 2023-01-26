#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      mx = max(v[i], mx);
    }
    if (v.back() == mx) {
      cout << "0\n";
    } else if (v.front() == mx) {
      cout << "2\n";
    } else {
      cout << "1\n";
    }
  }
  return 0;
}
