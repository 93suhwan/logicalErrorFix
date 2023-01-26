#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
long long t, n, anss, ans, bal, sum, m, k, ver;
vector<long long> v;
string second[N];
int get(char ch) { return (int)(ch - 'a' + 1); }
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    ans = 0;
    if (!n % 2 && !m % 2) {
      cout << "YES" << endl;
      continue;
    }
    if (n % 2) {
      if (m / 2 > k || (k - m / 2) % 2 == 1) {
        cout << "NO" << endl;
        continue;
      }
      cout << "Yes" << endl;
      continue;
    }
    ver = (n * m) / 2;
    ver -= k;
    if (m % 2) {
      if (n / 2 > ver || (ver - n / 2) % 2 == 1) {
        cout << "NO" << endl;
        continue;
      }
      cout << "YES" << endl;
      continue;
    }
    cout << "YES" << endl;
  }
}
