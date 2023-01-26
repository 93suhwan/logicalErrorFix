#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, int>> m;
bool cmp(pair<long long, int> &a, pair<long long, int> &b) {
  if (a.first == b.first) return a.second > b.second;
  return a.first < b.first;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long maxi = 0;
    for (int i = 0; i < n; i++) {
      int k;
      cin >> k;
      vector<long long> a;
      for (int j = 0; j < k; j++) {
        long long z;
        cin >> z;
        maxi = max(maxi, z);
        a.push_back(z);
      }
      auto maxa = max_element(a.begin(), a.end());
      long long maxai = maxa - a.begin();
      long long A = *maxa;
      m.push_back({max(a[0] + 1, A - maxai + 1), a.size()});
    }
    sort(m.begin(), m.end(), cmp);
    long long ans = m[0].first;
    long long temp = ans + m[0].second;
    for (int i = 1; i < n; i++) {
      long long tem = m[i].first;
      if (tem < temp) {
        temp += m[i].second;
      } else {
        ans = tem;
        temp = tem + m[i].second;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
