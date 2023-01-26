#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  };
}
void solve() {
  string s;
  cin >> s;
  int n = s.size();
  int c1 = 0;
  int c2 = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'B')
      c1++;
    else
      c2++;
  }
  if (c1 == c2)
    cout << "yes";
  else
    cout << "no";
}
