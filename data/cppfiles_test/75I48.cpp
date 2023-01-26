#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, int>> m;
bool cmp(pair<long long, int> &a, pair<long long, int> &b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first < b.first;
}
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
    sort(m.begin(), m.end(), cmp);
    long long ans = m[0].first;
    long long temp = ans + m[0].second;
    for (int i = 1; i < n; i++) {
      long long tem = m[i].first;
      if (tem < temp) {
        temp += m[i].second;
      } else {
        long long diff = tem - temp;
        ans += diff;
        temp = tem + m[i].second;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
