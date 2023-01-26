#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long alice, bob;
  cin >> alice >> bob;
  long long n = alice + bob;
  if (n == 1) {
    cout << "2\n0 1\n";
    return;
  }
  set<long long> ans;
  {
    long long a = alice;
    long long b = bob;
    long long p = min(a, b);
    long long a_end = 1e9;
    long long b_end = 1e9;
    for (long long i = 1; i <= n; i++) {
      if (i % 2) {
        if (b) {
          b--;
        } else {
          a--;
        }
        if (!b) {
          b_end = min(b_end, i);
        }
      } else {
        if (a) {
          a--;
        } else {
          b--;
        }
        if (!a) {
          a_end = min(a_end, i);
        }
      }
    }
    long long st = (n - 2 * p) / 2 + (a_end < b_end && (n - 2 * p) % 2 == 1);
    for (long long k = st; k <= st + 2 * p; k += 2) {
      ans.insert(k);
    }
  }
  {
    long long a = alice;
    long long b = bob;
    long long p = min(a, b);
    long long a_end = 1e9;
    long long b_end = 1e9;
    for (long long i = 1; i <= n; i++) {
      if (!(i % 2)) {
        if (b) {
          b--;
        } else {
          a--;
        }
        if (!b) {
          b_end = min(b_end, i);
        }
      } else {
        if (a) {
          a--;
        } else {
          b--;
        }
        if (!a) {
          a_end = min(a_end, i);
        }
      }
    }
    long long st = (n - 2 * p) / 2 + (a_end > b_end && (n - 2 * p) % 2 == 1);
    for (long long k = st; k <= st + 2 * p; k += 2) {
      ans.insert(k);
    }
  }
  cout << ans.size() << '\n';
  for (auto& x : ans) {
    cout << x << ' ';
  }
  cout << '\n';
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
