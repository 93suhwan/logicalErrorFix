#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    const int Z = 1e5 + 10;
    int n, a[Z], mn = 1, k;
    scanf("%d%d", &n, &k);
    map<int, int> mp;
    mp.clear();
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      mp[a[i]] = i;
    }
    sort(a, a + n);
    for (int i = 1; i < n; i++)
      if (mp[a[i]] != mp[a[i - 1]] + 1) ++mn;
    mn <= k ? puts("Yes") : puts("No");
  }
  return 0;
}
