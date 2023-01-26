#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e7 + 10;
const long long MAXN1 = 1e9 + 10;
const long long MAXN2 = 2e5 + 7;
const long long M = 1e9 + 7;
const long long MM = 998244353;
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
void solved() {
  string str;
  cin >> str;
  int a = 0, b = 0, c = 0;
  for (int i = 0; i < str.size(); ++i) {
    if (str[i] == 'A')
      a++;
    else if (str[i] == 'B')
      b++;
    else
      c++;
  }
  int maxl = max(a, c);
  int minl = min(a, c);
  if (b - minl == maxl)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solved();
  }
  return 0;
}
