#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    if (sum % (1ll * n * (n + 1) / 2)) {
      puts("NO");
      continue;
    }
    sum = sum / (1ll * n * (n + 1) / 2);
    vector<ll> ans;
    int flag = 1;
    ll ss = 0;
    for (int i = 0; i < n; i++) {
      ll cur = sum - (a[i] - a[(i - 1 + n) % n]);
      if (cur % n || cur <= 0) {
        flag = 0;
        break;
      }
      ans.push_back(cur / n);
    }
    if (flag) {
      puts("YES");
      for (auto v : ans) cout << v << " ";
      cout << endl;
    } else {
      puts("NO");
    }
  }
  return 0;
}
