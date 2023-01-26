#include <bits/stdc++.h>
using namespace std;
const long long maxN = 100001;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) cin >> a[i];
    string s;
    cin >> s;
    bool flag = 1;
    multiset<long long> b, r;
    for (long long i = 0; i < n; i++) {
      if (s[i] == 'B') {
        b.insert(a[i]);
      } else {
        r.insert(a[i]);
      }
    }
    for (long long i = 1; i <= n; i++) {
      long long tar = i;
      if (b.size()) {
        auto it = b.lower_bound(tar);
        if (it != b.end()) {
          b.erase(it);
        } else {
          if (r.size()) {
            auto it = r.begin();
            if ((*it) > tar) {
              flag = 0;
              break;
            }
            r.erase(it);
          } else {
            flag = 0;
            break;
          }
        }
      } else {
        if (r.size()) {
          auto it = r.begin();
          if ((*it) > tar) {
            flag = 0;
            break;
          }
          r.erase(it);
        } else {
          flag = 0;
          break;
        }
      }
    }
    if (flag) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    cout << "\n";
  }
}
