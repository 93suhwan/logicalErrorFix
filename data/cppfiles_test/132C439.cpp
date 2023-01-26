#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  long long t;
  cin >> t;
  while (t--) {
    vector<long long> v(7);
    for (auto& e : v) cin >> e;
    sort(v.begin(), v.end());
    cout << v[0] << ' ' << v[1] << ' ';
    if (v[2] != v[1] + v[0])
      cout << v[2] << endl;
    else
      cout << v[3] << endl;
  }
  return 0;
}
