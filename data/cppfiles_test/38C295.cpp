#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n < 6)
      cout << "15\n";
    else {
      n = (n + 1) / 2;
      long long a = 15 + (n - 3) * 5;
      cout << a << "\n";
    }
  }
  return 0;
}
