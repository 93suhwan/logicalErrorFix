#include <bits/stdc++.h>
using namespace std;
using namespace std;
long long arr[100] = {0};
bool cool(long long n, long long cur, long long w) {
  if (w == 0) return true;
  if (n == cur) {
    if (n == 0)
      return false;
    else
      return cool(n - 1, cur, w);
  }
  if (n == 0) {
    return (w == arr[n] || w == -arr[n]);
  }
  return cool(n - 1, cur, w - arr[n]) || cool(n - 1, cur, w + arr[n]) ||
         cool(n - 1, cur, w);
}
int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long alive[105] = {0};
    for (int i = 0; i <= 2 * n; i++) alive[i] = 1;
    vector<pair<long long, long long> > pears;
    pair<long long, long long> input;
    for (int i = 0; i < k; i++) {
      cin >> input.first >> input.second;
      pears.push_back(make_pair(min(input.first, input.second),
                                max(input.first, input.second)));
      alive[input.first] = 0;
      alive[input.second] = 0;
    }
    long long s = 1, e = 1;
    for (int i = 0; i < n - k; i++) {
      e++;
      while (alive[e] == 0) e++;
    }
    while (alive[e] == 0) e++;
    while (k < n) {
      while (alive[s] == 0) s++;
      alive[s] = 0;
      while (alive[e] == 0) e++;
      pears.push_back(make_pair(s, e));
      k++;
      alive[e] = 0;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        long long cnt = 0;
        if (pears[i].first < pears[j].first && pears[j].first < pears[i].second)
          cnt++;
        if (pears[i].first < pears[j].second &&
            pears[j].second < pears[i].second)
          cnt++;
        if (cnt == 1) {
          ans++;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
