#include <bits/stdc++.h>
using namespace std;
void Solve() {
  string s;
  cin >> s;
  int N = s.size();
  int e = 0, n = 0;
  for (int i = 0; i < N; i++) {
    if (s[i] == 'E')
      e += 1;
    else
      n += 1;
  }
  if (n == 0 || e == 0 || n >= 2) {
    cout << "YES\n";
    return;
  }
  cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) Solve();
}
