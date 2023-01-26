#include <bits/stdc++.h>
using namespace std;
inline void setIO(string);
int solve() {
  long long n, k;
  cin >> n >> k;
  long long arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  pair<long long, long long> a[n];
  for (int i = 0; i < n; i++) {
    a[i].first = arr[i];
    a[i].second = i;
  }
  sort(a, a + n);
  long long count = 0;
  for (int i = 1; i < n; i++) {
    long long index = a[i].second;
    long long prev = a[i - 1].first;
    if (index == 0) {
      count++;
      continue;
    }
    if (prev != arr[index - 1]) count++;
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
