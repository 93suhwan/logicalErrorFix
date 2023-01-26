#include <bits/stdc++.h>
using namespace std;
void Ammar_Yasser() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  cout.tie(0);
}
int main() {
  Ammar_Yasser();
  int t;
  cin >> t;
  while (t--) {
    int c = 0;
    int n;
    cin >> n;
    c += (int)sqrt(n);
    c += (int)cbrt(n);
    c -= (int)sqrt(cbrt(n));
    cout << c << '\n';
  }
}
