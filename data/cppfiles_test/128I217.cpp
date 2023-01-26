#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int c = 1;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      c = i;
      break;
    }
  }
  n /= c;
  n--;
  int a, b;
  a = b = n / 2;
  while (a == b || a % 2 == 0) {
    a--;
    b++;
  }
  cout << a * c << " " << b * c << " " << c << "\n";
}
int main() {
  { ios_base::sync_with_stdio(false); }
  { cin.tie(NULL); }
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
