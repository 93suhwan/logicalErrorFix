#include <bits/stdc++.h>
using namespace std;
long long t, a, b;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long s;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    if (b % 2 == 1) {
      s = b / 2;
      if (b - s >= a)
        cout << s << '\n';
      else if (b - s < a)
        cout << b - a << '\n';
    } else {
      s = b / 2 - 1;
      if (b - s >= a)
        cout << s << '\n';
      else if (b - s < a)
        cout << b - a << '\n';
    }
  }
}
