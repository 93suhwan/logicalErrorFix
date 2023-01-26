#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2, MOD = 1e9 + 7;
void solve() {
  int n;
  scanf("%d", &n);
  int ar[2][n];
  for (long long int j = 0; j < n; j++) {
    scanf("%d", &ar[0][j]);
    if (j != 0)
      ar[0][j] = ar[0][j] + ar[0][j - 1];
    else
      ar[0][j] = ar[0][j];
  }
  for (long long int i = 0; i < n; i++) {
    scanf("%d", &ar[1][i]);
    if (i != 0)
      ar[1][i] = ar[1][i] + ar[1][i - 1];
    else
      ar[1][i] = ar[1][i];
  }
  unordered_set<long long int> s;
  for (long long int i = 0; i < n; i++) {
    long long int fsum, ssum;
    fsum = (ar[0][n - 1] - ar[0][i]);
    if (i > 0)
      ssum = (ar[1][i - 1]);
    else
      ssum = 0;
    long long int t = 0;
    if (fsum > ssum)
      t = fsum;
    else
      t = ssum;
    s.insert(t);
  }
  cout << *(min_element(s.begin(), s.end())) << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
}
