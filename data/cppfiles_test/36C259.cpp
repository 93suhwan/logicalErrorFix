#include <bits/stdc++.h>
using namespace std;
const long long int MAX = LLONG_MAX;
const int N = 1e5 + 10;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << "a\n";
    } else if (n % 2 == 0) {
      for (int i = 1; i <= n / 2 - 1; i++) cout << 'a';
      cout << 'b';
      for (int i = 1; i <= n / 2; i++) cout << 'a';
      cout << "\n";
    } else {
      for (int i = 1; i <= n / 2 - 1; i++) cout << 'a';
      cout << 'b';
      for (int i = 1; i <= n / 2; i++) cout << 'a';
      cout << "c\n";
    }
  }
  return 0;
}
