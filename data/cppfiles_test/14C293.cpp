#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n, i, j = 0, x1;
  cin >> t;
  while (t--) {
    j = 0;
    cin >> n;
    vector<long long> v(n);
    for (i = 0; i < n; i++) {
      cin >> v[i];
    }
    vector<long long> v1(n);
    for (i = 0; i < n; i++) {
      v1[i] = v[i];
    }
    vector<pair<long long, pair<long long, long long>>> ans;
    sort(v1.begin(), v1.end());
    i = 0;
    while (i < n) {
      if (v[i] == v1[i]) {
        i++;
      } else {
        for (j = i; j < n; j++) {
          if (v1[i] == v[j]) {
            break;
          }
        }
        long long temp = v[i];
        v[i] = v1[i];
        ans.push_back({i, {j, (j - i)}});
        for (long long p = i + 1; p <= j; p++) {
          long long pp = v[p];
          v[p] = temp;
          temp = pp;
        }
        i++;
      }
    }
    cout << ans.size() << "\n";
    for (i = 0; i < ans.size(); i++) {
      cout << ans[i].first + 1 << " " << ans[i].second.first + 1 << " "
           << ans[i].second.second << "\n";
    }
  }
}
