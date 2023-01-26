#include <bits/stdc++.h>
using namespace std;
long long lstbt(long long val) {
  long long msk = val & (val - 1);
  return log2(val ^ msk);
}
void c_p_c() {}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  c_p_c();
  int t;
  cin >> t;
  while (t--) {
    long long n;
    long long k;
    cin >> n >> k;
    long long arr[n + 2];
    vector<long long> pos, neg;
    for (long long i = 0; i < n; ++i) {
      cin >> arr[i];
      if (arr[i] >= 0) {
        pos.push_back(arr[i]);
      } else {
        neg.push_back(arr[i]);
      }
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    long long ans = 0;
    long long p1 = pos.size();
    long long n1 = neg.size();
    for (long long i = p1 - 1; i >= k - 1; i = i - k) {
      ans = ans + 2 * pos[i];
    }
    if (p1 % k != 0) {
      ans = ans + 2 * pos[p1 % k - 1];
    }
    for (long long i = n1 - 1; i >= k - 1; i = i - k) {
      ans = ans + 2 * neg[i];
    }
    if (n1 % k != 0) {
      ans = ans + 2 * neg[n1 % k - 1];
    }
    if (p1 == 0) {
      ans = ans - neg[n1 - 1];
    } else if (n1 == 0) {
      ans = ans - pos[p1 - 1];
    } else if (pos[p1 - 1] >= neg[n1 - 1]) {
      ans = ans - pos[p1 - 1];
    } else {
      ans = ans - neg[n1 - 1];
    }
    cout << ans << endl;
  }
}
