#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const long long MAXN = 1e5 + 5;
long long a[MAXN];
int main() {
  long long T;
  cin >> T;
  while (T--) {
    vector<long long> vec;
    long long n;
    cin >> n;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] & 1) vec.push_back(i);
    }
    long long ans = INF, flag = true;
    if (n & 1) {
      if (vec.size() == n / 2) {
        long long now = 0;
        for (long long i = 1; i <= n / 2; i++) now += abs(vec[i - 1] - 2 * i);
        ans = min(ans, now);
      } else if (vec.size() == n / 2 + 1) {
        long long now = 0;
        for (long long i = 1; i <= n / 2 + 1; i++)
          now += abs(2 * i - 1 - vec[i - 1]);
        ans = min(ans, now);
      } else
        flag = false;
    } else {
      if (vec.size() == n / 2) {
        long long now = 0;
        for (long long i = 1; i <= n / 2; i++) now += abs(vec[i - 1] - 2 * i);
        ans = min(ans, now);
        now = 0;
        for (long long i = 1; i <= n / 2; i++)
          now += abs(2 * i - 1 - vec[i - 1]);
        ans = min(ans, now);
      } else
        flag = false;
    }
    if (!flag)
      puts("-1");
    else
      cout << ans << endl;
  }
  return 0;
}
