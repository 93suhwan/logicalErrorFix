#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t-- > 0) {
    int n;
    cin >> n;
    string srr[n];
    for (int i = 0; i < n; i++) {
      cin >> srr[i];
    }
    vector<pair<float, int>> afirst(n);
    vector<pair<float, int>> bfirst(n);
    vector<pair<float, int>> cfirst(n);
    vector<pair<float, int>> dfirst(n);
    vector<pair<float, int>> efirst(n);
    for (int i = 0; i < n; i++) {
      int countabc[5] = {0};
      for (int j = 0; j < srr[i].size(); j++) {
        countabc[srr[i][j] - 'a']++;
      }
      afirst[i].first = float(countabc[0]) / srr[i].size();
      if (!countabc[0]) {
        afirst[i].first = 1.0 / (srr[i].size() + 2);
      }
      bfirst[i].first = float(countabc[1]) / srr[i].size();
      if (!countabc[1]) {
        bfirst[i].first = 1.0 / (srr[i].size() + 2);
      }
      cfirst[i].first = float(countabc[2]) / srr[i].size();
      if (!countabc[2]) {
        cfirst[i].first = 1.0 / (srr[i].size() + 2);
      }
      dfirst[i].first = float(countabc[3]) / srr[i].size();
      if (!countabc[3]) {
        dfirst[i].first = 1.0 / (srr[i].size() + 2);
      }
      efirst[i].first = float(countabc[4]) / srr[i].size();
      if (!countabc[4]) {
        efirst[i].first = 1.0 / (srr[i].size() + 2);
      }
      afirst[i].second = i;
      bfirst[i].second = i;
      cfirst[i].second = i;
      dfirst[i].second = i;
      efirst[i].second = i;
    }
    sort(afirst.begin(), afirst.end());
    sort(bfirst.begin(), bfirst.end());
    sort(cfirst.begin(), cfirst.end());
    sort(dfirst.begin(), dfirst.end());
    sort(efirst.begin(), efirst.end());
    int maxi = 0;
    int curr = 0;
    int total = 0;
    for (int i = n - 1; i >= 0; i--) {
      if ((afirst[i].first * srr[afirst[i].second].size()) < 1) {
        afirst[i].first = 0;
      }
      curr += 2 * (afirst[i].first * srr[afirst[i].second].size()) -
              srr[afirst[i].second].size();
      if (curr >= 1) {
        total++;
      } else {
        break;
      }
    }
    maxi = max(maxi, total);
    curr = 0;
    total = 0;
    for (int i = n - 1; i >= 0; i--) {
      if ((bfirst[i].first * srr[bfirst[i].second].size()) < 1) {
        bfirst[i].first = 0;
      }
      curr += 2 * (bfirst[i].first * srr[bfirst[i].second].size()) -
              srr[bfirst[i].second].size();
      if (curr >= 1) {
        total++;
      } else {
        break;
      }
    }
    maxi = max(maxi, total);
    curr = 0;
    total = 0;
    for (int i = n - 1; i >= 0; i--) {
      if ((cfirst[i].first * srr[cfirst[i].second].size()) < 1) {
        cfirst[i].first = 0;
      }
      curr += 2 * (cfirst[i].first * srr[cfirst[i].second].size()) -
              srr[cfirst[i].second].size();
      if (curr >= 1) {
        total++;
      } else {
        break;
      }
    }
    maxi = max(maxi, total);
    curr = 0;
    total = 0;
    for (int i = n - 1; i >= 0; i--) {
      if ((dfirst[i].first * srr[dfirst[i].second].size()) < 1) {
        dfirst[i].first = 0;
      }
      curr += 2 * (dfirst[i].first * srr[dfirst[i].second].size()) -
              srr[dfirst[i].second].size();
      if (curr >= 1) {
        total++;
      } else {
        break;
      }
    }
    maxi = max(maxi, total);
    curr = 0;
    total = 0;
    for (int i = n - 1; i >= 0; i--) {
      if ((efirst[i].first * srr[efirst[i].second].size()) < 1) {
        efirst[i].first = 0;
      }
      curr += 2 * (efirst[i].first * srr[efirst[i].second].size()) -
              srr[efirst[i].second].size();
      if (curr >= 1) {
        total++;
      } else {
        break;
      }
    }
    maxi = max(maxi, total);
    cout << maxi << endl;
  }
  return 0;
}
