#include <bits/stdc++.h>
using namespace std;
void hehe() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
  }
  if (v[0] % 2 == 0) {
    cout << "NO\n";
  } else
    cout << "YES\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) hehe();
  return 0;
}
