#include <bits/stdc++.h>
using namespace std;
void solve();
int main(int argc, const char** argv) {
  int t = 1;
  cin >> t;
  while (bool(t--)) {
    solve();
    cout << '\n';
  }
}
void solve() {
  int size = 0;
  cin >> size;
  vector<int> v(size);
  unordered_map<int, int> mp;
  for (int i = 0; i < size; i++) {
    cin >> v[i];
    mp[v[i]] = i;
  }
  string s;
  cin >> s;
  vector<pair<int, int>> pos;
  for (int i = 0; i < size; i++) {
    if (s[i] == '1') {
      pos.push_back({v[i], i});
    }
  }
  sort(pos.begin(), pos.end(),
       [](const pair<int, int>& p1, const pair<int, int>& p2) {
         return p1.first < p2.first;
       });
  int ptr = pos.size() - 1;
  for (int rating = size; rating >= size - pos.size() + 1; rating--) {
    int i = mp[rating];
    if (s[i] == '1') {
      ptr--;
      continue;
    }
    int next = pos[ptr].second;
    mp[pos[ptr].first] = i;
    mp[rating] = next;
    swap(v[i], v[next]);
    ptr--;
  }
  for (auto i : v) {
    cout << i << ' ';
  }
}
