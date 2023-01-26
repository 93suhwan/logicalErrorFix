#include <bits/stdc++.h>
using namespace std;
void up(long long i, long long x, long long lx, long long rx,
        vector<long long> &tree) {
  if (rx - lx == 1) {
    tree[x]++;
  } else {
    long long helpp = (rx + lx) / 2;
    if (i < helpp) {
      up(i, 2 * x + 1, lx, helpp, tree);
    } else {
      up(i, 2 * x + 2, helpp, rx, tree);
    }
    tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
  }
  return;
}
long long gan(long long x, long long l, long long r, long long lx, long long rx,
              vector<long long> &tree) {
  if (lx >= l and rx <= r) {
    return tree[x];
  } else if (lx >= r or l >= rx) {
    return 0;
  } else {
    long long helpp = (rx + lx) / 2;
    return gan(2 * x + 1, l, r, lx, helpp, tree) +
           gan(2 * x + 2, l, r, helpp, rx, tree);
  }
}
signed main() {
  long long amm;
  cin >> amm;
  while (amm--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> ch(n);
    long long anss = 0;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      a[i]--;
      ch[a[i]]++;
      if (ch[a[i]] > 1) {
        anss = 1;
      }
    }
    if (anss == 1) {
      cout << "YES\n";
    } else {
      long long sz = 1;
      while (sz <= n) {
        sz *= 2;
      }
      vector<long long> st(sz * 2 - 1);
      long long ans = 0;
      for (long long i = 0; i < n; i++) {
        ans += gan(0, a[i] + 1, n, 0, sz, st);
        up(a[i], 0, 0, sz, st);
      }
      if (ans % 2 == 0) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
}
