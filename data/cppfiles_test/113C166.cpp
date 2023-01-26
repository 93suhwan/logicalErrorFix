#include <bits/stdc++.h>
using namespace std;
const int N = 6e5 + 100;
const long long int mod = 1e9 + 7;
const int inf = 1e9;
const long long int base = 313;
int get(int x) {
  int res = 0;
  while (x) {
    res++;
    x /= 10;
  }
  return res;
}
void solve() {
  int a, b, p1, p2;
  cin >> a >> p1 >> b >> p2;
  int x = get(a), y = get(b);
  if (x + p1 > y + p2) {
    cout << '>' << endl;
    return;
  }
  if (x + p1 < y + p2) {
    cout << '<' << endl;
    return;
  }
  for (int i = 0; i < x - y; i++) {
    b *= 10;
    p2--;
  }
  for (int i = 0; i < y - x; i++) {
    a *= 10;
    p1--;
  }
  if (a > b) {
    cout << '>' << endl;
  }
  if (a < b) {
    cout << '<' << endl;
    return;
  }
  if (a == b) {
    cout << '=' << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int q;
  cin >> q;
  while (q--) {
    solve();
  }
  return 0;
}
