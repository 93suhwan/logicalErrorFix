#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
typedef struct {
  int n;
  vector<pair<int, long long> > a[N];
  set<int> s[N];
} Matrix;
const int mod = 1e9 + 7, inv100 = 570000004;
int x[N], y[N], pos[N];
set<tuple<int, int, int, int> > s;
Matrix a;
inline long long quick_pow(long long x, long long p, long long mod) {
  long long ans = 1;
  while (p) {
    if (p & 1) ans = ans * x % mod;
    x = x * x % mod;
    p >>= 1;
  }
  return ans;
}
inline vector<pair<int, long long> >::iterator get_pointer1(Matrix &a, int x,
                                                            int y) {
  return lower_bound(a.a[x].begin(), a.a[x].end(), make_pair(y, 0ll));
}
inline vector<pair<int, long long> >::iterator get_pointer2(Matrix &a, int x,
                                                            int y) {
  vector<pair<int, long long> >::iterator ans =
      lower_bound(a.a[x].begin(), a.a[x].end(), make_pair(y, 0ll));
  if (ans == a.a[x].end() || ans->first != y) {
    ans = a.a[x].insert(
        lower_bound(a.a[x].begin(), a.a[x].end(), make_pair(y, 0ll)),
        make_pair(y, 0ll));
    a.s[y].insert(x);
  }
  return ans;
}
inline bool gauss(Matrix &a, int mod) {
  int ni = a.n + 1;
  for (register int i = 1; i <= a.n; i++) {
    long long cur_inv;
    vector<pair<int, long long> >::iterator it1 = get_pointer1(a, i, i);
    if (it1->second == 0) {
      int t = i;
      for (register int j = i + 1; j <= a.n; j++) {
        vector<pair<int, long long> >::iterator it2 = get_pointer1(a, j, i);
        if (it2 == a.a[j].end()) break;
        j = it2->first;
        if (it2->second != 0) {
          t = j;
          break;
        }
      }
      if (i == t) return false;
      swap(a.a[i], a.a[t]);
      it1 = get_pointer1(a, i, i);
    }
    cur_inv = quick_pow(it1->second, mod - 2, mod);
    for (register int j = i + 1; j <= a.n; j++) {
      set<int>::iterator it2 = a.s[i].lower_bound(j);
      if (it2 == a.s[i].end()) break;
      vector<pair<int, long long> >::iterator it3;
      j = *it2;
      it3 = get_pointer1(a, j, i);
      if (it3 == a.a[j].end()) break;
      if (it3->second == 0) continue;
      long long t = cur_inv * it3->second % mod;
      for (register int k = i; k <= ni; k++) {
        vector<pair<int, long long> >::iterator it4 = get_pointer1(a, i, k);
        if (it4 == a.a[i].end()) break;
        k = it4->first;
        if (it4->second == 0) continue;
        vector<pair<int, long long> >::iterator it5 = get_pointer2(a, j, k);
        it5->second = ((it5->second - t * it4->second % mod) % mod + mod) % mod;
      }
    }
  }
  for (register int i = a.n; i >= 1; i--) {
    vector<pair<int, long long> >::iterator it1 = get_pointer1(a, i, ni);
    for (register int j = i + 1; j <= a.n; j++) {
      vector<pair<int, long long> >::iterator it2 = get_pointer1(a, i, j);
      if (it2 == a.a[i].end()) break;
      j = it2->first;
      it1->second =
          ((it1->second - it2->second * get_pointer1(a, j, ni)->second % mod) %
               mod +
           mod) %
          mod;
    }
    it1->second = it1->second *
                  quick_pow(get_pointer1(a, i, i)->second, mod - 2, mod) % mod;
  }
  return true;
}
int main() {
  int t;
  cin >> t;
  for (register int i = 1; i <= t; i++) {
    int n, m, rb, cb, rd, cd, p, dr = 1, dc = 1, loop = 0, cnt = 0, cnt_i;
    long long prob;
    cin >> n >> m >> rb >> cb >> rd >> cd >> p;
    prob = (long long)(100 - p) * inv100 % mod;
    s.clear();
    while (true) {
      tuple<int, int, int, int> tp;
      if (rb + dr < 1 || rb + dr > n) dr = -dr;
      if (cb + dc < 1 || cb + dc > m) dc = -dc;
      loop++;
      x[loop] = rb;
      y[loop] = cb;
      rb += dr;
      cb += dc;
      tp = make_tuple(rb, cb, dr, dc);
      if (s.count(tp)) {
        loop--;
        break;
      }
      s.insert(tp);
    }
    for (register int j = 1; j <= loop; j++) {
      if (x[j] == rd || y[j] == cd) pos[++cnt] = j;
    }
    a.n = cnt;
    for (register int j = 1; j <= cnt; j++) {
      a.a[j].clear();
    }
    cnt_i = cnt + 1;
    for (register int j = 1; j <= cnt_i; j++) {
      a.s[j].clear();
    }
    for (register int i = 1; i <= cnt; i++) {
      int pre = i == 1 ? cnt : i - 1,
          dis = i == 1 ? loop - pos[cnt] + pos[i] : pos[i] - pos[pre];
      vector<pair<int, long long> >::iterator it;
      get_pointer2(a, i, pre)->second = 1;
      it = get_pointer2(a, i, i);
      it->second = ((it->second - prob) % mod + mod) % mod;
      get_pointer2(a, i, cnt_i)->second = (long long)prob * dis % mod;
    }
    gauss(a, mod);
    cout << (get_pointer1(a, 1, cnt_i)->second + pos[1] - 1) % mod << endl;
  }
  return 0;
}
