#include <bits/stdc++.h>
using namespace std;
map<pair<long long, long long>, bool> m;
map<pair<long long, long long>, long long> a;
void solve(long long start, long long end, long long extra, long long n,
           vector<pair<long long, long long>> &v) {
  if (n == 1) {
    v.push_back({start, end});
    return;
  }
  solve(start, extra, end, n - 1, v);
  v.push_back({start, end});
  solve(extra, end, start, n - 1, v);
  return;
}
void get(long long start, long long end) {
  if (start == end) {
    a[{start, end}] = end;
    return;
  }
  for (long long i = start; i <= end; i++) {
    if (i == end) {
      if (m[{start, i - 1}]) {
        a[{start, end}] = i;
        get(start, i - 1);
        break;
      }
    } else if (i == start) {
      if (m[{i + 1, end}]) {
        a[{start, end}] = i;
        get(i + 1, end);
        break;
      }
    } else {
      if (m[{start, i - 1}] && m[{i + 1, end}]) {
        a[{start, end}] = i;
        get(start, i - 1);
        get(i + 1, end);
        break;
      }
    }
  }
}
void solve2(long long start, long long end, long long extra, long long n,
            vector<pair<long long, long long>> &v) {
  if (n == 1) {
    v.push_back({start, end});
    return;
  }
  solve(start, extra, end, n - 1, v);
  v.push_back({start, end});
  solve(extra, end, start, n - 1, v);
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long tc;
  cin >> tc;
  while (tc--) {
    m.clear();
    a.clear();
    long long n;
    cin >> n;
    vector<pair<long long, long long>> v(n);
    for (long long i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    for (long long i = 0; i < n; i++) {
      m[{v[i].first, v[i].second}] = true;
    }
    long long start = 1;
    long long end = n;
    get(start, end);
    for (auto i : m) {
      if (a[i.first]) {
        cout << i.first.first << " " << i.first.second << " " << a[i.first]
             << "\n";
      }
    }
    cout << "\n";
  }
  return 0;
}
