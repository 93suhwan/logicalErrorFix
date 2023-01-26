#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
bool vis[100];
bool prime[100];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (int i = 2; i < 100; i++) {
    if (!vis[i]) {
      prime[i] = 1;
      for (int j = i; j < 100; j += i) {
        vis[j] = 1;
      }
    }
  }
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool found = 0;
    for (int i = n / 2; i < n; i++) {
      if (s[i] == '0') {
        cout << "1 " << i + 1 << " 1 " << i << '\n';
        found = 1;
        break;
      }
    }
    if (!found) {
      if (n % 2) {
        cout << n / 2 + 1 << ' ' << n - 1 << ' ';
        cout << n / 2 + 2 << ' ' << n << '\n';
      } else {
        if (s[n / 2 - 1] == '1') {
          cout << n / 2 - 1 << ' ' << n - 1 << ' ';
          cout << n / 2 << ' ' << n << '\n';
        } else {
          cout << n / 2 - 1 << ' ' << n << ' ';
          cout << n / 2 << ' ' << n << '\n';
        }
      }
    }
  }
  return 0;
}
