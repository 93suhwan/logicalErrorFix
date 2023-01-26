#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e5 + 5;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k, j;
    cin >> n >> k;
    long long int i;
    vector<long long int> pv, nv;
    for (i = 0; i < n; i++) {
      long long int x;
      cin >> x;
      if (x >= 0) {
        pv.push_back(x);
      } else {
        nv.push_back(0 - x);
      }
    }
    sort(nv.begin(), nv.end());
    sort(pv.begin(), pv.end());
    long long int l1 = nv.size();
    long long int l2 = pv.size();
    long long int sum = 0;
    if (l2 != 0 && l1 == 0) {
      sum += pv[l2 - 1];
      for (j = l2 - k - 1; j >= 0;) {
        sum += 2 * pv[j];
        j -= k;
      }
    } else if (l1 != 0 && l2 == 0) {
      sum += nv[l1 - 1];
      for (j = l1 - k - 1; j >= 0;) {
        sum += 2 * nv[j];
        j -= k;
      }
    } else if (nv[l1 - 1] > pv[l2 - 1]) {
      if (l2 != 0) {
        for (j = l2 - 1; j >= 0;) {
          sum += 2 * pv[j];
          j -= k;
        }
      }
      sum += nv[l1 - 1];
      for (j = l1 - k - 1; j >= 0;) {
        sum += 2 * nv[j];
        j -= k;
      }
    } else if (nv[l1 - 1] <= pv[l2 - 1]) {
      if (l1 != 0) {
        for (j = l1 - 1; j >= 0;) {
          sum += 2 * nv[j];
          j -= k;
        }
      }
      sum += pv[l2 - 1];
      for (j = l2 - k - 1; j >= 0;) {
        sum += 2 * pv[j];
        j -= k;
      }
    }
    cout << sum << endl;
  }
  return 0;
}
