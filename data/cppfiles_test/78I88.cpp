#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> vec(n), cnt(32), ans;
  for (auto &v : vec) {
    cin >> v;
  }
  for (int i = 0; i < 31; i++) {
    for (auto &v : vec) {
      if ((v & (1 << i))) {
        cnt[i]++;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    bool f = true;
    for (int j = 1; j < 31; j++) {
      if (cnt[j] % i != 0) {
        f = false;
        break;
      }
    }
    if (f) {
      ans.push_back(i);
    }
  }
  for (auto &a : ans) {
    cout << a << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve(), cout << "\n";
  }
  return 0;
}
