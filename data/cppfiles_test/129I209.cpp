#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.14159265358979323844;
const long long int inf = 1e18;
const long long int N = 1e5 + 1;
const long long int M = 1e9 + 7;
void somlve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (v[i] < i + 1) {
      cout << -1 << "\n";
      return;
    }
    if (v[i] > i + 1) {
      int x = v[i] / 2;
      if (v[i] % 2 == 0) x--;
      if (x < i + 1) {
        cout << -1 << "\n";
        return;
      }
      ans++;
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t) {
    t--;
    somlve();
  }
  return 0;
}
