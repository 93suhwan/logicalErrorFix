#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
long long k, bas, hval, ans[35], pw[35];
map<long long, long long> poss[35];
void getval(long long tp) {
  long long i, mask, cnt, res, ly;
  vector<long long> v;
  for (mask = 0; mask < (1 << ((1 << (k - 1)) - 1)); mask++) {
    v.clear();
    for (i = 1; i <= (1 << (k - 1)); i++) {
      if (tp == 0) {
        v.push_back(i);
      } else {
        v.push_back(i + (1 << (k - 1)));
      }
    }
    cnt = 0;
    res = 0;
    vector<long long> nv;
    ly = k - 1;
    while (v.size() > 1) {
      nv.clear();
      for (i = 0; i < v.size(); i += 2) {
        if (mask & (1 << cnt)) {
          res = (res + pw[(1 << ly) + 1] * v[i + 1]) % 998244353;
          nv.push_back(v[i]);
        } else {
          res = (res + pw[(1 << ly) + 1] * v[i]) % 998244353;
          nv.push_back(v[i + 1]);
        }
        cnt++;
      }
      ly--;
      v = nv;
    }
    res = (res + pw[2] * v[0]) % 998244353;
    poss[v[0]][res] = 1;
  }
  return;
}
void cons(long long cham, long long val) {
  long long i, mask, cnt, res, ly;
  vector<long long> v;
  for (mask = 0; mask < (1 << ((1 << (k - 1)) - 1)); mask++) {
    v.clear();
    for (i = 1; i <= (1 << (k - 1)); i++) {
      if (cham <= (1 << (k - 1))) {
        v.push_back(i);
      } else {
        v.push_back(i + (1 << (k - 1)));
      }
    }
    cnt = 0;
    res = 0;
    vector<long long> nv;
    ly = k - 1;
    while (v.size() > 1) {
      nv.clear();
      for (i = 0; i < v.size(); i += 2) {
        if (mask & (1 << cnt)) {
          res = (res + pw[(1 << ly) + 1] * v[i + 1]) % 998244353;
          ans[v[i + 1]] = (1 << ly) + 1;
          nv.push_back(v[i]);
        } else {
          res = (res + pw[(1 << ly) + 1] * v[i]) % 998244353;
          ans[v[i]] = (1 << ly) + 1;
          nv.push_back(v[i + 1]);
        }
        cnt++;
      }
      ly--;
      v = nv;
    }
    res = (res + pw[2] * v[0]) % 998244353;
    ans[v[0]] = 2;
    if (v[0] == cham && res == val) {
      return;
    }
  }
  return;
}
int main() {
  long long i, j, l;
  cin >> k >> bas >> hval;
  pw[0] = 1;
  for (i = 1; i < 35; i++) {
    pw[i] = (pw[i - 1] * bas) % 998244353;
  }
  getval(0);
  getval(1);
  for (i = 1; i <= (1 << k); i++) {
    for (map<long long, long long>::iterator it = poss[i].begin();
         it != poss[i].end(); it++) {
      long long nv = ((it->first) + 998244353 - ((i * pw[2]) % 998244353) +
                      ((i * bas) % 998244353)) %
                     998244353;
      for (j = 1; j <= (1 << k); j++) {
        if ((j - 1) / (1 << (k - 1)) != (i - 1) / (1 << (k - 1))) {
          if (poss[j].count((hval + 998244353 - nv) % 998244353)) {
            cons(i, it->first);
            cons(j, (hval + 998244353 - nv) % 998244353);
            ans[i] = 1;
            for (i = 1; i <= (1 << k); i++) {
              cout << ans[i] << " ";
            }
            puts("");
            return 0;
          }
        }
      }
    }
  }
  puts("-1");
  return 0;
}
