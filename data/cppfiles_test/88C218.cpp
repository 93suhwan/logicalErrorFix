#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[";
  for (int i = 0; i < (int)v.size(); ++i) {
    os << v[i];
    if (i != (int)v.size() - 1) os << ", ";
  }
  os << "]\n";
  return os;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
  os << "[";
  os << p.first;
  os << ", ";
  os << p.second;
  os << "]";
  return os;
}
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
long long binpow(long long a, long long b, long long p) {
  if (b == 0) return 1;
  long long t = binpow(a, b / 2, p);
  if (b % 2)
    return (((a * t) % p) * t) % p;
  else
    return ((t * t) % p);
}
void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  if (n % 2 == 0) {
    cout << "Yes\n";
    return;
  }
  for (int i = 1; i < n; i++) {
    if (arr[i] <= arr[i - 1]) {
      cout << "Yes\n";
      return;
    }
  }
  cout << "No\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
