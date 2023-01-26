#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n, 0);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long ans = a[0];
    long long b = 0;
    long long bans = ans;
    for (int i = 0; i < n - 1; i++) {
      a[i + 1] -= b;
      b += a[i];
      a[i + 1] -= a[i];
      ans = a[i + 1];
      bans = max(bans, ans);
    }
    cout << bans << endl;
  }
}
