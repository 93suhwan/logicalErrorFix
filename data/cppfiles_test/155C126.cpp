#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i], a[i]--;
  string s;
  cin >> s;
  int allbad = count(s.begin(), s.end(), '0');
  set<int> bad, good;
  for (int i = 0; i < allbad; i++) bad.insert(i);
  for (int i = allbad; i < n; i++) good.insert(i);
  for (int i = 0; i < n; i++) {
    if (s[i] - '0') {
      int mn = 1e9;
      auto it = good.lower_bound(a[i]);
      if (it != good.end()) {
        mn = min(mn, abs(*it - a[i]));
      }
      if (it != good.begin()) {
        it--;
        if (abs(*it - a[i]) <= mn) {
          cout << *it + 1 << ' ';
          good.erase(it);
        } else {
          it++;
          cout << *it + 1 << ' ';
          good.erase(it);
        }
      } else {
        cout << *it + 1 << ' ';
        good.erase(it);
      }
    } else {
      int mn = 1e9;
      auto it = bad.lower_bound(a[i]);
      if (it != bad.end()) {
        mn = min(mn, abs(*it - a[i]));
      }
      if (it != bad.begin()) {
        it--;
        if (abs(*it - a[i]) <= mn) {
          cout << *it + 1 << ' ';
          bad.erase(it);
        } else {
          it++;
          cout << *it + 1 << ' ';
          bad.erase(it);
        }
      } else {
        cout << *it + 1 << ' ';
        bad.erase(it);
      }
    }
  }
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
