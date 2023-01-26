#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> v(n);
    long long sum = 0ll;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      sum += v[i];
    }
    long long N = (n * (n + 1)) / 2;
    if (sum % N != 0) {
      cout << "NO\n";
    } else {
      vector<long long> ans(n);
      sum /= N;
      bool flag = true;
      for (int i = 1; i < n; i++) {
        long long val = v[i - 1] - v[i];
        val += sum;
        if (val % n == 0 && val > 0)
          ans[i] = val / n;
        else {
          flag = false;
          break;
        }
      }
      long long val = 0ll;
      for (int i = 1; i < n; i++) val += ans[i];
      if ((sum - val) > 0)
        ans[0] = (sum - val);
      else
        flag = false;
      if (!flag)
        cout << "NO\n";
      else {
        cout << "YES\n";
        for (auto &u : ans) cout << u << " ";
        cout << "\n";
      }
    }
  }
  return 0;
}
