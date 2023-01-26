#include <bits/stdc++.h>
using namespace std;
void debug_out() { cerr << '\n'; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  for (auto tt = 0; tt < t; tt++) {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n, 0));
    for (auto i = 0; i < m; i++)
      for (auto j = 0; j < n; j++) cin >> a.at(i).at(j);
    int L = 0;
    int R = 1000000001;
    while (R - L > 1) {
      int M = (L + R) / 2;
      vector<int> mm(m, 0);
      bool TWO = false;
      bool Found;
      for (auto j = 0; j < n; j++) {
        Found = false;
        for (auto i = 0; i < m; i++)
          if (a.at(i).at(j) >= M) {
            Found = true;
            mm.at(i)++;
            if (mm.at(i) > 1) TWO = true;
          }
        if (!Found) break;
      }
      if (!Found) {
        R = M;
        continue;
      }
      if (!TWO) {
        R = M;
        continue;
      }
      L = M;
    }
    cout << L << endl;
  }
  return 0;
}
