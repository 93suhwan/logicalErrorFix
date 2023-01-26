#include <bits/stdc++.h>
using namespace std;
bool prime(long long x) {
  if (x == 2) {
    return true;
  }
  if (x <= 1) {
    return false;
  }
  for (int i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}
void printv(vector<long long> v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}
string Y = "YES\n";
string N = "NO\n";
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  for (int pop = 0; pop < t; pop++) {
    long long q, k;
    cin >> q >> k;
    long long ans = 0;
    long long one, two, three, four;
    long long first, last;
    long long c1;
    cin >> c1;
    for (int i = 0; i < c1; i++) {
      long long el;
      cin >> el;
      if (i == 0) {
        first = el;
      } else {
        last = el;
      }
    }
    ans = max(ans, (last - first) * k);
    cin >> c1;
    for (int i = 0; i < c1; i++) {
      long long el;
      cin >> el;
      if (i == 0) {
        first = el;
      } else {
        last = el;
      }
    }
    ans = max(ans, (last - first) * k);
    cin >> c1;
    for (int i = 0; i < c1; i++) {
      long long el;
      cin >> el;
      if (i == 0) {
        first = el;
      } else {
        last = el;
      }
    }
    ans = max(ans, (last - first) * q);
    cin >> c1;
    for (int i = 0; i < c1; i++) {
      long long el;
      cin >> el;
      if (i == 0) {
        first = el;
      } else {
        last = el;
      }
    }
    ans = max(ans, (last - first) * q);
    cout << ans << endl;
  }
  return 0;
}
