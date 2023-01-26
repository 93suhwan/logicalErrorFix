#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 6;
const int MOD = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  vector<int> v;
  int i = 1;
  while (n) {
    if (n % 2) v.push_back(i);
    i *= 2;
    n /= 2;
  }
  string s = "";
  string ss = "";
  string sep = "";
  char ch = 'a';
  for (int x : v) {
    if (x == 1) {
      sep += ch;
      ch++;
      continue;
    }
    int y = x / 2;
    for (int z = 0; z < y; z++) s += ch;
    for (int z = 1; z < y; z++) ss += ch;
    ch++;
    sep += ch;
    ch++;
  }
  cout << s << sep << ss << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
