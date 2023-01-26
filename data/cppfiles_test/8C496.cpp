#include <bits/stdc++.h>
using namespace std;
const long long MXX = 1e7;
void kajelag() {
  int n;
  cin >> n;
  int c1 = n / 3;
  int c2 = n - c1;
  if (c2 % 2)
    cout << c1 + 1 << " " << c2 / 2 << "\n";
  else
    cout << c1 << " " << c2 / 2 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    kajelag();
  }
  return 0;
}
