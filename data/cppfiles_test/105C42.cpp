#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int, int> > meals(n);
    vector<int> Ms(n);
    map<int, vector<pair<int, int> > > categories;
    for (int i = 0; i < n; i++) {
      cin >> meals[i].first >> meals[i].second >> Ms[i];
      int totalSum = meals[i].first + meals[i].second - Ms[i];
      pair<int, int> curr(meals[i].first - min(0, meals[i].second - Ms[i]), i);
      categories[totalSum].push_back(curr);
    }
    int ans = 0;
    vector<pair<int, int> > out(n);
    for (pair<int, vector<pair<int, int> > > category : categories) {
      sort(category.second.begin(), category.second.end());
      int curr = (int)-1e9;
      for (pair<int, int> x : category.second) {
        int idx = x.second;
        int reach = max(meals[idx].first - Ms[idx], 0);
        if (reach > curr) {
          out[idx] = pair<int, int>(Ms[idx] - min(meals[idx].second, Ms[idx]),
                                    min(meals[idx].second, Ms[idx]));
          curr = meals[idx].first - Ms[idx] + min(meals[idx].second, Ms[idx]);
          ans++;
        } else
          out[idx] = pair<int, int>(meals[idx].first - curr,
                                    Ms[idx] - meals[idx].first + curr);
      }
    }
    cout << ans << endl;
    for (pair<int, int> x : out) cout << x.first << " " << x.second << endl;
  }
}
