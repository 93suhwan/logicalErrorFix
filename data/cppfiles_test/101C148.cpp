#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    bool flag = true;
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    string s;
    cin >> s;
    vector<int> b, r;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'R') {
        r.push_back(a[i]);
      } else
        b.push_back(a[i]);
    }
    sort(r.begin(), r.end());
    sort(b.rbegin(), b.rend());
    for (int i = 0; i < r.size(); i++) {
      if (r[i] > n || r.size() - i > n - r[i] + 1) flag = false;
    }
    for (int i = 0; i < b.size(); i++) {
      if (b[i] < 0 || b[i] < b.size() - i) flag = false;
    }
    if (flag)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
