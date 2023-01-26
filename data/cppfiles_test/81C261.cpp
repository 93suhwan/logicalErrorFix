#include <bits/stdc++.h>
using namespace std;
int t;
const int maxn = 3e5 + 6;
char e[maxn];
int a[maxn];
int s[maxn];
int n;
int q;
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> q;
    cin >> e + 1;
    for (int i = 1; i <= n; i++) {
      int flag = 1;
      if (i & 1) flag = -1;
      if (e[i] == '+')
        a[i] = 1;
      else
        a[i] = -1;
      s[i] = s[i - 1] + flag * a[i];
    }
    while (q--) {
      int l, r;
      cin >> l >> r;
      int sum = s[r] - s[l - 1];
      if (sum == 0) {
        cout << 0 << endl;
        continue;
      }
      if (sum & 1)
        cout << 1 << endl;
      else
        cout << 2 << endl;
    }
  }
  return 0;
}
