#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b, c;
  cin >> a >> b;
  c = a;
  a--;
  if (a % 4 == 0)
    a = a;
  else if (a % 4 == 1)
    a = 1;
  else if (a % 4 == 2)
    a++;
  else
    a = 0;
  if (a == b)
    cout << c << endl;
  else if ((a ^ b) == c)
    cout << c + 2 << endl;
  else
    cout << c + 1 << endl;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
