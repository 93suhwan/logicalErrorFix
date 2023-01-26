#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> v(n);
    for (auto &c : v) {
      cin >> c;
    }
    string s;
    cin >> s;
    multiset<long long int> B;
    multiset<long long int> R;
    bool ans = true;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'R') {
        R.insert(v[i]);
        if (v[i] > n) {
          ans = false;
          break;
        }
      } else {
        B.insert(v[i]);
        if (v[i] < 1) {
          ans = false;
          break;
        }
      }
    }
    if (!ans) {
      cout << "NO" << endl;
      continue;
    }
    for (int i = 1; i <= n; i++) {
      if (!B.empty()) {
        auto c = *(B.begin());
        B.erase(B.begin());
        if (c < i) {
          ans = false;
          break;
        }
      } else {
        auto c = *(R.begin());
        R.erase(R.begin());
        if (c > i) {
          ans = false;
          break;
        }
      }
    }
    if (ans) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
