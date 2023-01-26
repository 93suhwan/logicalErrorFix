#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long eps = 1e-9;
void solve() {
  string ch;
  cin >> ch;
  int count = 0;
  for (int i = 0; i < ch.size(); i++) {
    if (ch[i] == 'N') count++;
  }
  if (count != 1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
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
