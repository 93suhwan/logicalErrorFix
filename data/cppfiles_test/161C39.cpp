#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    long long num, n;
    cin >> num;
    n = num;
    set<pair<long long, long long>> al;
    vector<pair<long long, long long>> a(n);
    for (long long i = 0; i < n; i++) {
      int l, r;
      cin >> l >> r;
      a[i] = {l, r};
      al.insert({l, r});
    }
    long long ans = -1;
    for (long long i = 0; i < n; i++) {
      long long x = a[i].first;
      long long y = a[i].second;
      for (long long j = x; j <= y; j++) {
        if (x == y) {
          ans = x;
          break;
        } else if (j == x && al.find({x + 1, y}) != al.end()) {
          ans = x;
          break;
        } else if (j == y && al.find({x, y - 1}) != al.end()) {
          ans = y;
          break;
        } else if (al.find({x, j - 1}) != al.end() &&
                   al.find({j + 1, y}) != al.end()) {
          ans = j;
          break;
        }
      }
      cout << x << " " << y << " " << ans << endl;
    }
    cout << endl;
  }
}
