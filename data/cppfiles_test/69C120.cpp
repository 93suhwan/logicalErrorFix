#include <bits/stdc++.h>
using namespace std;
int solve(string s1, string s2) {
  int n = s1.length(), m = s2.length();
  int i = 0, j = 0, common = 0;
  while (i < n and j < m) {
    if (s1[i] == s2[j]) {
      j++;
      common++;
    }
    i++;
  }
  return ((n - common) + (m - common));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  for (long long int i = 1; i <= t; i++) {
    string n;
    cin >> n;
    int ans = INT_MAX;
    for (long long int j = 1; j <= (long long int)2e18; j *= 2) {
      ans = min(ans, solve(n, to_string(j)));
    }
    cout << ans << "\n";
  }
  return 0;
}
