#include <bits/stdc++.h>
using namespace std;
void Senior() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
int main() {
  Senior();
  int t;
  cin >> t;
  while (t--) {
    int n, a = 0, b = 0;
    cin >> n;
    while (n--) {
      int x;
      cin >> x;
      if (x == 1)
        a++;
      else if (x == 0)
        b++;
    }
    if (b > 0)
      cout << a * b * 2 << endl;
    else
      cout << a << endl;
  }
  return 0;
}
