#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;
const int MOD = 1000000007;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vi a(n);
    ll s = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      s += (ll)a[i];
    }
    ll c = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
      ll ai = a[i];
      if ((2 * s) % n == 0) {
        ll aj = (2 * s - 2 * ai - (n - 2) * ai) / n;
        c += upper_bound(a.begin() + i + 1, a.end(), aj) -
             lower_bound(a.begin() + i + 1, a.end(), aj);
      }
    }
    cout << c << endl;
  }
  return 0;
}
