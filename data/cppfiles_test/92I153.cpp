#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const long long MOD = 1000000007;
const long long NO_OPERTATION = -1;
const double eps = 1e-8;
const int MAX = 100010;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t != 0) {
    t--;
    long long n;
    string second;
    cin >> second;
    n = second.size();
    int ab = 0;
    int ba = 0;
    for (int i = 0; i < n - 1; i++) {
      if (second[i] == 'a' and second[i + 1] == 'b') {
        ab++;
      } else if (second[i] == 'b' and second[i + 1] == 'a') {
        ba++;
      }
    }
    if (ab == ba) {
      cout << second << "\n";
      ;
    } else {
      if (ab > ba) {
        for (int i = 0; i < n; i++) {
          if (second[i] == 'b') {
            break;
          } else {
            second[i] = 'b';
          }
        }
      } else {
        for (int i = 0; i < n; i++) {
          if (second[i] == 'a') {
            break;
          } else {
            second[i] = 'a';
          }
        }
      }
      cout << second << "\n";
      ;
    }
  }
  return 0;
}
