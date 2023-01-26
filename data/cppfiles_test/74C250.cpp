#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  string str, str2;
  long long elm, tc, n, m;
  cin >> tc;
  while (tc--) {
    cin >> n >> m;
    if (n == 0) {
      if (m % 2 == 0)
        cout << 1 << endl << m / 2 << endl;
      else
        cout << 2 << endl << m / 2 << " " << m / 2 + 1 << endl;
    } else if (m == 0) {
      if (n % 2 == 0)
        cout << 1 << endl << n / 2 << endl;
      else
        cout << 2 << endl << n / 2 << " " << n / 2 + 1 << endl;
    } else if (n == m) {
      cout << (n + m) / 2 + 1 << endl;
      for (long long x = 0; x <= (n + m); x += 2) cout << x << " ";
      cout << endl;
    } else {
      if ((n + m) % 2 == 0) {
        long long start = (n + m) / 2;
        long long son = start + min(n, m);
        start -= min(n, m);
        queue<long long> q;
        for (long long x = start; x <= son; x += 2) q.push(x);
        cout << q.size() << endl;
        while (!q.empty()) {
          cout << q.front() << " ";
          q.pop();
        }
        cout << endl;
      } else {
        long long start = (n + m) / 2;
        long long son = start + 1 + min(n, m);
        start -= min(n, m);
        queue<long long> q;
        for (long long x = start; x <= son; x++) q.push(x);
        cout << q.size() << endl;
        while (!q.empty()) {
          cout << q.front() << " ";
          q.pop();
        }
        cout << endl;
      }
    }
  }
  return 0;
}
