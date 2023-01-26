#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long t, n;
vector<long long> a;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    a.resize(n);
    for (auto& x : a) cin >> x;
    long long first = -1;
    for (long long i = 0; i < n; i++) first = max(first, a[i]);
    long long second = -1;
    for (long long i = 0; i < n; i++)
      if (a[i] != first) second = max(second, a[i]);
    long long who = -1;
    for (long long i = n - 1; i >= 0; i--) {
      if (a[i] == first) {
        who = 1;
        break;
      }
      if (a[i] == second) {
        who = 2;
        break;
      }
    }
    if (a[n - 1] == first)
      cout << "0\n";
    else if (a[n - 1] == second)
      cout << "1\n";
    else if (who == 1)
      cout << "1\n";
    else
      cout << "2\n";
  }
}
