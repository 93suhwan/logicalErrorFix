#include <bits/stdc++.h>
using namespace std;
void Solve() {
  string s;
  cin >> s;
  int cnt = 0;
  for (auto i : s) {
    cnt += (i == 'N');
  }
  cout << (cnt == 1 ? "NO" : "YES") << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) Solve();
}
