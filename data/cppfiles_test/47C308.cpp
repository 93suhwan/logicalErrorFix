#include <bits/stdc++.h>
#pragma pack(1)
#pragma GCC target("avx,avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    long long int a[n];
    for (long long int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    sort(a, a + n);
    vector<long long int> pos, neg;
    for (long long int i = 0; i < n; ++i) {
      if (a[i] > 0) pos.push_back(a[i]);
      if (a[i] < 0) neg.push_back(a[i]);
    }
    for (long long int i = 0; i < neg.size(); ++i) {
      neg[i] = -neg[i];
    }
    reverse(neg.begin(), neg.end());
    long long int sum = 0;
    if (pos.size() > 0) {
      for (long long int i = pos.size() - 1; i >= 0; i = i - k) {
        sum += pos[i];
      }
    }
    if (neg.size() > 0) {
      for (long long int i = neg.size() - 1; i >= 0; i = i - k) {
        sum += neg[i];
      }
    }
    long long int x = 0, y = 0;
    if (pos.size() > 0) x = a[n - 1];
    if (neg.size() > 0) y = -a[0];
    long long int temp = max(x, y);
    cout << (2 * sum) - temp << endl;
  }
  return 0;
}
