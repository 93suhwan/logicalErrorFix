#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int a = 0;
  int b = 0;
  int c = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'A')
      a++;
    else if (s[i] == 'B')
      b++;
    else
      c++;
  }
  if (a + c == b)
    cout << "YES"
         << "\n";
  else
    cout << "NO"
         << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) solve();
}
