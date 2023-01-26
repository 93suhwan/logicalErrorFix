#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long a[N], primes[N], cnt;
bool st[N];
void get_primes(int n) {
  for (int i = 2; i <= n; i++) {
    if (st[i]) continue;
    primes[cnt++] = i;
    for (int j = i + i; j <= n; j += i) st[j] = true;
  }
}
int main() {
  int t;
  cin >> t;
  get_primes(N);
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    bool flag = true;
    for (int i = 1; i <= n; i++) {
      bool k = false;
      for (int j = 0; primes[j] <= i + 1; j++) {
        if (a[i] % primes[j] == 0) {
          k = true;
          i--;
          n--;
          break;
        }
      }
      if (k == false) {
        flag = false;
        break;
      }
    }
    if (flag)
      puts("NO");
    else
      puts("YES");
  }
  return 0;
}
