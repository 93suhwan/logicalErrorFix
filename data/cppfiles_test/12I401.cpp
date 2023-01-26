#include <bits/stdc++.h>
using namespace std;
void input() {
  long long int n, m, k;
  cin >> n >> m >> k;
  if (m == 1 && k > 0) {
    cout << "NO\n";
    return;
  }
  if (n % 2) {
    if ((k * 2) % m != 0) {
      cout << "NO\n";
      return;
    } else {
      int x = (k * 2) / m;
      if (x % 2 == 0) {
        cout << "NO\n";
        return;
      }
    }
  } else {
    if (k % 2) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    input();
  }
  return 0;
}
