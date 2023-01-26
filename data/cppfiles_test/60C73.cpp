#include <bits/stdc++.h>
using namespace std;
const int N = 1e9 + 1;
void solve() {
  long long int n;
  cin >> n;
  ;
  vector<long long int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  long long int a = 0;
  for (int i = 0; i < 31; i++) {
    bool ch = false;
    for (int j = 0; j < n; j++) {
      if (!(v[j] & (1 << i))) ch = true;
    }
    if (!ch) a += (1 << i);
  }
  cout << a << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
