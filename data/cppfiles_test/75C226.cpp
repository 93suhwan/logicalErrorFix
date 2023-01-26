#include <bits/stdc++.h>
using namespace std;
void subtraction(vector<vector<int>> &v) {
  for (int i = 0; i < v.size(); i++) {
    int t = 0;
    int ans = 0;
    for (int j = 0; j < v[i].size(); j++) {
      v[i][j] = v[i][j] - t;
      t = t + 1;
    }
  }
}
bool sortbyfirst(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.first < b.first);
}
void vectorsubtraction(vector<vector<int>> &v, vector<pair<int, int>> &v1) {
  int t = v[v1.at(0).second].size();
  for (int i = 0; i < v1.size() - 1; i++) {
    v1.at(i + 1).first = v1.at(i + 1).first - t;
    t += v[v1.at(i + 1).second].size();
  }
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    vector<vector<int>> v_2(n);
    for (int j = 0; j < n; j++) {
      int a;
      cin >> a;
      for (int k = 0; k < a; k++) {
        int b;
        cin >> b;
        v_2[j].push_back(b);
      }
    }
    subtraction(v_2);
    vector<pair<int, int>> v2;
    for (int m = 0; m < v_2.size(); m++) {
      int a;
      a = *max_element(v_2[m].begin(), v_2[m].end());
      v2.push_back(make_pair(a, m));
    }
    sort(v2.begin(), v2.end(), sortbyfirst);
    vectorsubtraction(v_2, v2);
    int ans = -10000000;
    for (auto x : v2) {
      ans = max(ans, x.first);
    }
    cout << ans + 1 << endl;
  }
}
