#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  long long int p = 2;
  for (int i = 0; i < n; i++) {
    cout << p << " ";
    p++;
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
