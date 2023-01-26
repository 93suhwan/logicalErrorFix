#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
void test() {
  long long n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  long long top = 0, down = 0, left = 0, right = 0, hori = 0, verti = 0;
  for (long long i = 0; i < s.length(); i++) {
    if (left + right + 1 >= m) break;
    if (s[i] == 'L') hori--;
    if (s[i] == 'R') hori++;
    (hori > 0) ? right = max(right, hori) : left = max(left, abs(hori));
  }
  for (long long i = 0; i < s.length(); i++) {
    if (top + down + 1 >= n) break;
    if (s[i] == 'D') verti++;
    if (s[i] == 'U') verti--;
    (verti > 0) ? down = max(down, verti) : top = max(top, abs(verti));
  }
  cout << top + 1 << " " << left + 1 << endl;
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) test();
  return 0;
}
