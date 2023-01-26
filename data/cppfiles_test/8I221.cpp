#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
void work() {
  int n;
  cin >> n;
  if (n % 3 == 0) {
    int x = n / 3;
    cout << n << " " << n;
  } else if (n % 3 == 1) {
    int x = n / 3;
    cout << x + 1 << " " << x;
  } else {
    int x = n / 3;
    cout << x << " " << x + 1;
  }
}
signed main() {
  fast();
  long long t;
  cin >> t;
  while (t--) {
    work();
    cout << "\n";
  }
  return 0;
}
