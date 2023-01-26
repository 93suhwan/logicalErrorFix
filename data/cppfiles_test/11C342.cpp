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
    vector<pair<int, int>> afirst(n);
    vector<pair<int, int>> bfirst(n);
    vector<pair<int, int>> cfirst(n);
    vector<pair<int, int>> dfirst(n);
    vector<pair<int, int>> efirst(n);
    for (int i = 0; i < n; i++) {
      int countabc[5] = {0};
      for (int j = 0; j < srr[i].size(); j++) {
        countabc[srr[i][j] - 'a']++;
      }
      afirst[i].first = 2 * countabc[0] - srr[i].size();
      bfirst[i].first = 2 * countabc[1] - srr[i].size();
      cfirst[i].first = 2 * countabc[2] - srr[i].size();
      dfirst[i].first = 2 * countabc[3] - srr[i].size();
      efirst[i].first = 2 * countabc[4] - srr[i].size();
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
      curr += afirst[i].first;
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
      curr += bfirst[i].first;
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
      curr += cfirst[i].first;
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
      curr += dfirst[i].first;
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
      curr += efirst[i].first;
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
