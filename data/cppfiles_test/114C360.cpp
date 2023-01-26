#include <bits/stdc++.h>
using namespace std;
int t;
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  int Min = *min_element(v.begin(), v.end());
  for (int i = 0, k = 0; k < n / 2; i++)
    if (v[i] != Min) {
      cout << v[i] << ' ' << Min << '\n';
      k++;
    }
}
int main() {
  cin >> t;
  while (t--) solve();
}
