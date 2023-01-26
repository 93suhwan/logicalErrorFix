#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
using namespace std;
void solve() {
  string s, t;
  cin >> s >> t;
  long long pos = 0;
  string st = "";
  while (s.find(string(st + t[pos])) != string::npos) {
    st += t[pos];
    pos++;
  }
  long long posi = s.find(st) + pos - 2;
  long long posj = pos;
  while (posj < t.length()) {
    if (posi < 0) {
      cout << "NO" << endl;
      return;
    }
    if (t[posj] == s[posi]) {
      posj++;
      posi--;
    } else {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
