#include <bits/stdc++.h>
using namespace std;
int block;
bool cmp(array<int, 3> first, array<int, 3> second) {
  if (first[0] / block == second[0] / block) return first[1] < second[1];
  return (first[0] / block < second[0] / block);
}
int d[2000005];
int ans[2000005];
int s[2000005], first[2000005];
array<int, 3> a[2000005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t-- > 0) {
    int n, q;
    string f;
    cin >> n >> q >> f;
    block = sqrt(n);
    f = ' ' + f;
    for (int i = 1; i <= n; ++i) {
      int u = (f[i] == '+') ? 1 : -1;
      s[i] = s[i - 1];
      if (i % 2)
        s[i] += u, first[i] = u;
      else
        s[i] -= u, first[i] = -u;
    }
    while (q-- > 0) {
      int l, r;
      cin >> l >> r;
      int m = s[r] - s[l - 1];
      if (m == 0)
        cout << 0 << endl;
      else if (m % 2)
        cout << 1 << endl;
      else
        cout << 2 << endl;
    }
  }
}
