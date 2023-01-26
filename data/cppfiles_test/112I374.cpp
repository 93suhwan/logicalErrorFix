#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b, c, m;
    cin >> a >> b >> c >> m;
    if (a > m || b > m || c > m) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    cout << '\n';
  }
}
