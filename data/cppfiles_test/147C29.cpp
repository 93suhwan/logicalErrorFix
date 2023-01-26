#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int flag = 0, a = 0, b = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'E')
      a++;
    else
      b++;
  }
  if (a == s.length() - 1 && b == 1)
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
