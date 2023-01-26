#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
unordered_map<int, int> mp;
const int N = 2e5 + 9;
int a[N];
int main() {
  int T;
  cin >> T;
  a[3] = 3;
  mp[3] = 1;
  for (int i = 4; a[i - 1] < 1e9; i++) {
    a[i] = a[i - 1] + (i - 1);
    mp[a[i]] = 1;
  }
  while (T--) {
    long long n, m, k;
    cin >> n >> m >> k;
    if (n == 1 && m == 0 && k >= 2)
      puts("YES");
    else if (m < n)
      puts("NO");
    else if (n * (n - 1) / 2 > m) {
      if (k - 1 > 2)
        puts("NO");
      else
        puts("NO");
    } else if (n * (n - 1) / 2 <= m) {
      if (k - 1 > 1)
        puts("YES");
      else
        puts("NO");
    }
  }
}
