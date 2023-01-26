#include <bits/stdc++.h>
using namespace std;
int t, n, a[100];
vector<pair<int, int> > ans;
void perform(int l, int r) {
  if (l != r) {
    ans.push_back(make_pair(l, r));
    int ri = a[r];
    for (int i = r; i > l; --i) a[i] = a[i - 1];
    a[l] = ri;
  }
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    ans.clear();
    for (int i = 0; i < n; ++i) {
      int pos = min_element(a + i, a + n) - a;
      perform(i, pos);
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < (int)ans.size(); ++i)
      printf("%d %d %d\n", ans[i].first + 1, ans[i].second + 1,
             ans[i].second - ans[i].first);
  }
  return 0;
}
