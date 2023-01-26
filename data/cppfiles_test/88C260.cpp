#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> eye_sights(n * m);
    for (int i = 0; i < n * m; i++) {
      cin >> eye_sights[i].first;
      eye_sights[i].second = i;
    }
    sort(eye_sights.begin(), eye_sights.end());
    int inconvenience = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int k = 0; k < j; k++) {
          if (eye_sights[i * m + k].first < eye_sights[i * m + j].first &&
              eye_sights[i * m + k].second < eye_sights[i * m + j].second)
            inconvenience++;
        }
      }
    }
    cout << inconvenience << "\n";
  }
}
