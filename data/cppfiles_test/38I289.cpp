#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n % 2) {
      n += 1;
    }
    long long ans = 0;
    ans = (n / 10) * 25;
    n = n % 10;
    ans += (n / 8) * 20;
    n = n % 8;
    ans += (n / 6) * 15;
    n = n % 6;
    if (n > 0) {
      ans += 15;
    }
    cout << ans << endl;
  }
}
