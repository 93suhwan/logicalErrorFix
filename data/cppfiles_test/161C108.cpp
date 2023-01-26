#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int l[n], r[n];
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
      cin >> l[i] >> r[i];
      v[i].second = i;
      v[i].first = r[i] - l[i];
    }
    sort(v.begin(), v.end());
    int req[n];
    int temp;
    set<int> s;
    set<int>::iterator it;
    for (int j = 0; j < n; j++) {
      temp = v[j].second;
      for (int k = l[temp]; k <= r[temp]; k++) {
        it = s.find(k);
        if (it == s.end()) {
          req[temp] = k;
          s.insert(k);
          break;
        }
      }
    }
    for (int g = 0; g < n; g++) {
      cout << l[g] << " " << r[g] << " " << req[g] << '\n';
    }
    cout << '\n';
  }
  return 0;
}
