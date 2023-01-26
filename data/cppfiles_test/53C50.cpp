#include <bits/stdc++.h>
using namespace std;
const long long logN = 20;
const long long M = 1000000007;
const long long INF = 1e18;
const long long N = 100005;
void solve() {
  long long n, k;
  cin >> n >> k;
  long long arr[n];
  for (long long i = 0; i <= n - 1; i++) {
    cin >> arr[i];
  }
  int c = 0;
  for (long long i = 1; i <= n - 1; i++) {
    if (arr[i - 1] > arr[i]) c++;
  }
  if (c > k) {
    cout << "NO";
    return;
  }
  if (c == 0) {
    cout << "YES";
    return;
  }
  c = 0;
  set<long long> m;
  map<long long, long long> s;
  for (long long i = 0; i <= n - 1; i++) {
    m.insert(arr[i]);
    s[arr[i]] = i;
  }
  for (auto i = m.begin(); i != m.end(); i++) {
    if (i == m.begin()) {
      c++;
      continue;
    }
    long long t1 = *i;
    auto j = i;
    j--;
    long long t2 = *j;
    if (s[t1] - 1 != s[t2]) {
      c++;
    }
  }
  if (c > k) {
    cout << "NO";
  } else {
    cout << "YES";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
