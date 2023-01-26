#include <bits/stdc++.h>
using namespace std;
const long long Max = 1e5 + 1;
void nos() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
long long n, m, k;
void read() { cin >> n >> m >> k; }
void solve() {
  long long highcnt = n - (m * (n / m));
  highcnt *= n / m + 1;
  long long plusonetotal = highcnt * k;
  long long small, smallcnt, big, bigcnt;
  small = plusonetotal / n;
  big = small + 1;
  bigcnt = plusonetotal - small * n;
  smallcnt = n - bigcnt;
  vector<pair<long long, long long> > mp;
  long long i;
  for (i = 1; i <= n; i++) {
    if (bigcnt) {
      bigcnt--;
      mp.push_back({i, big});
    } else
      mp.push_back({i, small});
  }
  while (k--) {
    long long attable = n / m + 1;
    std::vector<long long> mult;
    long long luat = 0;
    vector<pair<long long, long long> > newmp;
    for (auto &it : mp) {
      if (luat < highcnt) {
        luat++;
        mult.push_back(it.first);
        it.second--;
      }
      if (it.second != 0) newmp.push_back(it);
    }
    sort(newmp.begin(), newmp.end(),
         [](pair<long long, long long> p1, pair<long long, long long> p2) {
           return p1.second > p2.second;
         });
    mp = newmp;
    long long bigline = mult.size() / attable;
    long long it = 0;
    vector<long long> fq(n + 1);
    while (bigline--) {
      cout << attable << ' ';
      long long end = it + attable;
      for (; it < end; it++) {
        fq[mult[it]] = 1;
        cout << mult[it] << ' ';
      }
      cout << '\n';
    }
    vector<long long> less;
    for (i = 1; i <= n; i++)
      if (!fq[i]) less.push_back(i);
    attable--;
    long long smallline = less.size() / attable;
    it = 0;
    while (smallline--) {
      cout << attable << ' ';
      long long end = it + attable;
      for (; it < end; it++) {
        cout << less[it] << ' ';
      }
      cout << '\n';
    }
  }
  cout << '\n';
}
void restart() {}
int32_t main() {
  nos();
  long long teste;
  cin >> teste;
  while (teste--) {
    read();
    solve();
    restart();
  }
  return 0;
}
