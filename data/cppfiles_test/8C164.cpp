#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int dx8[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy8[8] = {1, -1, 0, 1, -1, 1, -1, 0};
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long c1 = n / 3, c2 = n / 3;
    if (n - (c1 + 2 * c2) == 1)
      c1++;
    else if (n - (c1 + 2 * c2) == 2)
      c2++;
    cout << c1 << ' ' << c2 << endl;
  }
  return 0;
}
