#include <bits/stdc++.h>
using namespace std;
void FAST_IO(string filein = "", string fileout = "", string fileerr = "") {
  if (fopen(filein.c_str(), "r")) {
    freopen(filein.c_str(), "r", stdin);
    freopen(fileout.c_str(), "w", stdout);
  }
  cin.tie(0), cout.tie(0)->sync_with_stdio(0);
}
void Hollwo_Pelw();
signed main() {
  FAST_IO("hollwo_pelw.inp", "hollwo_pelw.out");
  int testcases = 1;
  for (int test = 1; test <= testcases; test++) {
    Hollwo_Pelw();
  }
  return 0;
}
const int N = 2e5 + 5;
void Hollwo_Pelw() {
  int n, m;
  cin >> n >> m;
  vector<pair<string, int>> st(n);
  for (int i = 0; i < n; i++) {
    cin >> st[i].first, st[i].second = i;
    for (int j = 1; j < st[i].first.size(); j += 2)
      st[i].first[j] = 'A' + 'Z' - st[i].first[j];
  }
  sort(st.begin(), st.end());
  for (auto [v, p] : st) cout << p + 1 << ' ';
}
