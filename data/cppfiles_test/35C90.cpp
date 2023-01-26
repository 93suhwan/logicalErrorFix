#include <bits/stdc++.h>
using namespace std;
long long n, a[1000006], s[1000006], ans;
vector<long long> v[1000006], p[1000006];
char str[1000006];
void pre() {
  for (long long i = 2; i < 1000006; i++) {
    if (v[i].empty()) {
      for (long long j = i; j < 1000006; j *= i) {
        for (long long k = j; k < 1000006; k += j) {
          v[k].push_back(i);
        }
      }
    }
  }
}
bool ok(long long j) {
  if (s[0]) {
    if (p[j].empty()) return true;
    if (p[j].back() < s[s[0]]) return true;
  }
  return false;
}
signed main() {
  pre();
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  scanf("%s", str + 1);
  for (long long i = 1; i <= n; i++) {
    s[++s[0]] = i;
    for (auto& j : v[a[i]]) {
      if (str[i] == '*') {
        p[j].push_back(i);
      } else {
        while (ok(j)) {
          s[0]--;
        }
        if (!p[j].empty()) p[j].pop_back();
      }
    }
    ans += s[0];
  }
  printf("%lld\n", ans);
}
