#include <bits/stdc++.h>
using namespace std;
const int N = 300000;
char cc[N + 1];
int aa[N];
set<long long> dd;
int query(int l, int r) {
  return l <= r ? aa[r] - (l - 1 >= 0 ? aa[l - 1] : 0) : 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q >> cc;
    for (int i = 0; i < n; i++) {
      int a = cc[i] == '+' ? 1 : -1;
      aa[i] = i % 2 == 0 ? a : -a;
    }
    for (int i = 1; i < n; i++) aa[i] += aa[i - 1];
    dd.clear();
    for (int i = 0; i < n; i++) {
      int p = query(0, i - 1);
      int q = query(i + 1, n - 1);
      int d = p - q;
      dd.insert((long long)(d + n) * n + i);
    }
    while (q--) {
      int l, r;
      cin >> l >> r, l--, r--;
      if (query(l, r) == 0)
        cout << "0\n";
      else {
        if ((r - l + 1) % 2 != 0)
          cout << "1\n";
        else {
          cout << "2\n";
          cout << l + 1 << ' ';
          l++;
        }
        int d = query(0, l - 1) - query(r + 1, n - 1);
        long long x = *dd.lower_bound((long long)(d + n) * n + l);
        int i = x % n;
        cout << i + 1 << '\n';
      }
    }
  }
  return 0;
}
