#include <bits/stdc++.h>
using namespace std;
void slv() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  bool ok = 0;
  for (int i = 0; i < n - 1; i++)
    if (v[i] > v[i + 1]) ok = 1;
  if ((n & 1) and !ok)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    slv();
  }
  return 0;
}
