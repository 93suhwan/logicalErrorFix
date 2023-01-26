#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;
const long double pi = 2 * acos(0.0);
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
const int e = 1e5 + 5;
void solve() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  unordered_map<char, int> map;
  string s;
  cin >> s;
  string a[2] = {"YES", "NO"};
  int g = 1;
  for (int i = 0; i < s.length(); ++i) {
    map[s[i]]++;
  }
  if (map['A'] and map['B']) {
    while ((map['A'] > 0) and (map['B'] > 0)) {
      map['A']--;
      map['B']--;
    }
    if (map['B'] == map['C'])
      g = 0;
    else
      g = 1;
  } else {
    while ((map['C'] >= 1) or (map['B'] >= 1)) {
      map['C']--;
      map['B']--;
    }
    if (map['B'] == map['A'])
      g = 0;
    else
      g = 1;
  }
  cout << a[g] << endl;
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
