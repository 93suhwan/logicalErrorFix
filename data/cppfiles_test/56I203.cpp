#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  vector<pair<int, int> > moves;
  for (int i = 1; i <= 8; i++) {
    if (i % 2)
      for (int j = 1; j <= 8; j++) moves.push_back({i, j});
    else
      for (int j = 8; j >= 1; j--) moves.push_back({i, j});
  }
  int i = rng() % 64;
  for (int j = i; j < 64; j++) {
    auto [x, y] = moves[i];
    cout << x << " " << y << endl;
    string s;
    cin >> s;
    if (s == "Done") return;
  }
  for (int j = 0; j < i; j++) {
    auto [x, y] = moves[i];
    cout << x << " " << y << endl;
    string s;
    cin >> s;
    if (s == "Done") return;
  }
  assert(false);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int testcase = 1;
  cin >> testcase;
  for (int i = 1; i <= testcase; i++) {
    solve();
  }
  return 0;
}
