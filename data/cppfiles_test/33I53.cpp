#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int txtc;
  cin >> txtc;
  while (txtc--) {
    long long int n;
    cin >> n;
    vector<long long int> v;
    for (long long int i = 0; i < n; i++) {
      long long int x;
      cin >> x;
      v.push_back(x);
    }
    long long int totmax = 0;
    for (long long int i = 1; i < n; i++) {
      long long int maxele = max(v[i], v[i - 1]);
      if (maxele > totmax) {
        totmax = maxele;
      }
    }
    long long int totmin = 0;
    for (long long int i = 1; i < n; i++) {
      long long int minele = min(v[i], v[i - 1]);
      if (minele > totmin) {
        totmin = minele;
      }
    }
    cout << totmax * totmin << "\n";
  }
  return 0;
}
