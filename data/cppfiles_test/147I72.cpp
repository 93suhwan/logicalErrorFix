#include <bits/stdc++.h>
using namespace std;
vector<int> factors(int n) {
  vector<int> f;
  for (int x = 2; x * x <= n; x++) {
    while (n % x == 0) {
      f.push_back(x);
      n /= x;
    }
  }
  if (n > 1) f.push_back(n);
  return f;
}
long long int power(long long int x, long long int y) {
  long long int res = 1;
  while (y > 0) {
    if (y & 1) res = res % 1000000007 * x % 1000000007;
    y = y >> 1;
    x = x % 1000000007 * x % 1000000007;
  }
  return res;
}
bool palindrome(const string &s) {
  int n = s.length();
  for (int i = 0; i < n; i++) {
    if (s[i] != s[n - i - 1]) return false;
  }
  return true;
}
void answer() {
  string s;
  cin >> s;
  long long int s1 = s.size();
  bool ok = true;
  for (int i = 0; i < s1 - 1; i++) {
    if (s[i] != 'E')
      ok = false;
    else
      break;
  }
  if (ok) {
    if (s[s1 - 1] == 'N') {
      cout << "NO"
           << "\n";
      return;
    } else {
      cout << "YES"
           << "\n";
      return;
    }
  } else {
    cout << "YES"
         << "\n";
    return;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) answer();
}
