#include <bits/stdc++.h>
using namespace std;
long long int dx[] = {1, -1, 1, -1, 0, -1, 0, 1};
long long int dy[] = {1, -1, -1, 1, 1, 0, -1, 0};
long double PI = acosl(-1);
long long int i = 0, j = 0, c = 0, mx = 0, n = 0, w, h, d = 0, k = 0, s = 0,
              f = 0, sum = 0, mid, t = 0, m = 0, l = 0, r = 0, x = 0, y = 0, u;
void input() {
  cin >> n;
  if (n % 2 == 0 and n % 4 == 0)
    cout << "2 4" << endl;
  else if (n % 3 == n % 2)
    cout << "3 2" << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  t = 1;
  cin >> t;
  while (t--) {
    input();
  }
  return 0;
}
