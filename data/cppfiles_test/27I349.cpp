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
    if (n * (n - 1) / 2 < m)
      puts("NO");
    else if (k <= 1)
      puts("NO");
    else if (n == 1 && k > 1)
      puts("YES");
    else if (m == 0 && k > 1)
      puts("YES");
    else if (m == 1 && k > 2)
      puts("YES");
    else if (m == 1 && k <= 2)
      puts("NO");
    else if (m == 2 && k >= 4)
      puts("YES");
    else if (m == 2 && k < 4)
      puts("NO");
    else if (n >= 3 && m >= 3) {
      if (mp[m] && k >= 3)
        puts("YES");
      else if (mp[m] && k < 3)
        puts("NO");
      else if (!mp[m] && k >= 4)
        puts("YES");
      else if (!mp[m] && k < 4)
        puts("NO");
    }
  }
}
