#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N], b[N];
map<int, int> mp;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), b[i] = a[i];
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) mp[b[i]] = i;
    int cnt = 0;
    for (int i = 1; i < n; i++) {
      if (mp[a[i]] + 1 == mp[a[i + 1]])
        continue;
      else
        cnt++;
    }
    cnt++;
    if (cnt <= k)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
