#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
vector<long long> arr;
long long n;
bool bs(long long mid) {
  vector<long long> extra(n);
  for (long long i = n - 1; i >= 2; i--) {
    long long diff = min(arr[i], extra[i] + arr[i] - mid);
    if (diff < 0)
      return false;
    else {
      long long x = diff / 3;
      extra[i - 1] += x;
      extra[i - 2] += 2 * x;
    }
  }
  for (long long i = 0; i < 2; i++) {
    if (arr[i] + extra[i] < mid) return false;
  }
  return true;
}
void solve() {
  cin >> n;
  arr.resize(n);
  for (long long i = 0; i < n; i++) cin >> arr[i];
  long long beg = 1, end = 1e9;
  while (beg < end) {
    vector<long long> give(n), extra(n);
    long long mid = (beg + end) / 2;
    if (beg + 1 == end) {
      if (bs(end))
        beg = end;
      else
        end = beg;
    } else {
      if (bs(mid))
        beg = mid;
      else
        end = mid - 1;
    }
  }
  cout << beg << '\n';
}
int main() {
  fast();
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
