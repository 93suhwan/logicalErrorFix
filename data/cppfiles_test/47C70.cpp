#include <bits/stdc++.h>
using namespace std;
long long t, n, k;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    vector<long long> neg, pos;
    long long negctr = 0, posctr = 0;
    for (int i = 0; i < n; i++) {
      long long x;
      cin >> x;
      if (x < 0) {
        neg.push_back(-x);
        negctr++;
      } else if (x > 0) {
        pos.push_back(x);
        posctr++;
      }
    }
    if (neg.size() == 0 && pos.size() == 0) {
      cout << 0 << endl;
      continue;
    }
    sort(neg.begin(), neg.end(), greater<long long>());
    sort(pos.begin(), pos.end(), greater<long long>());
    long long ans = 0;
    for (int i = 0; i < negctr; i += k) {
      ans += 2 * neg[i];
    }
    for (int i = 0; i < posctr; i += k) {
      ans += 2 * pos[i];
    }
    if (negctr == 0) {
      ans -= pos[0];
    } else if (posctr == 0) {
      ans -= neg[0];
    } else {
      ans -= max(neg[0], pos[0]);
    }
    cout << ans << "\n";
  }
  cout.flush();
  return 0;
}
