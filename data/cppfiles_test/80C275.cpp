#include <bits/stdc++.h>
using namespace std;
bool is_prime(int x) {
  if (x < 2) return false;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) return false;
  }
  return true;
}
void run_ass() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  s = "#" + s;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '0') {
      if (n / 2 < i) {
        cout << i - n / 2 << " " << i << " ";
        cout << i - n / 2 << " " << i - 1 << endl;
        return;
      } else {
        cout << i << " " << i + n / 2 << " ";
        cout << i + 1 << " " << i + n / 2 << endl;
        return;
      }
    }
  }
  cout << 1 << " " << n - (n % 2) << " ";
  cout << 1 << " " << n / 2 << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  int t = 1;
  cin >> t;
  while (t--) run_ass();
  return 0;
}
