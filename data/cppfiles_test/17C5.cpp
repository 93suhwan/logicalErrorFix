#include <bits/stdc++.h>
using namespace std;
void solve(long long _case) {
  long long n;
  cin >> n;
  vector<vector<long long>> a(n, vector<long long>(5));
  long long index = 0;
  for (auto& athlete : a) {
    for (auto& pos : athlete) {
      cin >> pos;
    }
    ++index;
    athlete.push_back(index);
  }
  sort(a.begin(), a.end(), [&](vector<long long>& v1, vector<long long>& v2) {
    long long win = 0;
    for (long long k{}; k < 5; ++k) {
      if (v1[k] < v2[k])
        ++win;
      else
        --win;
    }
    return win > 0;
  });
  for (long long i{1}; i < n; ++i) {
    long long win = 0;
    for (long long j{}; j < 5; ++j) {
      if (a[0][j] < a[i][j])
        ++win;
      else
        --win;
    }
    if (win <= 0) {
      cout << -1 << '\n';
      return;
    }
  }
  cout << a[0][5] << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  for (long long _case{1}; _case <= t; ++_case) {
    solve(_case);
  }
  return 0;
}
