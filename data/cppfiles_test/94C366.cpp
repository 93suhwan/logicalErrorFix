#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int nc = n, i = 0, s1 = 0, s2 = 0, p1 = 0, p2 = 0;
  while (nc) {
    if (i % 2 == 0) {
      s1 += (nc % 10) * pow(10, p1);
      p1++;
    } else {
      s2 += (nc % 10) * pow(10, p2);
      p2++;
    }
    nc /= 10;
    i++;
  }
  if (s2 == 0) {
    cout << s1 - 1 << '\n';
  } else {
    cout << (s1 + 1) * (s2 + 1) - 2 << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) solve();
}
