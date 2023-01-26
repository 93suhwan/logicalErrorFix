#include <bits/stdc++.h>
using namespace std;
void prepareIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(std::numeric_limits<double>::max_digits10);
}
struct HASH {
  size_t operator()(const pair<long long int, long long int>& x) const {
    return hash<long long>()(x.first ^ (x.second) << 32);
  }
};
const long long int MOD = 1e9 + 7;
const long long int N = 1e5 + 5;
int main() {
  prepareIO();
  long long int t = 1;
  cin >> t;
  for (long long int Case = 1; Case <= t; Case++) {
    long long int n;
    cin >> n;
    vector<long long int> a(n);
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<long long int>());
    double p = a[0], q = 0.0;
    for (long long int i = 1; i < n; i++) {
      q += a[i];
    }
    q /= (n - 1);
    p += q;
    cout << fixed << setprecision(9) << p << "\n";
  }
  return 0;
}
