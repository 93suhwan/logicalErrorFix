#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
long long INFMAX = 1e16, INFMIN = -1e18;
const long long N = 2e5 + 7;
void peace(long long tc) {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  map<char, long long> mp;
  for (long long i = 0; i < n; i++) {
    mp[s[i]]++;
    if (s[i] != '2' && s[i] != '3' && s[i] != '7' && s[i] != '5') {
      cout << 1 << "\n";
      cout << s[i] << "\n";
      return;
    }
  }
  for (auto x : mp) {
    if (x.second > 1) {
      cout << 2 << "\n";
      cout << x.first << x.first << "\n";
      return;
    }
  }
  string temp = "";
  if (n > 2) {
    long long ind = 0;
    for (auto x : s) {
      if (x == '2' || x == '5') {
        if (ind) {
          cout << 2 << "\n";
          cout << s[0] << x << "\n";
          return;
        }
      }
      ind++;
    }
    if (mp.count('2') && mp.count('7')) {
      cout << 2 << "\n";
      cout << 27 << "\n";
      return;
    }
    if (mp.count('5') && mp.count('7')) {
      cout << 2 << "\n";
      cout << 57 << "\n";
      return;
    }
  }
  cout << n << "\n";
  cout << s << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    peace(i);
  }
}
