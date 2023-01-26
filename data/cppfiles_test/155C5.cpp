#include <bits/stdc++.h>
const int NN = 2e5 + 2;
using namespace std;
int n, l, h, m;
int t, q[NN], b[NN];
string s;
int a[NN], p[NN];
int main() {
  cin >> t;
  while (t--) {
    h = m = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    cin >> s;
    for (int i = 1; i <= n; i++) {
      if (!(s[i - 1] - '0')) {
        q[++h] = a[i];
      } else {
        b[++m] = a[i];
      }
    }
    sort(q + 1, q + h + 1);
    sort(b + 1, b + m + 1);
    for (int i = 1; i <= h; i++) {
      p[q[i]] = i;
    }
    for (int i = h + 1; i <= m + h; i++) {
      p[b[i - h]] = i;
    }
    for (int i = 1; i <= n; i++) {
      if (i == n)
        printf("%d", p[a[i]]);
      else {
        printf("%d ", p[a[i]]);
      }
    }
    printf("\n");
  }
  return 0;
}
