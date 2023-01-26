#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    int counts[2];
    counts[0] = counts[1] = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i] %= 2;
      counts[a[i]]++;
    }
    if (abs(counts[0] - counts[1]) != 0 && abs(counts[0] - counts[1]) != 1) {
      cout << "-1\n";
      continue;
    } else if (counts[0] == counts[1]) {
      int b[n];
      vector<pair<int, int> > v;
      int ans1, ans2;
      ans1 = 0;
      for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
          b[i] = 0;
        else
          b[i] = 1;
      }
      for (int i = 0; i < n; i++) {
        if (a[i] != b[i] && v.size() == 0) {
          v.push_back(make_pair(a[i], i));
        } else if (a[i] != b[i]) {
          if (a[i] == v[v.size() - 1].first) {
            v.push_back(make_pair(a[i], i));
          } else {
            ans1 += (i - v[v.size() - 1].second);
            v.pop_back();
          }
        }
      }
      ans2 = 0;
      for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
          b[i] = 1;
        else
          b[i] = 0;
      }
      for (int i = 0; i < n; i++) {
        if (a[i] != b[i] && v.size() == 0) {
          v.push_back(make_pair(a[i], i));
        } else if (a[i] != b[i]) {
          if (a[i] == v[v.size() - 1].first) {
            v.push_back(make_pair(a[i], i));
          } else {
            ans2 += (i - v[v.size() - 1].second);
            v.pop_back();
          }
        }
      }
      cout << min(ans1, ans2) << "\n";
    } else {
      int b[n];
      vector<pair<int, int> > v;
      int ans1, ans2;
      ans1 = ans2 = 0;
      if (counts[0] > counts[1]) {
        for (int i = 0; i < n; i++) {
          if (i % 2 == 0)
            b[i] = 0;
          else
            b[i] = 1;
        }
      } else {
        for (int i = 0; i < n; i++) {
          if (i % 2 == 0)
            b[i] = 1;
          else
            b[i] = 0;
        }
      }
      for (int i = 0; i < n; i++) {
        if (a[i] != b[i] && v.size() == 0) {
          v.push_back(make_pair(a[i], i));
        } else if (a[i] != b[i]) {
          if (a[i] == v[v.size() - 1].first) {
            v.push_back(make_pair(a[i], i));
          } else {
            ans2 += (i - v[v.size() - 1].second);
            v.pop_back();
          }
        }
      }
      cout << ans2 << "\n";
    }
  }
}
