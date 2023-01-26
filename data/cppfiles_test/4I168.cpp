#include <bits/stdc++.h>
using namespace std;
const int Mxn = 2e5;
int tab[Mxn];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n <= 5) {
      cout << n - 1 << " " << n - 3 << "\n";
    } else {
      cout << n - 1 << " " << n - 2 << "\n";
    }
  }
}
