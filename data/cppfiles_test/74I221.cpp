#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    if (a > b) {
      swap(a, b);
    }
    vector<long long> ans;
    if ((a + b) % 2 == 1) {
      ans.push_back((a + b) / 2);
      ans.push_back((a + b) / 2 + 1);
      for (long long i = (a + b) / 2 + 2, cnt = 0; cnt < a; cnt++, i++) {
        ans.push_back(i);
      }
      for (long long i = (a + b) / 2 - 1, cnt = 0; cnt < a; cnt++, i--) {
        ans.push_back(i);
      }
    } else {
      long long x = (a + b) / 2;
      ans.push_back(x - a);
      ans.push_back(x + a);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto x : ans) {
      cout << x << " ";
    }
    cout << "\n";
  }
}
