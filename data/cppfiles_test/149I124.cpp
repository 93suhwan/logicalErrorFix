#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7, inf = 2e9 + 9, mod = 1e9 + 7;
int n, k, x, d[maxn];
void solve() {
  vector<int> a;
  char s[maxn], dum[maxn];
  scanf("%d%d%d", &n, &k, &x);
  memset(d, 0, (n + 3) * sizeof(int));
  scanf("%s", &dum);
  int l = 0;
  for (int i = 0; i < n + 1; ++i) {
    if (dum[i] == '*')
      l++;
    else {
      a.push_back(l * k);
      l = 0;
    }
  }
  int sz = a.size();
  long long t = 1;
  for (int i = sz - 1; i >= 0; --i) {
    t = t * (a[i] + 1);
    if (t >= x) {
      x--;
      for (int j = i; j < sz; ++j) {
        t /= a[j] + 1;
        d[j] = x / t;
        x -= d[j] * t;
      }
      break;
    }
  }
  for (int i = 0; i < sz; ++i) {
    for (int j = 0; j < d[i]; ++j) {
      printf("b");
    }
    if (i != sz - 1) printf("a");
  }
  puts("");
}
int main() {
  int test;
  scanf("%d", &test);
  while (test--) solve();
  return 0;
}
