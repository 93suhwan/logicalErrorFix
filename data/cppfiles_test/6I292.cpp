#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<set<long long>> s(n + 1);
  set<long long> ans;
  for (long long i = 0, x, y; i < m; i++) {
    cin >> x >> y;
    s[x].insert(y);
    s[y].insert(x);
    if (*s[x].rbegin() < x) {
      ans.insert(x);
    } else {
      if (ans.find(x) != ans.end()) ans.erase(x);
    }
    if (*s[y].rbegin() < y) {
      ans.insert(y);
    } else {
      if (ans.find(y) != ans.end()) ans.erase(y);
    }
  }
  int q;
  cin >> q;
  while (q--) {
    long long type;
    cin >> type;
    if (type == 1) {
      int x, y;
      cin >> x >> y;
      s[x].insert(y);
      s[y].insert(x);
      if (*s[x].rbegin() < x) {
        ans.insert(x);
      } else {
        if (ans.find(x) != ans.end()) ans.erase(x);
      }
      if (*s[y].rbegin() < y) {
        ans.insert(y);
      } else {
        if (ans.find(y) != ans.end()) ans.erase(y);
      }
    } else if (type == 2) {
      int x, y;
      cin >> x >> y;
      s[x].erase(y);
      s[y].erase(x);
      if (*s[x].rbegin() < x) {
        ans.insert(x);
      } else {
        if (ans.find(x) != ans.end()) ans.erase(x);
      }
      if (*s[y].rbegin() < y) {
        ans.insert(y);
      } else {
        if (ans.find(y) != ans.end()) ans.erase(y);
      }
    } else {
      cout << ans.size() << "\n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t = 1;
  for (int i = 1; i < t + 1; i++) {
    solve();
  }
}
