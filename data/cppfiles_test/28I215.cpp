#include <bits/stdc++.h>
using namespace std;
void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
bool cmp(int a, int b) { return a > b; }
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a > b && a > c) {
    int d = a;
    a = c;
    c = d;
  } else if (b > c) {
    int d = b;
    b = c;
    c = d;
  }
  if (a > b) {
    int d = a;
    a = b;
    b = d;
  }
  cout << max(b - a, c - b);
}
int main() {
  fastio();
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
  return 0;
}
