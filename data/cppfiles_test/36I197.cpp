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
    vector<int> ans;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      int q;
      cin >> q;
      ans.push_back(q);
      ind[q] = i + 1;
      sum += q;
    }
    if (is_composite(sum) == 0) ans.pop_back();
    cout << ans.size() << endl;
    for (long long e : ans) cout << ind[e] << " ";
    cout << endl;
  }
  return 0;
}
