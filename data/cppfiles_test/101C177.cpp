#include <bits/stdc++.h>
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
        while (p < r.size() && r[p] > i) ++p;
        if (p == r.size()) break;
        ++p;
        h[i] = 1;
      }
    }
    if (b.size()) {
      int p = 0;
      for (int i = 1; i <= n; ++i) {
        while (p < b.size() && b[p] < i) ++p;
        if (p == b.size()) break;
        ++p;
        h[i] = 1;
      }
    }
    int flag = 1;
    for (long long i = 1; i <= (long long)n; ++i) {
      if (!h[i]) {
        flag = 0;
        break;
      }
    }
    for (long long i = 1; i <= (long long)n; ++i) h[i] = 0;
    if (flag) {
      printf("YES\n");
    } else
      printf("NO\n");
  }
  return 0;
}
