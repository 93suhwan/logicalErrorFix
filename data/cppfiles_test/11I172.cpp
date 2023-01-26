#include <bits/stdc++.h>
using namespace std;
long long d = 0;
bool compare1(pair<long long, long long> v1, pair<long long, long long> v2) {
  return (1.0 * v1.first / v1.second) > (1.0 * v2.first / v2.second);
}
bool compare2(pair<long long, long long> v1, pair<long long, long long> v2) {
  return (v1.second < v2.second);
}
int main() {
  long long t;
  cin >> t;
  while (t > 0) {
    long long n;
    string s;
    cin >> n;
    vector<vector<pair<long long, long long>>> a;
    vector<long long> b;
    long long m[5];
    for (int i = 0; i < 5; i++) {
      m[i] = 0;
      a.push_back({{0, 0}});
    }
    long long total = 0;
    for (int i = 0; i < n; i++) {
      cin >> s;
      b.assign(6, 0);
      for (int j = 0; j < s.length(); j++) {
        b[s[j] - 97] += 1;
        m[s[j] - 97] += 1;
        total++;
      }
      b[5] = s.length();
      for (int i = 0; i < 5; i++) {
        a[i].push_back({b[i], b[5]});
      }
      b.clear();
    }
    long long ans[5];
    for (int i = 0; i < 5; i++) {
      ans[i] = 0;
    }
    for (int i = 0; i < 5; i++) {
      stable_sort(a[i].begin() + 1, a[i].end(), compare2);
      stable_sort(a[i].begin() + 1, a[i].end(), compare1);
      d++;
      long long mq = 0, mm = 0;
      long long j = 0;
      while (j < n) {
        if (mq + a[i][j + 1].second - a[i][j + 1].first <
            mm + a[i][j + 1].first) {
          mq += a[i][j + 1].second - a[i][j + 1].first;
          mm += a[i][j + 1].first;
          ans[i]++;
        }
        j++;
      }
    }
    long long max = ans[0];
    for (int i = 0; i < 5; i++) {
      if (ans[i] > max) {
        max = ans[i];
      }
    }
    cout << max << "\n";
    t--;
  }
  return 0;
}
