#include <bits/stdc++.h>
using namespace std;
long double pi = 3.1415926535897932;
void evolve() {
  long long int n;
  cin >> n;
  string s;
  cin >> s;
  long long int one = 0;
  long long int zero = 0;
  for (long long int i = 0; i < n - 1; i++) {
    long long int one = 0;
    long long int zero = 0;
    if (s[i] == 'a')
      zero++;
    else
      one++;
    for (long long int j = i + 1; j < n; j++) {
      if (s[j] == 'a')
        zero++;
      else
        one++;
      if (one == zero && one > 0) {
        cout << i + 1 << " " << j + 1 << "\n";
        return;
      }
    }
  }
  cout << -1 << " " << -1 << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    evolve();
  }
  return 0;
}
