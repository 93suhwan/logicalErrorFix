#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, all = 0;
  cin >> n;
  vector<int> arr(n + 1), ans;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    all ^= arr[i];
  }
  if (all == 1) {
    cout << "NO\n";
    return;
  }
  if (n & 1) {
    for (int i = 1; i < n; i += 2) {
      ans.push_back(i);
    }
    for (int i = n - 4; i > 0; i -= 2) {
      ans.push_back(i);
    }
    cout << "YES\n" << ans.size() << '\n';
    for (int i : ans) {
      cout << i << ' ';
    }
    cout << '\n';
    return;
  } else {
    int pre = 0;
    for (int i = 1; i <= n; i++) {
      pre ^= arr[i];
      if (pre == 0 && (i & 1)) {
        for (int j = 1; j < i; j += 2) {
          ans.push_back(j);
        }
        for (int j = i - 4; j > 0; j -= 2) {
          ans.push_back(j);
        }
        for (int j = i + 1; j < n; j += 2) {
          ans.push_back(j);
        }
        for (int j = n - 4; j > i; j -= 2) {
          ans.push_back(j);
        }
        cout << "YES\n" << ans.size() << '\n';
        for (int i : ans) {
          cout << i << ' ';
        }
        cout << '\n';
        return;
      }
    }
  }
  cout << "NO\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
