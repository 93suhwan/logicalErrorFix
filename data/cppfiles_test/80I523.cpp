#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 998244353;
bool isPrime(int number) {
  if (number < 2) return false;
  if (number == 2) return true;
  if (number % 2 == 0) return false;
  for (int i = 3; (i * i) <= number; i += 2) {
    if (number % i == 0) return false;
  }
  return true;
}
void solve() {
  int k;
  string s;
  cin >> k;
  cin >> s;
  vector<int> hash(10, 0);
  for (auto x : s) hash[x - '0']++;
  if (hash[9] || hash[8] || hash[6] || hash[4] || hash[1]) {
    cout << 1 << endl;
    if (hash[9])
      cout << 9;
    else if (hash[8])
      cout << 8;
    else if (hash[6])
      cout << 6;
    else if (hash[4])
      cout << 4;
    else
      cout << 1;
    cout << endl;
    return;
  }
  reverse((s).begin(), (s).end());
  for (int i = 12; i < 100; i++) {
    if (!isPrime(i)) {
      string t = to_string(i);
      int i = 0, flag = 0;
      for (i = 0; i < s.length(); i++) {
        if (s[i] == t[1]) {
          flag++;
          i++;
          break;
        }
      }
      for (; i < s.length(); i++) {
        if (s[i] == t[0]) {
          flag++;
          break;
        }
      }
      if (flag == 2) {
        cout << 2 << endl << t << endl;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
