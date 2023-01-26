#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
void solve();
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
}
void solve() {
  string a, b;
  long long p1, p2;
  cin >> a >> p1 >> b >> p2;
  long long a1 = a.length();
  long long a2 = b.length();
  a1 = a1 + p1;
  a2 = a2 + p2;
  if (a1 > a2) {
    cout << ">";
  } else if (a1 < a2) {
    cout << "<";
  } else if (a1 == a2) {
    long long n = a.length();
    long long n1 = b.length();
    if (p1 > p2) {
      while (p1 > p2) {
        a += "0";
        p1--;
      }
    } else if (p1 < p2) {
      while (p1 < p2) {
        b += "0";
        p2--;
      }
    }
    if (a > b) {
      cout << ">";
    } else if (a < b) {
      cout << "<";
    } else {
      cout << "=";
    }
  }
}
