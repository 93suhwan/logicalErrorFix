#include <bits/stdc++.h>
using namespace std;
void dfs(long long i, long long v, long long x, long long lx, long long rx,
         vector<long long> &tree) {
  if (rx - lx == 1) {
    tree[x] = v;
    return;
  }
  long long helpp = (lx + rx) / 2;
  if (i < helpp) {
    dfs(i, v, 2 * x + 1, lx, helpp, tree);
  } else {
    dfs(i, v, 2 * x + 2, helpp, rx, tree);
  }
  tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
}
long long summ(long long l, long long r, long long x, long long lx,
               long long rx, vector<long long> &tree) {
  if (l >= rx or lx >= r) {
    return 0;
  }
  if (lx >= l and rx <= r) {
    return tree[x];
  }
  long long helpp = (lx + rx) / 2;
  long long s1 = summ(l, r, 2 * x + 1, lx, helpp, tree);
  long long s2 = summ(l, r, 2 * x + 2, helpp, rx, tree);
  return s1 + s2;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long am;
  cin >> am;
  for (long long qq = 0; qq < am; qq++) {
    long long n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<long long> prev(n + 1);
    long long idd = 0;
    for (auto nw : s) {
      if (idd % 2 == 0) {
        if (s[idd] == '+') {
          prev[idd + 1] = prev[idd] + 1;
        } else {
          prev[idd + 1] = prev[idd] - 1;
        }
      } else {
        if (s[idd] == '+') {
          prev[idd + 1] = prev[idd] - 1;
        } else {
          prev[idd + 1] = prev[idd] + 1;
        }
      }
      idd++;
    }
    for (long long tt = 0; tt < q; tt++) {
      long long l, r;
      cin >> l >> r;
      l--;
      r--;
      long long su = prev[r + 1] - prev[l];
      if (su == 0) {
        cout << 0 << "\n";
      } else if ((r - l + 1) % 2 == 1) {
        cout << 1 << "\n";
      } else {
        cout << 2 << "\n";
      }
    }
  }
}
