#include <bits/stdc++.h>
using namespace std;
const long long N = 2 * 1e6 + 1;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long _ = 1; _ <= t; _++) {
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++) {
      cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (long long i = 1; i < n / 2 + 1; i++)
      cout << v[i] << " " << v[0] << "\n";
  }
}
