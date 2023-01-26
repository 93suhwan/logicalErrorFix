#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t, n;
int check(int mid, pair<int, int> *s) {
  for (int i = 1; i <= n; i++) {
    mid += s[i - 1].second;
    if (mid <= s[i].first) return 0;
  }
  return 1;
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    pair<int, int> s[n + 1];
    for (int i = 1; i <= n; i++) {
      cin >> s[i].second;
      for (int j = 0; j < s[i].second; j++) {
        int x;
        cin >> x;
        x -= j;
        s[i].first = max(s[i].first, x);
      }
    }
    sort(s + 1, s + n + 1);
    int l = s[1].first, r = 1e9 + 10;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (check(mid, s))
        r = mid;
      else
        l = mid + 1;
    }
    cout << l << endl;
  }
  return 0;
}
