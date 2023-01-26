#include <bits/stdc++.h>
using namespace std;
int n, a[200015];
char s[200015];
vector<pair<int, int> > ans;
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (n); i++) scanf("%d", &a[i]);
  scanf("%s", s + 1);
  sort(a + 1, a + n + 1);
  int lp = 1, rp = n;
  for (int i = (1); i <= (n); i++)
    if (i == 1 || s[i] != s[i - 1]) rp--;
  lp = rp++;
  bool flag = 0;
  for (int l = 1, r; l <= n; l = r + 1) {
    r = l;
    while (r < n && s[r + 1] == s[l]) r++;
    int len = r - l + 1;
    ans.push_back(make_pair(a[rp++], s[l] == 'R'));
    for (int _ = (1); _ <= (len - 1); _++) {
      ans.push_back(make_pair(a[lp--], (s[1] == 'L') ^ flag));
      flag ^= 1;
    }
  }
  for (auto x : ans) {
    printf("%d %c\n", x.first, x.second == 0 ? 'L' : 'R');
  }
  return 0;
}
