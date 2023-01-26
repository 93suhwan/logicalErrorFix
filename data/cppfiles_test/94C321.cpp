#include <bits/stdc++.h>
using namespace std;
int findXOR(int n) {
  int mod = n % 4;
  if (mod == 0)
    return n;
  else if (mod == 1)
    return 1;
  else if (mod == 2)
    return n + 1;
  else if (mod == 3)
    return 0;
}
bool ispfs(long double x) {
  if (x >= 0) {
    long long sr = sqrt(x);
    return (sr * sr == x);
  }
  return false;
}
int findXOR(int l, int r) { return (findXOR(l - 1) ^ findXOR(r)); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long int n = s.length();
    long long int t1 = 0, t2 = 0;
    for (long long int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        t1 = t1 * 10 + (s[i] - '0');
      } else {
        t2 = t2 * 10 + (s[i] - '0');
      }
    }
    cout << (t1 + 1) * (t2 + 1) - 2 << '\n';
  }
}
