#include <bits/stdc++.h>
using namespace std;
void init() {}
int main() {
  init();
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int tests;
  cin >> tests;
  while (tests--) {
    vector<long long int> v(3);
    for (long long int i = 0; i < 3; i++) cin >> v[i];
    sort(v.begin(), v.end(), greater<long long int>());
    long long int m;
    cin >> m;
    if (m > (v[0] + v[1] + v[2] - 3))
      cout << "NO\n";
    else {
      long long int op = v[0] - 1 - (v[1] + v[2]);
      if (m >= op)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}
