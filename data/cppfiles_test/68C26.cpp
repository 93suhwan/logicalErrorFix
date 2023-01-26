#include <bits/stdc++.h>
using namespace std;
long long T, n, x, s, px, py;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> T;
  while (T--) {
    cin >> n;
    if (sqrt(n) == floor(sqrt(n)))
      x = n;
    else
      x = (sqrt(n) + 1), x *= x;
    s = sqrt(x);
    px = 1, py = s;
    while (px != s && x > n) px++, x--;
    while (py > 1 && x > n) py--, x--;
    cout << py << " " << px << '\n';
  }
}
