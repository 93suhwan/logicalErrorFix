#include <bits/stdc++.h>
using namespace std;
bool intersect(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first > b.first) swap(a, b);
  return a.second > b.first && a.second < b.second;
}
void iluzn() {
  long long n, k;
  map<long long, bool> used;
  cin >> n >> k;
  vector<pair<long long, long long>> chord;
  for (long long i = 0; i < k; i++) {
    long long a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    chord.push_back({a, b});
    used[a] = 1, used[b] = 1;
  }
  vector<long long> unused;
  for (long long i = 1; i <= 2 * n; i++)
    if (!used[i]) unused.push_back(i);
  for (long long i = 0; i < n - k; i++) {
    chord.push_back({unused[i], unused[n - k + i]});
  }
  long long ans = 0;
  for (long long i = 0; i < n - 1; i++) {
    for (long long j = i + 1; j < n; j++) {
      if (intersect(chord[i], chord[j])) ans++;
    }
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) iluzn();
  return 0;
}
