#include <bits/stdc++.h>
using namespace std;
void speed_up() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int binpow(int a, int n) {
  if (n == 0) {
    return 1;
  }
  if (n % 2 == 1) {
    return a * binpow(a, n - 1);
  } else {
    int b = binpow(a, n / 2);
    return b * b;
  }
}
signed main() {
  speed_up();
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> s(k);
    for (int i = 0; i < k; ++i) {
      cin >> s[i].first >> s[i].second;
    }
    vector<int> used(2 * n + 1);
    for (auto x : s) {
      used[x.first] = x.second;
      used[x.second] = x.first;
    }
    vector<int> kek;
    for (int i = 1; i <= 2 * n; ++i) {
      if (used[i]) continue;
      kek.push_back(i);
    }
    int sz = kek.size();
    int l = 0, r = sz / 2;
    while (r != sz) {
      used[kek[l]] = kek[r];
      used[kek[r]] = kek[l];
      s.push_back({min(kek[l], kek[r]), max(kek[l], kek[r])});
      l++, r++;
    }
    for (auto x : s) {
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
      pair<int, int> now = {min(s[i].first, s[i].second),
                            max(s[i].first, s[i].second)};
      for (int j = 0; j < n; ++j) {
        if (i == j) continue;
        pair<int, int> now2 = {min(s[j].first, s[j].second),
                               max(s[j].first, s[j].second)};
        vector<pair<int, int>> all = {
            {now.first, i}, {now.second, i}, {now2.first, j}, {now2.second, j}};
        sort(all.begin(), all.end());
        bool fl = 1;
        for (int k = 0; k < 3; ++k) {
          if (all[k].second == all[k + 1].second) {
            fl = 0;
            break;
          }
        }
        if (fl) {
          res++;
        }
      }
    }
    cout << res / 2 << "\n";
  }
}
