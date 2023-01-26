#include <bits/stdc++.h>
using namespace std;
void FAST_IO(string filein = "", string fileout = "") {
  if (fopen(filein.c_str(), "r")) {
    freopen(filein.c_str(), "r", stdin);
    freopen(fileout.c_str(), "w", stdout);
  }
  cin.tie(0), cout.tie(0)->sync_with_stdio(0);
}
void Why_Are_You_So_Orz();
signed main() {
  FAST_IO("mike4235orz.inp", "mike4235orz.out");
  int testcases = 1;
  cin >> testcases;
  for (int test = 1; test <= testcases; test++) Why_Are_You_So_Orz();
  return 0;
}
string n;
long long k;
void Why_Are_You_So_Orz() {
  cin >> n >> k;
  while (1) {
    set<char> s;
    for (auto c : n) s.insert(c);
    if (s.size() <= k) return cout << n << '\n', (void)0;
    s.clear();
    for (long long i = 0;; i++) {
      s.insert(n[i]);
      if (s.size() > k) {
        while (n[i] == '9') i--;
        n[i]++;
        for (long long j = i + 1; j < n.size(); j++) n[j] = '0';
        break;
      }
    }
  }
}
