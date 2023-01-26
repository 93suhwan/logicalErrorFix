#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long a[N];
bool is_prime(long long x) {
  if (x < 2) return false;
  for (int i = 2; i <= x / i; i++)
    if (x % i == 0) return false;
  return true;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    bool flag = true;
    if (a[1] % 2 == 0) flag = false;
    if (flag)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
