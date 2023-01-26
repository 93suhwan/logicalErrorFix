#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long T;
  cin >> T;
  while (T--) {
    map<long long, long long> mp;
    long long n, k, score = 0;
    cin >> n >> k;
    vector<long long> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    long long i = 0, j = n - 1;
    long long sc = 0;
    while (k--) {
      if (j >= 1 and a[i] >= a[j - 1] / a[j]) {
        sc += a[j - 1] / a[j];
        j -= 2;
      } else {
        i++;
        j--;
      }
    }
    long long p = i, q = j;
    while (i <= j) {
      sc += a[i++];
      sc += a[j--];
    }
    i = p;
    j = q;
    if (i <= j and (j - i) % 2 == 0) sc -= a[(j - i) / 2];
    cout << sc << "\n";
  }
  return 0;
}
