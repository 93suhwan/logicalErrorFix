#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
void slove() {
  int n, m, k;
  cin >> n >> m >> k;
  int ls = 0;
  if (n % 2) {
    n--, ls += m / 2;
  }
  if (m % 2) m--;
  int flag = 1;
  if (ls > k) flag = 0;
  ls += (n * m) / 2;
  if (ls < k) flag = 0;
  if (ls % 2 != k % 2) flag = 0;
  if (flag)
    puts("YES");
  else
    puts("NO");
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    slove();
  }
  return 0;
}
