#include <bits/stdc++.h>
using namespace std;
const long long int oo = 1e18;
const long long int mod = 1e9 + 7;
const int base = 31;
const int tx[4] = {-1, 0, 1, 0};
const int ty[4] = {0, 1, 0, -1};
const long long int maxN = 70000 + 5;
const long long int maxM = 8 * 4e5 + 5;
const long long int block = 700;
bool solve() {
  string s;
  cin >> s;
  int n = s.length();
  s = " " + s;
  if (n % 2) {
    return false;
  }
  string t1 = "";
  string t2 = "";
  for (long long int i = 1; i <= (n / 2); i++) t1 += s[i];
  for (long long int i = n / 2 + 1; i <= (n); i++) t2 += s[i];
  return t1 == t2;
}
int main() {
  {
    ios::sync_with_stdio(false);
    cin.tie(0);
  };
  int t = 1;
  cin >> t;
  while (t--)
    if (solve())
      cout << "YES\n";
    else
      cout << "NO\n";
  return 0;
}
