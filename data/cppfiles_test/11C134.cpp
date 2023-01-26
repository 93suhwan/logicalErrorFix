#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1e9, MAX = 3e5 + 5;
const long long INF = 1e18 + 5;
int main() {
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    vector<string> V(n);
    for (int in = 0; in < 0 + n; in++) cin >> V[in];
    int ans = 0;
    int totlet = 0;
    for (auto s : V) {
      totlet += s.length();
    }
    for (int ps = 0; ps < 5; ps++) {
      vector<int> HM(n);
      for (int i = 0; i < n; i++) {
        for (auto c : V[i]) {
          if (c == ('a' + ps))
            HM[i]++;
          else
            HM[i]--;
        }
      }
      sort(HM.begin(), HM.end());
      reverse(HM.begin(), HM.end());
      int temp = 0;
      int sum = 0;
      for (int i = 0; i < n; i++) {
        sum += HM[i];
        if (sum > 0) {
          temp++;
        } else
          break;
      }
      ans = max(ans, temp);
    }
    cout << ans << endl;
  }
}
