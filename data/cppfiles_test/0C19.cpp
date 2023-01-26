#include <bits/stdc++.h>
using namespace std;
struct node {
  string ss;
  int i;
} s[1000009];
int cmp(node x, node y) { return x.ss < y.ss; }
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> s[i].ss;
    s[i].ss = ' ' + s[i].ss;
    s[i].i = i + 1;
    for (int j = 1; j <= m; ++j) {
      if (j % 2 == 0) {
        s[i].ss[j] = 'Z' - s[i].ss[j] + 'A';
      }
    }
  }
  sort(s, s + n, cmp);
  for (int i = 0; i < n; ++i) {
    cout << s[i].i << " ";
  }
}
