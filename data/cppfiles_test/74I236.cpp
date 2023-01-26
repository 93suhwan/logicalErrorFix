#include <bits/stdc++.h>
using namespace std;
void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long a, b;
vector<long long> v;
int32_t main() {
  fastio();
  long long t;
  cin >> t;
  while (t--) {
    v.clear();
    cin >> a >> b;
    for (long long i = 0; i <= a + b; i++) {
      if ((a + b) % 2 == 0) {
        long long f = (b - a + 2 * i);
        bool cond = (f % 4 == 0) && (f / 4 >= 0 && f / 4 <= i) && f / 4 <= b &&
                    (i - f / 4) <= a;
        if (cond) {
          v.push_back(i);
        }
      } else {
        long long f = (b - a + 1 + 2 * i);
        long long g = (b - a - 1 + 2 * i);
        bool cond =
            (((f % 4 == 0 && f / 4 <= i && f / 4 <= b && (i - f / 4) <= a) ||
              (g % 4 == 0 && (g / 4 <= i))) &&
             f / 4 <= b && (i - f / 4) <= a);
        if (cond) {
          v.push_back(i);
        }
      }
    }
    cout << v.size() << '\n';
    for (long long i = 0; i < v.size(); i++) {
      cout << v[i] << " ";
    }
    cout << '\n';
  }
}
