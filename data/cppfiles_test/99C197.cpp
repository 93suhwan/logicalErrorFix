#include <bits/stdc++.h>
using namespace std;
void my_dbg() { cout << endl; }
template <typename Arg, typename... Args>
void my_dbg(Arg A, Args... B) {
  cout << ' ' << A;
  my_dbg(B...);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long s, n;
    cin >> s >> n;
    if (s % 2 == 0) {
      if (n % 4 == 0)
        cout << s << endl;
      else if (n % 4 == 1) {
        cout << s - n << endl;
      } else if (n % 4 == 2) {
        cout << s + 1 << endl;
      } else {
        cout << s + 1 + n << endl;
      }
    } else {
      if (n % 4 == 0)
        cout << s << endl;
      else if (n % 4 == 1) {
        cout << s + n << endl;
      } else if (n % 4 == 2) {
        cout << s - 1 << endl;
      } else {
        cout << s - 1 - n << endl;
      }
    }
  }
  return 0;
}
