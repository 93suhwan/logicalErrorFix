#include <bits/stdc++.h>
using namespace std;
template <class T, class T1>
T1 power(T1 a, T b) {
  if (!b) return 1;
  T1 y = 1;
  while (b > 1) {
    if (b & 1) y *= a;
    a *= a;
    b = b >> 1;
  }
  return a * y;
}
template <class T>
T gcd(T a, T b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
void seive(vector<int>& prime, int n) {
  vector<bool> trace(n + 1, false);
  for (int i = 2; i * i <= n; i++) {
    if (trace[i]) continue;
    for (int j = 2 * i; j <= n; j += i) {
      if (!trace[j]) trace[j] = true;
    }
  }
  for (int i = 2; i < n; i++)
    if (!trace[i]) prime.push_back(i);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int res = INT_MAX;
    for (int x = 'a'; x <= 'z'; x++) {
      int i = 0, j = n - 1, help = 0;
      while (i <= j) {
        if (s[i] == s[j]) {
          i++;
          j--;
          help--;
        } else if (s[i] == x)
          i++;
        else if (s[j] == x)
          j--;
        else {
          help = INT_MAX;
          break;
        };
        help++;
      }
      res = min(res, help);
    }
    if (res == INT_MAX) res = -1;
    cout << res << "\n";
  }
  return 0;
}
