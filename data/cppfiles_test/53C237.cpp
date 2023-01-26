#include <bits/stdc++.h>
using namespace std;
inline void setIO(string);
long long n, k;
int solve() {
  cin >> n >> k;
  pair<long long, long long> arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i].first;
  pair<long long, long long> a[n];
  for (int i = 0; i < n; i++) {
    a[i].first = arr[i].first;
    a[i].second = i;
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    long long index = a[i].second;
    arr[index].second = i;
  }
  long long count = 1;
  for (int i = 1; i < n; i++) {
    long long index = arr[i].second;
    long long prev = arr[i - 1].first;
    if (index == 0) {
      count++;
      continue;
    }
    if (prev != a[index - 1].first) count++;
  }
  if (k >= count)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
inline void setIO(string name = "") {}
