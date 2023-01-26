#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.14159265358979323844;
const long long int inf = 1e18;
const long long int N = 1e5 + 1;
const long long int M = 1e9 + 7;
void somlve() {
  int n;
  cin >> n;
  vector<int> v(n), res(n + 1, 0);
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    m[v[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    if (m[i] > 1) {
      cout << -1 << "\n";
      return;
    }
    if (m[i] == 1) res[i] = 1;
  }
  sort(v.begin(), v.end());
  int ans = 0;
  int k = 1;
  for (int i = 0; i < n; i++) {
    if (res[k] == 1) {
      k = i + 2;
      continue;
    }
    if (m[v[i]] == 1 && v[i] <= n) {
      continue;
    }
    if (v[i] > k) {
      int x = v[i] / 2;
      if (v[i] % 2 == 0) x--;
      if (x < k) {
        cout << -1 << "\n";
        return;
      }
      ans++;
      k++;
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
