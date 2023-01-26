#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
const long long int inf = 1e18;
bool check(vector<long long int> &in, long long int ht) {
  vector<long long int> cap = (*new vector<long long int>(in));
  vector<long long int> tot = cap;
  long long int n = (int)((in).size());
  for (long long int i = n - 1; i >= 2; i--) {
    long long int unit1 = (tot[i] - ht) / 3;
    long long int unit2 = (cap[i]) / 3;
    if (unit1 < 0) {
      return false;
    }
    if (tot[i] < ht) return false;
    long long int unit = min(unit1, unit2);
    tot[i] -= 3 * unit;
    tot[i - 1] += unit;
    tot[i - 2] += 2 * unit;
  }
  if (tot[1] < ht) return false;
  if (tot[0] < ht) return false;
  return true;
}
int main() {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  };
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> in(n);
    ;
    for (long long int i = 0; i < n; i++) cin >> in[i];
    ;
    long long int l = 0;
    long long int r = inf;
    while (l < r) {
      long long int mid = (l + r + 1) / 2;
      if (check(in, mid)) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    cout << l << "\n";
  }
}
