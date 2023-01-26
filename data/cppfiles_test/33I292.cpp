#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, k, x, i;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long a[n];
    set<long long> s;
    set<long long>::iterator itr;
    for (int i = 0; i < n; i++) {
      cin >> x;
      s.insert(x);
    }
    vector<long long> v(s.begin(), s.end());
    k = v.size();
    if (k == 1) {
      cout << v[0] * v[0] << endl;
    } else {
      long long ans = v[k - 2] * v[k - 1];
      cout << ans << endl;
    }
  }
}
