#include <bits/stdc++.h>
using namespace std;
int ratings[200005];
void prob() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> ratings[i];
    ratings[i]--;
  }
  string review;
  cin >> review;
  set<pair<int, int>> disliked, liked;
  for (int i = 0; i < n; i++) {
    if (review[i] == '1') {
      liked.emplace(ratings[i], i);
    } else {
      disliked.emplace(ratings[i], i);
    }
  }
  int idx = 1;
  for (auto p : disliked) {
    ratings[p.second] = idx++;
  }
  for (auto p : liked) {
    ratings[p.second] = idx++;
  }
  for (int i = 0; i < n; i++) {
    cout << ratings[i] << ' ';
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) prob();
  return 0;
}
