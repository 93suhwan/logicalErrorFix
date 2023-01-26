#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int main() {
  fast();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n % 2 == 0 || n == 1) {
      double c1 = n / 3;
      double c2 = (n - c1) / 2;
      cout << ceil(c1) << " " << ceil(c2) << '\n';
    } else {
      double c1 = (n - 2) / 3;
      double c2 = (n - c1) / 2;
      cout << ceil(c1) << " " << floor(c2) << '\n';
    }
  }
  return 0;
}
