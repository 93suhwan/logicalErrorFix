#include <bits/stdc++.h>
using namespace std;
bool isPrime(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) return false;
  }
  return true;
}
void solve() {
  int k;
  cin >> k;
  string s;
  cin >> s;
  map<int, int> mp;
  bool found = false;
  for (char c : s) {
    int d = c - '0';
    if (d == 1 or d == 4 or d == 6 or d == 8 or d == 9) {
      cout << 1 << endl;
      cout << d << endl;
      return;
    }
    mp[d]++;
  }
  for (pair<int, int> d : mp) {
    int cnt = d.second;
    int dig = d.first;
    if (cnt > 1) {
      cout << 2 << endl;
      cout << dig << dig << endl;
      return;
    }
  }
  for (int i = 0; i < s.size(); i++) {
    for (int j = i + 1; j < s.size(); j++) {
      int d1 = s[i] - '0', d2 = s[j] - '0';
      int n = d1 * 10 + d2;
      if (isPrime(n)) continue;
      cout << 2 << endl;
      cout << d1 << d2 << endl;
      return;
    }
  }
  for (int i = 0; i < s.size(); i++) {
    for (int j = i + 1; j < s.size(); j++) {
      for (int k = j + 1; k < s.size(); k++) {
        int d1 = s[i] - '0', d2 = s[j] - '0', d3 = s[k] - '0';
        int n = d1 * 100 + d2 * 10 + d3;
        if (isPrime(n)) continue;
        cout << 3 << endl;
        cout << d1 << d2 << d3 << endl;
        return;
      }
    }
  }
  for (int i = 0; i < s.size(); i++) {
    for (int j = i + 1; j < s.size(); j++) {
      for (int k = j + 1; k < s.size(); k++) {
        for (int l = k + 1; l < s.size(); l++) {
          int d1 = s[i] - '0', d2 = s[j] - '0', d3 = s[k] - '0',
              d4 = s[l] - '0';
          int n = d1 * 1000 + d2 * 100 + d3 * 10 + d4;
          if (isPrime(n)) continue;
          cout << 4 << endl;
          cout << d1 << d2 << d3 << d4 << endl;
          return;
        }
      }
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
