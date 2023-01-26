#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, i, a, j, c;
    cin >> n;
    long long int best = 0;
    vector<vector<long long int>> v(n);
    for (i = 0; i < n; i++) {
      c = 0;
      for (j = 0; j < 5; j++) {
        cin >> a;
        v[i].push_back(a);
        if (i != 0) {
          if (v[best][j] > v[i][j]) c++;
        }
      }
      if (c >= 3) {
        best = i;
      }
    }
    long long int ok = -1;
    for (i = 0; i < n; i++) {
      c = 0;
      for (j = 0; j < 5; j++) {
        if (v[best][j] <= v[i][j]) c++;
      }
      if (c < 3) {
        ok = 1;
      }
    }
    if (ok == 1)
      cout << -1;
    else
      cout << best + 1;
    cout << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  solve();
}
