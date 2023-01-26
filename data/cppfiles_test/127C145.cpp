#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
const int N = 1e5 + 5;
const long long int mod = 1e9 + 7;
const long long int inf = 1e17;
const long double PI = (acos(-1));
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    string s, t;
    cin >> s >> t;
    map<char, int> mp;
    for (char ch : s) {
      ++mp[ch];
    }
    string res = "";
    int a = mp['a'], b = mp['b'], c = mp['c'];
    while (mp['a']--) {
      res += 'a';
    }
    if (t == "abc" && a > 0 && b > 0 && c > 0) {
      while (mp['c']--) {
        res += 'c';
      }
      while (mp['b']--) {
        res += 'b';
      }
    } else {
      while (mp['b']--) {
        res += 'b';
      }
      while (mp['c']--) {
        res += 'c';
      }
    }
    for (pair<char, int> p : mp) {
      while (p.second > 0) {
        res += p.first;
        --p.second;
      }
    }
    cout << res << endl;
  }
}
