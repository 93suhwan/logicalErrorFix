#include <bits/stdc++.h>
using namespace std;
const long long mod = 1E9 + 7;
const long long P = 31;
void filein() {}
void solve() {
  int n, i;
  cin >> n;
  vector<int> v(n, 0);
  int j = 2;
  for (i = 0; i < n; i++) {
    v[i] = j++;
  }
  for (i = 0; i < n; i++) cout << v[i] << " ";
  cout << endl;
}
int main() {
  filein();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
