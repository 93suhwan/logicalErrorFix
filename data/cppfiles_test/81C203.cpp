#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<long long int> odd, even;
    vector<long long int> arr;
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        if (s[i] == '+')
          arr.push_back(1);
        else
          arr.push_back(-1);
      } else {
        if (s[i] == '+')
          arr.push_back(-1);
        else
          arr.push_back(1);
      }
    }
    vector<long long int> pre(n + 1);
    for (int i = 1; i <= n; i++) {
      pre[i] = pre[i - 1] + arr[i - 1];
    }
    while (q--) {
      long long int l, r;
      cin >> l >> r;
      long long int ans = pre[r] - pre[l - 1];
      ans = abs(ans);
      if (ans == 0)
        cout << ans << endl;
      else if (ans % 2)
        cout << 1 << endl;
      else
        cout << 2 << endl;
    }
  }
  return 0;
}
