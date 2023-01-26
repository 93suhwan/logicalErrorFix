#include <bits/stdc++.h>
using namespace std;
int t;
void solve() {
  cin >> t;
  while (t--) {
    int i, n, r = 0;
    cin >> n;
    string s;
    cin >> s;
    int a[n];
    for (i = 0; i < (n); i++) {
      a[i] = s[i] - '0';
      if (a[i] > 0 && i != n - 1)
        r += (a[i] + 1);
      else if (a[i] > 0 && i == n - 1)
        r += a[i];
    }
    cout << r << endl;
  }
}
int main(int argc, char** argv) {
  string s;
  int i;
  if (argc == 1) ios::sync_with_stdio(false), cin.tie(0);
  for (i = 0; i < (argc - 1); i++) s += argv[i + 1], s += '\n';
  for (i = 0; i < (s.size()); i++) ungetc(s[s.size() - 1 - i], stdin);
  cout.tie(0);
  solve();
  return 0;
}
