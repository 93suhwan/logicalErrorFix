#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    set<long long> s;
    for (int i = 1; i <= n; i++) {
      long long x;
      cin >> x;
      s.insert(x);
    }
    if (n == 1) {
      printf("%lld\n", *(s.begin()));
      continue;
    }
    long long ans = *(s.begin()), cnt = 0;
    while (s.size() > 1) {
      long long minn = *(s.begin());
      s.erase(s.begin());
      cnt += minn;
      ans = max(ans, *(s.begin()) - minn);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
