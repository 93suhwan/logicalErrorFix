#include <bits/stdc++.h>
using namespace std;
const long long OO = 0x3f3f3f3f;
const double pi = 3.14159265359;
void skrrrt() { ios_base::sync_with_stdio(0), cin.tie(0); }
void solve() {
  int n, k;
  cin >> n >> k;
  map<int, int> mp1, mp2;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x > 0)
      mp1[x]++;
    else {
      x = -x;
      mp2[x]++;
    }
  }
  vector<pair<int, int>> v1, v2, v11, v22;
  for (auto i : mp1) {
    v1.emplace_back(i.first, i.second);
    v11.emplace_back(i.first, i.second);
  }
  for (auto i : mp2) {
    v2.emplace_back(i.first, i.second);
    v22.emplace_back(i.first, i.second);
  }
  reverse(v1.begin(), v1.end());
  reverse(v2.begin(), v2.end());
  reverse(v11.begin(), v11.end());
  reverse(v22.begin(), v22.end());
  long long ans1 = 0;
  bool frst = 1;
  int cary = k;
  if (!v1.empty()) {
    int pos = v1[0].first;
    for (int i = 0; i < v1.size();) {
      if (v1[i].second <= cary) {
        cary -= v1[i].second;
        i++;
        continue;
      } else {
        v1[i].second -= cary;
        cary = k;
        if (frst)
          ans1 += pos;
        else
          ans1 += 2 * pos;
        frst = 0;
        pos = v1[i].first;
      }
    }
    if (frst)
      ans1 += pos;
    else {
      ans1 += 2 * pos;
    }
  }
  cary = k;
  if (!v2.empty()) {
    int pos = v2[0].first;
    for (int i = 0; i < v2.size();) {
      if (v2[i].second <= cary) {
        cary -= v2[i].second;
        i++;
        continue;
      } else {
        v2[i].second -= cary;
        cary = k;
        ans1 += 2 * pos;
        pos = v2[i].first;
      }
    }
    ans1 += 2 * pos;
  }
  long long ans2 = 0;
  v1 = v11, v2 = v22;
  frst = 1;
  cary = k;
  if (!v2.empty()) {
    int pos = v2[0].first;
    for (int i = 0; i < v2.size();) {
      if (v2[i].second <= cary) {
        cary -= v2[i].second;
        i++;
        continue;
      } else {
        v2[i].second -= cary;
        cary = k;
        if (frst)
          ans2 += pos;
        else
          ans2 += 2 * pos;
        frst = 0;
        pos = v2[i].first;
      }
    }
    if (frst)
      ans2 += pos;
    else
      ans2 += 2 * pos;
  }
  cary = k;
  if (!v1.empty()) {
    int pos = v1[0].first;
    for (int i = 0; i < v1.size();) {
      if (v1[i].second <= cary) {
        cary -= v1[i].second;
        i++;
        continue;
      } else {
        v1[i].second -= cary;
        cary = k;
        ans2 += 2 * pos;
        pos = v1[i].first;
      }
    }
    ans2 += 2 * pos;
  }
  cout << min(ans1, ans2) << "\n";
}
int main() {
  skrrrt();
  int t;
  cin >> t;
  while (t--) solve();
}
