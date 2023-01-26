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
  long long int x, y;
  cin >> x >> y;
  if (x > y) {
    long long int z = x + y;
    cout << z << endl;
  } else if (x == y) {
    cout << x << endl;
  } else {
    cout << (y / x) * x + (y % x) / 2 << endl;
  }
}
int main() {
  FIO();
  long long int t;
  cin >> t;
  while (t--) solve();
}
