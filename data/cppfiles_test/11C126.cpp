#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int cnt[MAXN][30];
vector<int> v;
int t, n;
bool op(int x, int y) { return x > y; }
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    string s;
    for (int i = 1; i <= n; i++) {
      cin >> s;
      for (int j = 0; j < 26; j++) cnt[i][j] = 0;
      int len = s.size();
      for (int j = 0; j < len; j++) {
        cnt[i][s[j] - 'a']++;
      }
      cnt[i][26] = len;
    }
    int ans = 0;
    for (int p = 0; p < 26; p++) {
      for (int i = 1; i <= n; i++) {
        v.push_back(cnt[i][p] * 2 - cnt[i][26]);
      }
      sort(v.begin(), v.end(), op);
      int res = 0;
      int i;
      for (i = 0; i < v.size(); i++) {
        if (res + v[i] > 0) {
          res += v[i];
        } else {
          break;
        }
      }
      ans = max(ans, i);
      v.clear();
    }
    printf("%d\n", ans);
  }
  return 0;
}
