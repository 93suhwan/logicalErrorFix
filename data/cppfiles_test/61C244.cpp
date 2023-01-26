#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
const long long int INF = 1e9;
void solve() {
  long long int n;
  cin >> n;
  string s;
  cin >> s;
  int i = 0;
  while (i < n && s[i] == '?') i++;
  if (i == n) {
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0)
        cout << 'B';
      else
        cout << 'R';
    }
    cout << endl;
    return;
  }
  long long int cr = i;
  for (int j = i - 1; j >= 0; j--) {
    if (s[j] == 'R' || s[j] == 'B')
      cr = j;
    else if (s[j] == '?') {
      if (s[cr] == 'B')
        s[j] = 'R';
      else
        s[j] = 'B';
      cr = j;
    }
  }
  cr = i;
  for (int j = i + 1; j < n; j++) {
    if (s[j] == 'R' || s[j] == 'B')
      cr = j;
    else if (s[j] == '?') {
      if (s[cr] == 'B')
        s[j] = 'R';
      else
        s[j] = 'B';
      cr = j;
    }
  }
  cout << s << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int tc;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
  return 0;
}
