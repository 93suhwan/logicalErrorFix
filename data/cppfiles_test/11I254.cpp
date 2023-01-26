#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int N;
    cin >> N;
    vector<pair<string, vector<int>>> inputs(N);
    for (int n = 0; n < N; ++n) {
      inputs[n].second.resize(5);
    }
    for (int n = 0; n < N; ++n) {
      cin >> inputs[n].first;
      for (int i = 0; i < inputs[n].first.size(); ++i) {
        ++inputs[n].second[inputs[n].first[i] - 'a'];
      }
    }
    int ans = 0;
    for (int i = 0; i < 5; ++i) {
      sort(inputs.begin(), inputs.end(),
           [i](const pair<string, vector<int>>& a,
               const pair<string, vector<int>>& b) {
             if (a.first.size() - a.second[i] == b.first.size() - b.second[i]) {
               return a.second[i] > b.second[i];
             } else {
               return a.first.size() - a.second[i] <
                      b.first.size() - b.second[i];
             }
           });
      int sum_len = 0;
      int sum_pivot = 0;
      int mx_count = 0;
      for (int count = 0; count < N; ++count) {
        sum_pivot += inputs[count].second[i];
        sum_len += inputs[count].first.size();
        if (sum_pivot > sum_len - sum_pivot) {
          mx_count = count + 1;
        }
      }
      ans = max(mx_count, ans);
    }
    cout << ans << '\n';
  }
  return 0;
}
