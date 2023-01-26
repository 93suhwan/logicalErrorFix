#include <bits/stdc++.h>
using namespace std;
const int nax = 1e5 + 5;
int T, n, k, a[nax], b[nax];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;
  while (T--) {
    cin >> n >> k;
    map<int, int> mp;
    for (int i = 0; i < n; i += 1) {
      cin >> a[i];
      mp[a[i]] = i;
      b[i] = a[i];
    }
    sort(b, b + n);
    int cnt = 0;
    for (int i = 0; i < n;) {
      int pos = mp[b[i]];
      while (i < n && pos < n && a[pos] == b[i]) ++i, ++pos;
      ++cnt;
    }
    cout << (cnt <= k ? "Yes" : "No") << endl;
  }
  return 0;
}
