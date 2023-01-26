#include <bits/stdc++.h>
using namespace std;
using namespace std;
long long int factorial(long long int n) {
  if (n == 1 || n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}
void solve();
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
void solve() {
  long long int a, b;
  cin >> a >> b;
  if (a == b) {
    cout << (a + b) / 2 + 1 << endl;
    for (long long int i = 0; i <= a + b; i = i + 2) {
      cout << i << " ";
    }
    cout << endl;
  } else {
    long long int mini = min(a, b);
    map<long long int, long long int> mp1;
    vector<long long int> v;
    if (mini > 0) {
      for (long long int i = 0; i <= a; i = i + 2) {
        mp1[i]++;
        if (mp1[i] == 1) {
          v.push_back(i);
        }
      }
    }
    long long int diff = abs(b - a);
    for (long long int i = 0; i <= a; i = i + 2) {
      if (diff % 2 == 0) {
        mp1[i + ((diff) / 2)]++;
        if (mp1[i + ((diff) / 2)] == 1) {
          v.push_back(i + ((diff) / 2));
        }
      } else {
        mp1[i + ((diff) / 2)]++;
        mp1[i + 1 + ((diff) / 2)]++;
        if (mp1[i + ((diff) / 2)] == 1) {
          v.push_back(i + ((diff) / 2));
        }
        if (mp1[i + 1 + ((diff) / 2)] == 1) {
          v.push_back(i + 1 + ((diff) / 2));
        }
      }
    }
    cout << v.size() << endl;
    sort(v.begin(), v.end());
    for (long long int i = 0; i < v.size(); i++) {
      cout << v[i] << " ";
    }
    cout << endl;
  }
}
