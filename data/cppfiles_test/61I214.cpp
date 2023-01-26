#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int, int>> vect;
    map<int, int> mp1;
    map<int, int> mp2;
    for (int i = 0; i < n; i++) {
      int a, b;
      cin >> a >> b;
      vect.push_back({a, b});
      mp1[a]++;
      mp2[b]++;
    }
    int ans = n * (n - 1) * (n - 2) / (3 * 2);
    for (int i = 0; i < n; i++) {
      int ta = mp1[vect[i].first] - 1;
      int tb = mp2[vect[i].second] - 1;
      ans = ans - ta * tb;
    }
    cout << ans << endl;
  }
}
