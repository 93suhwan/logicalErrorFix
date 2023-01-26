#include <bits/stdc++.h>
using namespace std;
void print(vector<long long int> &arr) {
  long long int n = arr.size();
  for (long long int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}
void init_code() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
void pre() {}
int main() {
  init_code();
  pre();
  long long int q;
  cin >> q;
  vector<vector<long long int>> queries;
  for (long long int i = 0; i < q; i++) {
    long long int type, x, y;
    cin >> type;
    if (type == 1) {
      cin >> x;
      vector<long long int> temp({type, x});
      queries.push_back(temp);
    } else {
      cin >> x >> y;
      vector<long long int> temp({type, x, y});
      queries.push_back(temp);
    }
  }
  vector<long long int> ans;
  unordered_map<long long int, long long int> mp;
  for (long long int i = q - 1; i >= 0; i--) {
    if (queries[i][0] == 1) {
      long long int x = queries[i][1];
      long long int y = x;
      if (mp.find(y) != mp.end()) {
        y = mp[y];
      }
      ans.push_back(y);
    } else {
      long long int x = queries[i][1];
      long long int y = queries[i][2];
      if (x != y) {
        mp[x] = mp.find(y) == mp.end() ? y : mp[y];
      }
    }
  }
  reverse(ans.begin(), ans.end());
  print(ans);
  return 0;
}
