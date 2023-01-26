#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string str[2];
    cin >> str[0];
    cin >> str[1];
    bool ans = false;
    for (int i = 0; i < n; i++)
      if (str[0][i] == '1' && str[1][i] == '1') ans = true;
    if (!ans)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
