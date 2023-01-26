#include <bits/stdc++.h>
const int M = 1e9 + 7;
using namespace std;
int gcd(int x, int y) { return (y == 0) ? x : gcd(y, x % y); }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
bool checkPrime(int n) {
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
bool is_sqr(int x) {
  int y = (int)(sqrt(x) + 0.5);
  return y * y == x;
}
int power(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b % 2 != 0) res = (res * a % M) % M;
    a = (a % M * a % M) % M;
    b = b >> 1;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    string s, t;
    cin >> s >> t;
    map<char, long long> mp;
    for (int i = 0; i < s.size(); i++) {
      mp[s[i]]++;
    }
    if (t == "abc") {
      if (mp['a'] && mp['b'] && mp['c']) {
        while (mp['a']--) {
          cout << "a";
        }
        while (mp['c']--) {
          cout << "c";
        }
        while (mp['b']--) {
          cout << "b";
        }
        for (auto it : mp) {
          if (it.second > 0) cout << it.first;
        }
        cout << endl;
      } else {
        sort(s.begin(), s.end());
        cout << s << endl;
        continue;
      }
    } else {
      sort(s.begin(), s.end());
      cout << s << endl;
      continue;
    }
  }
  return 0;
}
