#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    set<long long> need;
    for (int i = 1; i <= n; i++) {
      need.insert(i);
    }
    vector<long long> rem;
    for (int i = 0; i < n; i++) {
      long long x;
      cin >> x;
      if (need.count(x)) {
        need.erase(x);
      } else
        rem.push_back(x);
    }
    bool f = 0;
    long long ans = 0;
    sort(rem.begin(), rem.end());
    for (int i = 0; i < rem.size(); i++) {
      long long curr = rem[i];
      long long maxp = (curr - 1) / 2;
      auto it = need.begin();
      long long temp = *it;
      if (maxp >= temp) {
        need.erase(temp);
        ans++;
      } else {
        f = 1;
        break;
      }
    }
    if (f == 1)
      cout << -1 << '\n';
    else
      cout << ans << '\n';
  }
  return 0;
}
