#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e10 + 7;
struct ed {
  long long first, second, z;
};
long long t, n, m, s, e;
pair<long long, long long> a[300005], b[300005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    priority_queue<pair<long long, long long> > pq;
    long long s = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i].first;
      a[i].second = i + 1;
      s += a[i].first;
    }
    sort(a, a + n);
    if (s - a[n - 1].first <= a[n - 1].first) {
      cout << s - a[n - 1].first << '\n';
      for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < a[i].first; j++)
          cout << a[i].second << ' ' << a[n - 1].second << '\n';
      }
    } else {
      long long l = 0, r = 1;
      vector<pair<long long, long long> > v;
      for (int i = 0; i < s - a[n - 1].first * 2; i += 2) {
        while (!a[r].first) r++;
        while (!a[l].first) {
          l++;
          if (l == r) r++;
        }
        a[r].first--, a[l].first--;
        v.push_back({l + 1, r + 1});
      }
      for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < a[i].first; j++)
          v.push_back({a[i].second, a[n - 1].second});
      }
      cout << v.size() << '\n';
      for (int i = 0; i < v.size(); i++)
        cout << v[i].first << ' ' << v[i].second << '\n';
    }
  }
}
