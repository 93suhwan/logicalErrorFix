#include <bits/stdc++.h>
using namespace std;
long long q, n;
string h;
int main() {
  ios::sync_with_stdio(NULL);
  cin.tie(0);
  cout.tie(0);
  cin >> q;
  while (q--) {
    cin >> n;
    if (n == 1) {
      cout << "a\n";
      continue;
    }
    for (long long i = 1; i <= n / 2; i++) cout << "a";
    cout << ((n % 2 == 0) ? "b" : "bc");
    for (long long i = 1; i <= n / 2 - 1; i++) cout << "a";
    cout << "\n";
  }
}
