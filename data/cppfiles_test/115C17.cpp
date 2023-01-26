#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tests;
  cin >> tests;
  for (int testid = 0; testid < tests; testid++) {
    int n;
    long long h;
    cin >> n >> h;
    vector<int> a;
    for (int i = 0; i < n; i++) {
      int k;
      cin >> k;
      a.push_back(k);
    }
    vector<int> diffs;
    for (int i = 0; i < n - 1; i++) diffs.push_back(a[i + 1] - a[i]);
    long long mink = 0;
    long long maxk = h + 2;
    while (mink < maxk - 1) {
      long long ck = mink / 2 + maxk / 2;
      if (mink % 2 && maxk % 2) ck += 1;
      long long hplost = 0;
      for (int i = 0; i < n - 1; i++) {
        long long toadd = min(ck, long long(diffs[i]));
        if (hplost > LLONG_MAX - toadd)
          hplost = LLONG_MAX;
        else
          hplost += toadd;
      }
      if (hplost > LLONG_MAX - ck)
        hplost = LLONG_MAX;
      else
        hplost += ck;
      if (hplost >= h) {
        maxk = ck;
      } else {
        mink = ck;
      }
    }
    cout << maxk << endl;
  }
}
