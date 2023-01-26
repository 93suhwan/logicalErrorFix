#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long eps = 1e-9;
void solve() {
  string ch;
  cin >> ch;
  set<char> e;
  for (auto x : ch) {
    e.insert(x);
  }
  if (e.size() == 1) {
    cout << "YES" << endl;
    return;
  }
  for (int i = 1; i < ch.size(); i++) {
    if (ch[i] == ch[i - 1]) {
      ch.erase(i + ch.begin());
    }
  }
  if (ch[0] != ch[ch.size() - 1]) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ;
  long long T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
