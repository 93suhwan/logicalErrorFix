#include <bits/stdc++.h>
using namespace std;
const long long maxn = 101010;
bool vis[maxn];
long long n, m;
int main() {
  long long t;
  scanf("%lld", &t);
  for (int testcases = 0; testcases < t; testcases++) {
    scanf("%lld%lld", &n, &m);
    long long a, b, c;
    while (m--) {
      scanf("%lld%lld%lld", &a, &b, &c);
      b--;
      vis[b] = true;
    }
    long long rt = 0;
    for (int i = 0; i < n; i++)
      if (!vis[i]) rt = i;
    for (int i = 0; i < n; i++)
      if (i != rt) printf("%lld %lld\n", i + 1, rt + 1);
  }
  return 0;
}
