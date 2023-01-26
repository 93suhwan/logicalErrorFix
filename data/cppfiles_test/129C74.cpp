#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    multiset<int> rem;
    for (auto& c : a) {
      int x;
      cin >> x;
      c = x;
      rem.insert(x);
    }
    sort((a).begin(), (a).end());
    int ans = 0;
    bool worked = true;
    for (int i = n; i >= 1; i--) {
      auto exists = rem.find(i);
      if (exists != rem.end()) {
        rem.erase(exists);
      } else {
        auto best = rem.upper_bound(i * 2);
        if (best == rem.end()) {
          worked = false;
          break;
        } else {
          rem.erase(best);
          ans++;
        }
      }
    }
    if (worked)
      cout << ans << '\n';
    else
      cout << -1 << '\n';
  }
  return 0;
}
