#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    int a, b = 0;
    int tmp = n / 3;
    a = b = tmp;
    if (n % 3 == 1) a++;
    if (n % 3 == 2) b++;
    cout << a << " " << b << endl;
  }
  return 0;
}
