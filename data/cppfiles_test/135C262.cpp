#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> vect(n);
    long long i;
    for (i = 0; i < n; i++) {
      cin >> vect[i];
    }
    sort(vect.begin(), vect.end(), greater<long long>());
    map<long long, long long> make_pair;
    for (i = 0; i < 2 * k; i++) {
      make_pair[vect[i]]++;
    }
    long long ans = 0;
    long long maxi = 0;
    long long other = 0;
    for (auto c : make_pair) {
      if (c.second > k) {
        maxi = c.second;
      } else {
        other += c.second;
      }
    }
    if (maxi > 0) {
      ans += (maxi - other) / 2;
    }
    for (i = 2 * k; i < n; i++) {
      ans += vect[i];
    }
    cout << ans << '\n';
  }
  return 0;
}
