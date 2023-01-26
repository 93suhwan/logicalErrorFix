#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
string s[maxn];
int n, t;
int main() {
  for (scanf("%d", &t); t--;) {
    int ans = 0;
    vector<int> vec[5];
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      cin >> s[i];
      int num[5] = {0};
      for (auto j : s[i]) num[j - 'a']++;
      for (int j = 0; j < 5; ++j)
        vec[j].emplace_back((num[j] << 1) - s[i].size());
    }
    for (int i = 0; i < 5; ++i) {
      sort(vec[i].begin(), vec[i].end());
      reverse(vec[i].begin(), vec[i].end());
      int cnt = 0, now = 0;
      for (auto j : vec[i])
        if (now + j <= 0)
          break;
        else
          ++cnt, now += j;
      ans = max(ans, cnt);
    }
    printf("%d\n", ans);
  }
  return 0;
}
