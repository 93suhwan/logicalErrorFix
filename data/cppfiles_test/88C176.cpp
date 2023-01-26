#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265;
void FIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
bool cmp(pair<string, long long int>& a, pair<string, long long int>& b) {
  return a.second < b.second;
}
bool cmp1(pair<long long int, pair<long long int, long long int>>& a,
          pair<long long int, pair<long long int, long long int>>& b) {
  return a.second.second < b.second.second;
}
void solve() {
  long long int n;
  cin >> n;
  long long int a[n];
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n % 2 == 0) {
    cout << "YES" << endl;
  } else {
    long long int t = 0;
    for (long long int i = 0; i < n - 1; i++) {
      if (a[i] >= a[i + 1]) {
        t = 1;
      }
    }
    if (t == 1) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
int main() {
  FIO();
  long long int t;
  cin >> t;
  while (t--) solve();
}
