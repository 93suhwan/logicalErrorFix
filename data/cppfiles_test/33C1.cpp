#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> mn(513, 1e9), ans;
  int n;
  scanf("%d", &n);
  mn[0] = 0;
  for (int i = 0, x; i < n; i++) {
    scanf("%d", &x);
    for (int j = 0; j < 513; j++)
      if (mn[j] < x) mn[j ^ x] = min(mn[j ^ x], x);
  }
  for (int i = 0; i < 513; i++)
    if (mn[i] != 1e9) ans.push_back(i);
  sort(ans.begin(), ans.end());
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
  return 0;
}
