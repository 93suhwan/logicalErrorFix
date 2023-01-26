#include <bits/stdc++.h>
using namespace std;
const long long INF = 9223372036854775807LL;
const long long SMALL_INF = 2009000999;
const long long NSIZE = 2 * 1e+5 + 1000;
const long long MOD = 998244353;
const long double EPS = 1e-12;
const long long MAX = 1e+6 + 1000;
const long double PI = atan(1) * 4;
bool checkPlusPos(char sym, int pos) {
  if (sym == '+') {
    return !(pos % 2);
  } else {
    return pos % 2;
  }
}
int getPlusCnt(int init_l, int l, int r, vector<int> &p) {
  if (init_l % 2 == 0) {
    return l == 0 ? p[r] : p[r] - p[l - 1];
  } else {
    return l == 0 ? (r - l + 1) - p[r] : (r - l + 1) - (p[r] - p[l - 1]);
  }
}
int getMinusCnt(int init_l, int l, int r, vector<int> &p) {
  return (r - l + 1) - getPlusCnt(init_l, l, r, p);
}
int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    string second(n, '?');
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      cin >> second[i];
      p[i] = checkPlusPos(second[i], i);
      if (i > 0) {
        p[i] += p[i - 1];
      }
    }
    while (q--) {
      int segl, segr;
      cin >> segl >> segr;
      segl--;
      segr--;
      int pluspos = getPlusCnt(segl, segl, segr, p);
      int minpos = getMinusCnt(segl, segl, segr, p);
      if (pluspos == minpos) {
        cout << 0 << endl;
        continue;
      }
      vector<int> ans;
      if ((segr - segl + 1) % 2 == 0) {
        ans.push_back(segl + 1);
        segl++;
      }
      pluspos = getPlusCnt(segl, segl, segr, p);
      minpos = getMinusCnt(segl, segl, segr, p);
      int l = segl, r = segr;
      while (l < r) {
        int m = (r + l + 1) / 2;
        if (pluspos > minpos) {
          if (getPlusCnt(segl, m, segr, p) - getMinusCnt(segl, m, segr, p) <
              (pluspos - minpos) / 2 + 1)
            r = m - 1;
          else
            l = m;
        } else {
          if (getMinusCnt(segl, m, segr, p) - getPlusCnt(segl, m, segr, p) <
              (minpos - pluspos) / 2 + 1)
            r = m - 1;
          else
            l = m;
        }
      }
      ans.push_back(l + 1);
      cout << ans.size() << endl;
      for (auto i : ans) cout << i << " ";
      cout << endl;
    }
  }
}
