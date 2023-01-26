#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<long long, long long> &p1, pair<long long, long long> &p2) {
  if (p1.first == p2.first) return p1.second > p2.second;
  return p1.first < p2.first;
}
void solve() {
  long long n;
  cin >> n;
  vector<pair<long long, long long> > v;
  for (long long i = 1; i <= n; i++) {
    long long a, b;
    cin >> a >> b;
    v.push_back({a, b});
  }
  sort(v.begin(), v.end(), cmp);
  for (long long i = 0; i < n; i++) {
    long long left = v[i].first, right = v[i].second;
    long long curr = left;
    if (left == right) {
      cout << left << " " << right << " " << left << endl;
      continue;
    }
    bool flag = false;
    for (long long j = i + 1; j < n; j++) {
      long long xx = v[j].first, yy = v[j].second;
      if (xx >= left && yy <= right) {
        if (curr >= xx && curr <= yy)
          curr = yy + 1;
        else {
          flag = true;
          cout << left << " " << right << " " << curr << endl;
          break;
        }
      }
    }
    if (!flag) cout << left << " " << right << " " << curr << endl;
  }
}
int main() {
  long long test;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
