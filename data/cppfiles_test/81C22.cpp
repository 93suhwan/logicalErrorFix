#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, d;
pair<int, int> p[N];
inline bool cmp(pair<int, int> a, pair<int, int> b) {
  if (max(a.first, a.second) != max(b.first, b.second))
    return max(a.first, a.second) < max(b.first, b.second);
  return a.first < b.first;
}
int main() {
  cin >> n >> d;
  for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
  sort(p, p + n, cmp);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (p[i].first >= d) ans++, d = max(d, p[i].second);
  }
  cout << ans << "\n";
  return 0;
}
