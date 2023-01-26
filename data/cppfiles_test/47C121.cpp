#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, i, ans = 0, k, j, ans1 = 0, ans2 = 0, nn, l1, l2, x;
    cin >> n >> k;
    vector<long long int> arr(n);
    for (i = 0; i < n; i++) {
      cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    vector<long long int> pos, neg;
    for (i = 0; i < n; i++) {
      if (arr[i] > 0) {
        pos.push_back(arr[i]);
      } else {
        neg.push_back(-arr[i]);
      }
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    l1 = pos.size();
    l2 = neg.size();
    nn = n;
    if (l1 > 0) {
      ans1 += pos[l1 - 1];
    }
    j = l1 - 1 - k;
    while (j >= 0) {
      ans1 += (2 * pos[j]);
      j -= k;
    }
    j = l2 - 1;
    while (j >= 0) {
      ans1 += (2 * neg[j]);
      j -= k;
    }
    if (l2 > 0) {
      ans2 += neg[l2 - 1];
    }
    j = l2 - 1 - k;
    while (j >= 0) {
      ans2 += (2 * neg[j]);
      j -= k;
    }
    j = l1 - 1;
    while (j >= 0) {
      ans2 += (2 * pos[j]);
      j -= k;
    }
    ans = min(ans1, ans2);
    cout << ans << "\n";
  }
  return 0;
}
