#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long h = 1;
  long long prev = -1;
  vector<long long> days(n, 0);
  for (long long i = 0; i < n; i++) {
    cin >> days[i];
  }
  for (long long i = 0; i < n; i++) {
    if (days[i] == 0 && (i > 0 && days[i - 1] == 0)) {
      cout << "-1\n";
      return;
    } else if (days[i] == 1 && (i > 0 && days[i - 1] == 1)) {
      h += 5;
    } else if (days[i] == 1) {
      h += 1;
    }
  }
  cout << h << "\n";
}
int main() {
  long long t;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    solve();
  }
}
