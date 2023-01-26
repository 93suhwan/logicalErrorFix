#include <bits/stdc++.h>
using namespace std;
int func(vector<long long> q, vector<long long> v) {
  for (long long i = 0; i < q.size(); i++) {
    long long j;
    long long c = 0;
    for (j = 0; j < v.size(); j++) {
      if (i + j >= q.size()) break;
      if (v[j] != q[i + j]) break;
    }
    if (j != v.size()) {
      continue;
    }
    if (j == v.size()) {
      for (long long k = 0; k < i; k++) {
        if (q[k] == 0) {
          c = 1;
          break;
        }
      }
      for (long long k = i + j; k < q.size(); k++) {
        if (q[k] == 0) {
          c = 1;
          break;
        }
      }
    }
    if (c == 0) {
      return 1;
    }
  }
  for (long long i = q.size() - 1; i >= 0; i--) {
    long long j;
    long long c = 0;
    for (j = 0; j < v.size(); j++) {
      if (i - j < 0) break;
      if (v[j] != q[i - j]) break;
    }
    if (j != v.size()) {
      continue;
    }
    if (j == v.size()) {
      for (long long k = q.size() - 1; k > i; k--) {
        if (q[k] == 0) {
          c = 1;
          break;
        }
      }
      for (long long k = i - j; k >= 0; k--) {
        if (q[k] == 0) {
          c = 1;
          break;
        }
      }
    }
    if (c == 0) {
      return 1;
    }
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    long long x, y;
    cin >> x >> y;
    vector<long long> v;
    vector<long long> q;
    while (x) {
      v.push_back(x % 2);
      x /= 2;
    }
    while (y) {
      q.push_back(y % 2);
      y /= 2;
    }
    if (q[0] == 1) {
      func(q, v) == 1 ? cout << "YES" : cout << "NO";
      cout << "\n";
      continue;
    }
    reverse(v.begin(), v.end());
    v.push_back(1);
    long long ans = 0;
    ans = func(q, v);
    if (ans == 1) {
      cout << "YES"
           << "\n";
      continue;
    }
    v.pop_back();
    while (v[v.size() - 1] == 0) {
      v.pop_back();
    }
    ans = func(q, v);
    if (ans == 1) {
      cout << "YES"
           << "\n";
      continue;
    } else
      cout << "NO"
           << "\n";
  }
  return 0;
}
