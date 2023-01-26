#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7, INF = 1e18;
const double PI = acos(-1);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long test = 1; test <= t; test++) {
    long long n, m, k;
    cin >> n >> m >> k;
    long long val = n / m, val2 = n % m;
    if (val2 == 0) {
      for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
          cout << val << " ";
          for (int l = 1; l <= val; l++) {
            cout << j * val + l << " ";
          }
          cout << "\n";
          ;
        }
      }
      continue;
    }
    int last = 0;
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < val2; j++) {
        cout << val + 1 << " ";
        for (int l = 0; l <= val; l++) {
          cout << last + 1 << " ";
          last = (last + 1) % n;
        }
        cout << "\n";
        ;
      }
      int last2 = last;
      for (int j = val2; j < m; j++) {
        cout << val << " ";
        for (int l = 0; l < val; l++) {
          cout << last2 + 1 << " ";
          last2 = (last2 + 1) % n;
        }
        cout << "\n";
        ;
      }
    }
  }
  return 0;
}
