#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<pair<long long, long long>> v;
    bool exs[2 * n + 1];
    for (long long i = 1; i <= 2 * n; i++) exs[i] = false;
    for (long long i = 0; i < k; i++) {
      long long a, b;
      cin >> a >> b;
      if (a > b) swap(a, b);
      v.push_back({a, b});
      exs[a] = true;
      exs[b] = true;
    }
    vector<long long> rem;
    for (long long i = 1; i <= 2 * n; i++)
      if (!exs[i]) rem.push_back(i);
    for (long long i = 0; i < n - k; i++) {
      v.push_back({rem[i], rem[i + n - k]});
    }
    long long ans = 0;
    sort(v.begin(), v.end());
    for (long long i = 0; i < n; i++) {
      for (long long j = i + 1; j < n; j++) {
        if (v[i].second < v[j].second && v[i].second > v[j].first) ans++;
      }
    }
    cout << ans;
    cout << "\n";
  }
  return 0;
}
