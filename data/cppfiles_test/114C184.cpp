#include <bits/stdc++.h>
const long long N = 1000000007;
using namespace std;
bool com(pair<long long, long long> p1, pair<long long, long long> p2) {
  return (p1.second < p2.second);
}
void kal() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) cin >> v[i];
  sort((v).begin(), (v).end());
  long long x = floor(n / 2);
  long long i = 0, j = n - 1;
  while (x != 0) {
    cout << v[j] << " " << v[i] << endl;
    x--;
    j--;
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  long long t = 1;
  cin >> t;
  while (t--) {
    kal();
  }
  return 0;
}
