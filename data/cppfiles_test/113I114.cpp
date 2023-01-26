#include <bits/stdc++.h>
using namespace std;
int solve() {
  long long int x1, p1, x2, p2;
  cin >> x1 >> p1 >> x2 >> p2;
  long long int a1 = x1;
  long long int a2 = x2;
  while (a1 >= 10) {
    a1 /= 10;
    p1++;
  }
  while (a2 >= 10) {
    a2 /= 10;
    p2++;
  }
  if (p1 == p2) {
    if (a1 > a2) {
      cout << ">" << endl;
    }
    if (a1 < a2) {
      cout << "<" << endl;
    }
    if (a1 == a2) {
      cout << "=" << endl;
    }
  }
  if (p1 < p2) {
    cout << "<" << endl;
  }
  if (p1 > p2) {
    cout << ">" << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
