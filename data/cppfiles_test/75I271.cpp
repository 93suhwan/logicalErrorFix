#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, int>> m;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int k;
      cin >> k;
      vector<long long> a;
      long long maxi = 0;
      for (int j = 0; j < k; j++) {
        long long z;
        cin >> z;
        a.push_back(z);
        maxi = max(z - j + 1, maxi);
      }
      m.push_back({maxi, a.size()});
    }
    sort(m.begin(), m.end());
    long long ans = m[0].first;
    long long temp = ans;
    for (int i = 1; i < n; i++) {
      temp += m[i - 1].second;
      if (temp > m[i].first) {
        temp += m[i].second;
      } else {
        long long diff = m[i].first - temp;
        ans += diff;
        temp += diff;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
