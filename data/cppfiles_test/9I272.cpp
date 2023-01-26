#include <bits/stdc++.h>
using namespace std;
string s;
void solve() {
  string a;
  cin >> s;
  bool flag;
  int res = 0, n = s.length();
  for (int(i) = 0; (i) < (n); (i)++) {
    flag = true;
    for (int(j) = 0; (j) < (a.length()); (j)++) {
      if (s[i] == a[j]) {
        for (int k = j + 1; k < a.length(); k++) {
          if (s[k] == a[j]) flag = false;
        }
      }
    }
    if (flag) a += s[i];
  }
  if (a.length() > 1)
    cout << a.length() / 2;
  else
    cout << 0;
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  cerr << "Time taken : " << (float)clock() / CLOCKS_PER_SEC * 3000 << " ms"
       << endl;
  return 0;
}
