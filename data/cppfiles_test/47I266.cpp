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
      if (arr[i] >= 0) {
        pos.push_back(arr[i]);
      } else {
        neg.push_back(arr[i]);
      }
    }
    sort(pos.rbegin(), pos.rend());
    sort(neg.rbegin(), neg.rend());
    l1 = pos.size();
    l2 = neg.size();
    nn = n;
    x = min((l1 % k), l1);
    nn -= x;
    if (x > 0) {
      if ((nn > 0) && (l1 > 0)) {
        ans1 += (2 * pos[l1 - x]);
      } else {
        if (l1 > 0) ans1 += pos[l1 - x];
      }
    }
    j = l1 - 1 - x;
    while (j >= 0) {
      x = min((j + 1), k);
      long long int cur = pos[j - x + 1];
      nn -= x;
      if (nn > 0) {
        ans1 += (2 * cur);
      } else {
        ans1 += cur;
      }
      j -= x;
    }
    x = min((l2 % k), l2);
    nn -= x;
    if (x > 0) {
      if ((nn > 0) && (l2 > 0)) {
        ans1 += (2 * abs(neg[l2 - 1]));
      } else {
        if (l2 > 0) ans1 += abs(neg[l2 - 1]);
      }
    }
    j = l2 - 1 - x;
    while (j >= 0) {
      long long int cur = abs(neg[j]);
      x = min((j + 1), k);
      nn -= x;
      if (nn > 0) {
        ans1 += (2 * cur);
      } else {
        ans1 += cur;
      }
      j -= x;
    }
    nn = n;
    x = min((l2 % k), l2);
    nn -= x;
    if (x > 0) {
      if ((nn > 0) && (l2 > 0)) {
        ans2 += (2 * abs(neg[l2 - 1]));
      } else {
        if (l2 > 0) ans2 += abs(neg[l2 - 1]);
      }
    }
    j = l2 - 1 - x;
    while (j >= 0) {
      long long int cur = abs(neg[j]);
      x = min((j + 1), k);
      nn -= x;
      if (nn > 0) {
        ans2 += (2 * cur);
      } else {
        ans2 += cur;
      }
      j -= x;
    }
    x = min((l1 % k), l1);
    nn -= x;
    if (x > 0) {
      if ((nn > 0) && (l1 > 0)) {
        ans2 += (2 * pos[l1 - x]);
      } else {
        if (l1 > 0) ans2 += pos[l1 - x];
      }
    }
    j = l1 - 1 - x;
    while (j >= 0) {
      x = min((j + 1), k);
      long long int cur = pos[j - x + 1];
      nn -= x;
      if (nn > 0) {
        ans2 += (2 * cur);
      } else {
        ans2 += cur;
      }
      j -= x;
    }
    ans = min(ans1, ans2);
    cout << ans << "\n";
  }
  return 0;
}
