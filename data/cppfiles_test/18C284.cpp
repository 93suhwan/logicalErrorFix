#include <bits/stdc++.h>
using namespace std;
bool intersect(pair<int, int> c, pair<int, int> d) {
  if (c.first > d.first) swap(c, d);
  return c.second > d.first and c.second < d.second;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> chords;
    vector<bool> used(2 * n + 1, false);
    for (int i = 1; i <= k; i++) {
      int x, y;
      cin >> x >> y;
      if (x > y) swap(x, y);
      chords.push_back(make_pair(x, y));
      used[x] = used[y] = true;
    }
    vector<int> unused;
    for (int i = 1; i <= 2 * n; i++)
      if (!used[i]) unused.push_back(i);
    for (int i = 0; i < n - k; i++)
      chords.push_back(make_pair(unused[i], unused[i + n - k]));
    int ans = 0;
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++) ans += intersect(chords[i], chords[j]);
    cout << ans << endl;
  }
  return 0;
}
