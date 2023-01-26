#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int _;
  cin >> _;
  while (_--) {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int> > v(k);
    vector<int> used(2 * n, 0);
    for (auto& pa : v) cin >> pa.first >> pa.second, pa.first--, pa.second--;
    for (auto pa : v) used[pa.first] = used[pa.second] = 1;
    vector<int> unused;
    for (int i = 0; i < 2 * n; i++)
      if (!used[i]) unused.push_back(i);
    for (int i = 0; 2 * i < unused.size(); i++)
      v.push_back({unused[i], unused[unused.size() / 2 + i]});
    int ans = 0;
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++) {
        auto pa1 = v[i];
        auto pa2 = v[j];
        if (pa1.first > pa1.second) swap(pa1.first, pa1.second);
        if (pa2.first > pa2.second) swap(pa2.first, pa2.second);
        if (pa1 > pa2) swap(pa1, pa2);
        if ((pa2.second > pa1.second) and (pa2.first < pa1.second)) ans++;
      }
    cout << ans << "\n";
  }
}
