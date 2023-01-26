#include <bits/stdc++.h>
const long long N = 2e5 + 10;
const long long inf = 0x3f3f3f3f3f3f3f3f;
using namespace std;
long long T, casnum;
long long num[N];
signed main() {
  set<long long> ans;
  long long n, q;
  long long m;
  scanf("%lld", &n), scanf("%lld", &m);
  for (long long i = 1; i <= n; i++) {
    num[i] = 0;
    ans.insert(i);
  }
  for (long long i = 1; i <= m; i++) {
    long long a, b;
    scanf("%lld", &a), scanf("%lld", &b);
    if (a > b)
      num[b]++;
    else
      num[a]++;
    if (num[a] != 0)
      ans.erase(a);
    else
      ans.insert(a);
    if (num[b] != 0)
      ans.erase(b);
    else
      ans.insert(b);
  }
  scanf("%lld", &q);
  for (long long i = 1; i <= q; i++) {
    long long t;
    scanf("%lld", &t);
    if (t == 1) {
      long long a, b;
      scanf("%lld", &a), scanf("%lld", &b);
      if (a > b)
        num[b]++;
      else
        num[a]++;
      if (num[a] != 0)
        ans.erase(a);
      else
        ans.insert(a);
      if (num[b] != 0)
        ans.erase(b);
      else
        ans.insert(b);
    } else if (t == 2) {
      long long a, b;
      scanf("%lld", &a), scanf("%lld", &b);
      if (a > b)
        num[b]--;
      else
        num[a]--;
      if (num[a] != 0)
        ans.erase(a);
      else
        ans.insert(a);
      if (num[b] != 0)
        ans.erase(b);
      else
        ans.insert(b);
    } else
      cout << (long long)ans.size() << "\n";
  }
  return 0;
}
