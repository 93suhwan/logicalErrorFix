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
    int mx = 0, mn = INT_MAX;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      mx = max(v[i], mx);
      mn = min(v[i], mn);
    }
    int cntn = 0, cntx = 0;
    for (int i = 0; i < n; i++) {
      if (v[i] == mn) {
        cntn++;
      }
      if (v[i] == mx) {
        cntx++;
      }
    }
    if (cntx == n) {
      cout << "0\n";
      continue;
    }
    if (cntx >= 2 and cntn >= 2) {
      cout << "1\n";
      continue;
    }
    if (cntn > cntx) {
      if (v.back() == mx) {
        cout << "0\n";
        continue;
      } else {
        cout << "1\n";
        continue;
      }
    } else if (cntx > cntn) {
      if (v.front() == mn) {
        cout << "0\n";
        continue;
      } else {
        cout << "1\n";
        continue;
      }
    } else {
      if (v.front() == mx and v.back() == mn) {
        cout << "2\n";
        continue;
      } else if (v.back() == mx and v.front() == mn) {
        cout << "0\n";
        continue;
      } else {
        cout << "1\n";
        continue;
      }
    }
  }
  return 0;
}
