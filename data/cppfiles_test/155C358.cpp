#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
const int mod = 1e9 + 7;
const double eps = 1e-5;
int n;
int a[maxn];
int b[maxn];
int c[maxn];
int ans[maxn];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    string s;
    cin >> s;
    int cntb = 0;
    int cntc = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '0')
        b[cntb++] = a[i];
      else
        c[cntc++] = a[i];
    }
    sort(b, b + cntb);
    sort(c, c + cntc);
    int now = 1;
    for (int i = 0; i < cntb; i++) {
      ans[b[i]] = now++;
    }
    for (int i = 0; i < cntc; i++) {
      ans[c[i]] = now++;
    }
    for (int i = 0; i < n; i++) {
      printf("%d ", ans[a[i]]);
    }
    printf("\n");
  }
  return 0;
}
