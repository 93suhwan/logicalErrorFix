#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    long long n;
    cin >> n;
    long long P[n];
    for (long long j = 0; j < n; j++) {
      cin >> P[j];
    }
    string s;
    cin >> s;
    long long Q[n];
    for (long long j = 0; j < n; j++) {
      if (s[j] == '0')
        Q[j] = P[j];
      else if (s[j] == '1')
        Q[j] = P[j] + 1;
    }
    for (long long j = 0; j < n; j++) {
      cout << Q[j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
