#include <bits/stdc++.h>
using namespace std;
int t, n;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    set<int> se;
    vector<int> a, b;
    for (int x, i = 1; i <= n; i++) {
      scanf("%d", &x);
      if (se.count(x) || x > n)
        a.push_back(x);
      else
        se.insert(x);
    }
    for (int i = 1; i <= n; i++)
      if (!se.count(i)) b.push_back(i);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    bool flag = true;
    int ans = a.size();
    for (int i = 0; i < ans; i++)
      if (a[i] <= 2 * b[i]) flag = false;
    flag ? printf("%d\n", ans) : puts("-1");
  }
  return 0;
}
