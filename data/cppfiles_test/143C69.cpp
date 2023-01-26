#include <bits/stdc++.h>
using namespace std;
long long const mod = 1e9 + 7, N = 2e5 + 7, OO = 1e12 + 7;
long double const PI = 3.14159265358979323846;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
void test() {
  long long a[N] = {}, n, x, h = 0;
  queue<long long> sol;
  priority_queue<long long> d;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    a[x]++;
  }
  for (int i = 0; i <= n; i++) {
    if (a[i] == 0) {
      sol.push(h);
      if (d.size() && d.top() < i) {
        h += i - d.top();
        d.pop();
      } else
        break;
    } else if (a[i] > 1) {
      sol.push(h + a[i]);
      while (a[i] > 1) {
        d.push(i);
        a[i]--;
      }
    } else
      sol.push(h + 1);
  }
  long long c = 0;
  while (sol.size()) {
    cout << sol.front() << ' ';
    c++;
    sol.pop();
  }
  while (c <= n) {
    cout << -1 << ' ';
    c++;
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) test();
  return 0;
}
