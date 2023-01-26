#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9 + 10;
void solve() {
  string s;
  cin >> s;
  long long twopow = 1;
  vector<string> p;
  p.push_back(to_string(twopow));
  for (int i = 1; i <= 62; i++) {
    twopow *= 2;
    p.push_back(to_string(twopow));
  }
  int move = s.size() + 1;
  for (string n : p) {
    int match = 0;
    int si = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == n[si]) {
        match++;
        si++;
      }
    }
    int cur_move = (n.size() - match) + (s.size() - match);
    move = min(move, cur_move);
  }
  cout << move << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
