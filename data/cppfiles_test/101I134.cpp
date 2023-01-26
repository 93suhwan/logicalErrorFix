#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
long long a[300010];
long long h[300010];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (long long i = 0; i < (long long)n; ++i) {
      cin >> a[i];
    }
    string s;
    cin >> s;
    vector<int> r, b;
    for (long long i = 0; i < (long long)n; ++i) {
      if (s[i] == 'R')
        r.push_back(a[i]);
      else
        b.push_back(a[i]);
    }
    sort(r.begin(), r.end(), greater<int>());
    sort(b.begin(), b.end());
    if (r.size()) {
      int p = 0;
      for (int i = n; i; --i) {
        if (r[p] <= i) {
          h[i] = 1;
        }
        if (++p >= r.size()) break;
      }
    }
    if (b.size()) {
      int p = 0;
      for (int i = 1; i <= n; ++i) {
        if (b[p] >= i) {
          h[i] = 1;
        }
        if (++p >= b.size()) break;
      }
    }
    int flag = 1;
    for (long long i = 1; i <= (long long)n; ++i) {
      if (!h[i]) {
        flag = 0;
        break;
      }
      h[i] = 0;
    }
    if (flag) {
      printf("YES\n");
    } else
      printf("NO\n");
  }
  return 0;
}
