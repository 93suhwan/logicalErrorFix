#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
const int MAXN = 4e4 + 2;
int t, n;
int a[MAXN];
int b[MAXN];
long long int sum;
bool flag;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    sum = 0;
    flag = false;
    for (int j = 0; j < n; j++) {
      cin >> b[j];
      sum += b[j];
    }
    if (sum % ((n + 1) * n / 2))
      cout << "NO"
           << "\n";
    else {
      sum = sum / ((n + 1) * n / 2);
      for (int j = 0; j < n; j++) {
        if ((b[j] + sum) % n) {
          cout << "NO"
               << "\n";
          flag = true;
          break;
        }
        a[j] = (b[j] + sum) / n;
      }
      if (!flag) {
        cout << "YES"
             << "\n";
        for (int j = 0; j < n; j++) {
          cout << a[j] << " ";
        }
        cout << "\n";
      }
    }
  }
}
