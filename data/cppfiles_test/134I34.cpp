#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long test_case;
  cin >> test_case;
  while (test_case--) {
    long long n;
    cin >> n;
    vector<long long> v(n);
    bool p = true;
    for (long long i = 0; i < n; i++) {
      cin >> v[i];
      if (i > 0 && v[i] == v[i - 1]) {
        p = false;
      }
    }
    if (!p) {
      cout << 0 << "\n";
      continue;
    }
    long long m1 = v[0], m2 = v[1];
    for (long long i = 2; i < n; i++) {
      if (i % 2 == 0)
        m1 = min(m1, v[i]);
      else
        m2 = min(m2, v[i]);
    }
    vector<long long> t;
    t.push_back(m1);
    t.push_back(m2);
    long long ans = 0;
    for (auto it : t) {
      bool ok = true;
      bool flag = (v[0] % it);
      for (long long i = 1; i < n; i++) {
        if (v[i] % it == 0 && flag == 1) {
          flag = 0;
        } else if (v[i] % it && flag == 0) {
          flag = 1;
        } else {
          ok = false;
          break;
        }
      }
      if (ok) {
        ans = it;
        break;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
