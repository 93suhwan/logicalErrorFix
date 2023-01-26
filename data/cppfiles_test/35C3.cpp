#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
long long n, a[N], s[N], ans;
vector<long long> v[N], p[N];
char str[N];
void pre() {
  for (long long i = 2; i < N; i++) {
    if (v[i].empty()) {
      for (long long j = i; j < N; j *= i) {
        for (long long k = j; k < N; k += j) {
          v[k].push_back(i);
        }
      }
    }
  }
}
bool ok(int j) {
  if (s[0]) {
    if (p[j].empty()) return true;
    if (p[j].back() < s[s[0]]) return true;
  }
  return false;
}
int main() {
  pre();
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  scanf("%s", str + 1);
  for (int i = 1; i <= n; i++) {
    s[++s[0]] = i;
    for (auto &j : v[a[i]]) {
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
  return 0;
}
