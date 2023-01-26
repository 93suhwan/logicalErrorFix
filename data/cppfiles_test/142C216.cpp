#include <bits/stdc++.h>
using namespace std;
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
template <class T>
void in(T& x) {
  cin >> x;
}
template <class H, class... T>
void in(H& h, T&... t) {
  in(h);
  in(t...);
}
bool avail(long long int shops, long long int person, long long int joy,
           vector<vector<long long int> >& v) {
  long long int used[person];
  memset(used, 0, sizeof(used));
  long long int get = 0;
  bool two_gift = false;
  for (long long int i = 0; i < shops; ++i) {
    long long int abovejoy = 0;
    for (long long int j = 0; j < person; ++j) {
      if (v[i][j] >= joy) {
        ++abovejoy;
        if (used[j]) {
          continue;
        } else {
          used[j] = 1;
          ++get;
        }
      }
    }
    if (abovejoy >= 2) {
      two_gift = true;
    }
  }
  return (two_gift && (get == person));
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long int T = 1;
  in(T);
  while (T--) {
    long long int shops, person;
    in(shops, person);
    vector<vector<long long int> > v(shops, vector<long long int>(person, 0));
    for (long long int i = 0; i < shops; ++i) {
      for (long long int j = 0; j < person; ++j) {
        in(v[i][j]);
      }
    }
    long long int l = 0, r = 1e9 + 1;
    long long int m;
    while (l < r - 1) {
      m = (l + r) / 2;
      if (avail(shops, person, m, v)) {
        l = m;
      } else {
        r = m;
      }
    }
    cout << l << '\n';
  }
  return 0;
}
