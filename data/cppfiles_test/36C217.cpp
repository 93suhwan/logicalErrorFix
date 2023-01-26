#include <bits/stdc++.h>
using namespace std;
bool is_composite(long long n) {
  if (n == 0) return false;
  for (int i = 2; i * i <= n; i++) {
    long long f = n / i;
    if (f * i == n) return true;
  }
  return false;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    map<long long, long long> ind;
    int n;
    cin >> n;
    vector<int> v;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      int q;
      cin >> q;
      v.push_back(q);
      ind[q] = i + 1;
    }
    int sum_e = 0;
    for (int i = 0; i < n; i++) {
      if (v[i] % 2 == 0) {
        ans.push_back(v[i]);
        sum_e += v[i];
      }
    }
    int sum_o = 0;
    for (int i = 0; i < n; i++) {
      if (v[i] % 2 == 1) {
        ans.push_back(v[i]);
        sum_o += v[i];
      }
    }
    if (is_composite(sum_e + sum_o) == 0) ans.pop_back();
    cout << ans.size() << endl;
    for (long long e : ans) cout << ind[e] << " ";
    cout << endl;
  }
  return 0;
}
