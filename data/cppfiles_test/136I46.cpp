#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (auto &i : a) cin >> i;
    for (auto i : a) sum += i;
    ll tot = n * (n + 1) / 2;
    if (sum % tot != 0) {
      cout << "NO\n";
      continue;
    }
    bool got = true;
    vector<ll> ans;
    for (int i = 0; i < n; i++) {
      ll val = a[i] - a[(i + n - 1) % n] - sum / tot;
      if ((-val) % n != 0) {
        got = false;
        break;
      } else {
        ans.push_back(val / -n);
        if (val / (-n) <= 0) {
          got = false;
          break;
        }
      }
    }
    if (!got) {
      cout << "NO\n";
    } else
      for (auto i : ans) {
        cout << i << " ";
      }
    cout << '\n';
  }
}
