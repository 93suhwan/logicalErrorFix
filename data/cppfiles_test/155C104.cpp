#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (int &x : p) cin >> x;
  string s;
  cin >> s;
  vector<int> liked, disliked;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1')
      liked.push_back(i);
    else
      disliked.push_back(i);
  }
  auto comp = [&](int i, int j) { return p[i] < p[j]; };
  sort(liked.begin(), liked.end(), comp);
  sort(disliked.begin(), disliked.end(), comp);
  vector<int> q(n);
  for (size_t i = 0; i < disliked.size(); i++) {
    q[disliked[i]] = i + 1;
  }
  for (size_t i = 0; i < liked.size(); i++) {
    q[liked[i]] = disliked.size() + i + 1;
  }
  for (int x : q) cout << x << ' ';
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}
