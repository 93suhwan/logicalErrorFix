#include <bits/stdc++.h>
using namespace std;
char nn = '\n';
char ss = ' ';
const long long int mod = 1e9 + 7;
long long int n, m;
bool isprime(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) return false;
  }
  return true;
}
void solve() {
  string s;
  cin >> s;
  map<char, int> mp;
  for (int i = 0; i < s.length(); i++) {
    mp[s[i]]++;
  }
  long long int cnt = 0;
  int n = s.length();
  for (auto i : mp) {
    if (i.second > 2) {
      cnt += 2;
    } else {
      cnt += i.second;
    }
  }
  cout << cnt / 2 << nn;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
