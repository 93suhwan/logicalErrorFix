#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long m, n, a[100009], ans = 0;
    cin >> n >> m;
    vector<pair<long long, long long> > v;
    for (int i = 0; i < n * m; i++) {
      cin >> a[i];
      v.push_back(make_pair(a[i], i));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int k = i * m; k < i * m + j; k++) {
          if (v[k].first < v[i * m + j].first &&
              v[k].second < v[i * m + j].second)
            ans++;
        }
      }
    }
    cout << ans << endl;
  }
}
