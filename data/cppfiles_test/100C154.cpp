#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (auto &p : v) {
      cin >> p;
    }
    vector<long long> ans;
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    long long x = v[v.size() - 1];
    if (x < 0 && v.size() > 1) v.pop_back();
    ans.push_back(x);
    if (n > 1) {
      for (auto &p : v) {
        p = p - x;
      }
    }
    ans.push_back(v[v.size() - 1]);
    for (int i = 1; i <= v.size() - 1; i++) {
      ans.push_back(v[i - 1] - v[i]);
    }
    if (v.size() == 1) ans.push_back(v[0]);
    sort(ans.begin(), ans.end());
    cout << ans[ans.size() - 1] << endl;
  }
  return 0;
}
