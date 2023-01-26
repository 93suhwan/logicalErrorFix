#include <bits/stdc++.h>
using namespace std;
const int N = 6e3 + 10;
const int INF = 1e9 + 10;
int n, t;
char a[N][N];
string s;
void solve() {
  vector<int> p2;
  for (int i = (0); i <= (n - 1); i++)
    for (int j = (0); j <= (n - 1); j++) a[i][j] = '=';
  for (int i = (0); i <= (n - 1); i++) {
    if (s[i] == '2') p2.push_back(i);
  }
  int n2 = (int)(p2).size();
  if (n2 == 2 or n2 == 1) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  for (int i = (0); i <= (n - 1); i++) a[i][i] = 'X';
  for (int i = (0); i <= (n2 - 1); i++) {
    int p = p2[i];
    int q = p2[(i + 1) % n2];
    a[p][q] = '+';
    a[q][p] = '-';
  }
  for (int i = (0); i <= (n - 1); i++) {
    for (int j = (0); j <= (n - 1); j++) {
      cout << a[i][j];
    }
    cout << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> s;
    solve();
  }
}
