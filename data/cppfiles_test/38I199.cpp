#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long n;
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    long long x = n / 10;
    int r = n % 10;
    long long ans = x * 25;
    if (r == 9)
      ans += 25;
    else if (r > 0 && r <= 6)
      ans += 15;
    else
      ans += 20;
    x = n / 8;
    r = n % 8;
    long long ans1 = x * 20;
    if (r == 7)
      ans1 += 20;
    else if (r > 0 && r <= 6)
      ans1 += 15;
    x = n / 6;
    r = n % 6;
    long long ans2 = x * 15;
    if (r > 0 && r < 6) ans2 += 15;
    cout << min(min(ans, ans1), ans2) << endl;
  }
}
