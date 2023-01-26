#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int flag = 0;
  for (int i = 0; i < s.length() - 1; i++) {
    if (s[i] != 'E') flag = 1;
  }
  if (flag == 0 && s[s.length() - 1] == 'N')
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long test = 1;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
