#include <bits/stdc++.h>
using namespace std;
const long long int MAX = 9187201950435737471;
const double pi = acos(-1);
const int N = 150009;
const long long mod = 1000000007;
const int M = 2147483647;
const int lg = 101;
int t, n, m, k;
int main() {
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    n = s.size();
    s += '2';
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] != s[i + 1]) {
        if (s[i] == '0') ans++;
      }
    }
    cout << min(ans, 2) << "\n";
  }
  return 0;
}
