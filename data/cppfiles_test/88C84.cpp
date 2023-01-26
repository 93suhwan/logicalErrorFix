#include <bits/stdc++.h>
using namespace std;
int solve() {
  int R, C;
  cin >> R >> C;
  int n = R * C;
  vector<vector<int> > vis(R, vector<int>(C));
  vector<int> q(n);
  for (int i = (0); i < (n); ++i) cin >> q[i];
  vector<int> ord(n);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(), [&](int i, int j) {
    if (q[i] != q[j]) return q[i] < q[j];
    return i > j;
  });
  int p = 0;
  while (p < n) {
    int p2 = p + 1;
    while (p2 < n && q[ord[p2]] == q[ord[p]]) ++p2;
    if (p / C != (p2 - 1) / C) {
      vector<int> v(ord.begin() + p, ord.begin() + p2);
      int pmid = p / C * C + C;
      for (int i = (pmid - 1); i >= (p); --i) ord[i] = v.back(), v.pop_back();
      for (pmid += C; pmid <= p2; pmid += C)
        for (int i = (pmid - 1); i >= (pmid - C); --i)
          ord[i] = v.back(), v.pop_back();
      for (int i = (p2 - 1); i >= (pmid - C); --i)
        ord[i] = v.back(), v.pop_back();
    }
    p = p2;
  }
  for (int i = (0); i < (n); ++i) q[ord[i]] = i;
  int res = 0;
  for (int i = (0); i < (n); ++i) {
    int placeR = q[i] / C;
    int placeC = q[i] % C;
    for (int j = (0); j < (placeC); ++j)
      if (vis[placeR][j]) ++res;
    vis[placeR][placeC] = true;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    cout << solve() << "\n";
  }
}
