#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (long long int i = 0; i < n; i++) cin >> v[i];
  vector<int> cp = v;
  sort(cp.begin(), cp.end());
  long long int c = 0;
  while (cp != v) {
    for (long long int i = 0; i < n - 1; i++) {
      if ((i + 1) % 2 == (c + 1) % 2 && v[i] > v[i + 1]) {
        swap(v[i], v[i + 1]);
      }
    }
    c++;
  }
  cout << c << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) solve();
}
