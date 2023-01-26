#include <bits/stdc++.h>
using namespace std;
const int N_MAX = 100000;
int n, m;
string s[N_MAX];
int p[N_MAX];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (int j = 1; j < m; j++) s[i][j] = char('z' - 1 - s[i][j]);
  }
  for (int i = 0; i < n; i++) p[i] = i;
  sort(p, p + n, [&](const int &i, const int &j) { return s[i] < s[j]; });
  for (int i = 0; i < n; i++) cout << p[i] + 1 << " ";
  cout << "\n";
  return 0;
}
