#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int n = (int)s.size();
  int a = 0, b = 0, c = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'A')
      a += 1;
    else if (s[i] == 'B')
      b += 1;
    else
      c += 1;
  }
  if (b == a + c) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
const int query = 1;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int qq = 1;
  if (query == 1) cin >> qq;
  for (int i = 1; i <= qq; i++) {
    solve();
  }
}
