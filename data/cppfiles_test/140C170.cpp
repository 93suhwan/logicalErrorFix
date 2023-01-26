#include <bits/stdc++.h>
using namespace std;
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    if (n == 1) {
      cout << 1 << endl;
      continue;
    }
    long long int ans = 0;
    long long int num = 2;
    unordered_map<long long int, long long int> saved;
    while (1) {
      long long int square = num * num;
      long long int cube = num * num * num;
      if (square > n) {
        break;
      }
      if (square == n) {
        if (saved[square] == 0) {
          saved[square] = 1;
          ans++;
        }
        break;
      }
      if (square < n) {
        if (saved[square] == 0) {
          saved[square] = 1;
          ans++;
        }
      }
      if (cube > n) {
        ;
      } else {
        if (cube <= n) {
          if (saved[cube] == 0) {
            saved[cube] = 1;
            ans++;
          }
        }
      }
      num++;
    }
    cout << ans + 1 << endl;
  }
  return 0;
}
