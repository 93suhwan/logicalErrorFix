#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
long long int n;
void solve() {
  for (int i = 0; i != n; ++i) {
    cout << "()";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    solve();
  }
  return 0;
}
