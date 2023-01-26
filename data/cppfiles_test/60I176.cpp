#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> m;
    long long int sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      sum += v[i];
      m[v[i]]++;
    }
    if ((2 * sum) % n != 0) {
      cout << 0 << endl;
      continue;
    }
    long long int need = 2 * (sum) / n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int a1 = v[i];
      int a2 = need - a1;
      ans += m[a2];
      if (a1 == a2) ans -= 1;
    }
    cout << ans / 2 << endl;
  }
}
