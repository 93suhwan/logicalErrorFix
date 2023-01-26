#include <bits/stdc++.h>
using namespace std;
const int N = 25000000 + 10;
string s, str;
map<string, int> mp;
set<string> Set;
int a[N], b[N];
void solve() {
  mp.clear();
  Set.clear();
  int n;
  s = " ";
  cin >> n >> str;
  s += str;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n - i + 1; j++) {
      str = s.substr(i, j);
      Set.insert(str);
    }
  }
  int idx = 0;
  for (auto str : Set) {
    mp[str] = ++idx;
  }
  idx = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n - i + 1; j++) {
      str = s.substr(i, j);
      a[++idx] = mp[str];
    }
  }
  int len = 0;
  for (int i = 1; i <= idx; i++) {
    int l = 1, r = len;
    int pos = 0;
    while (l <= r) {
      int mid = l + r >> 1;
      if (a[i] < b[mid]) {
        pos = mid;
        r = mid - 1;
      } else
        l = mid + 1;
    }
    if (!pos)
      b[++len] = a[i];
    else
      b[pos] = a[i];
  }
  printf("%d\n", len);
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
