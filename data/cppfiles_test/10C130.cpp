#include <bits/stdc++.h>
using namespace std;
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
void solve() {
  int n, numColors;
  cin >> n >> numColors;
  int k = numColors;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> color(n, 0);
  unordered_map<int, vector<int>> colormap;
  for (int i = 0; i < n; i++) {
    if (colormap.find(a[i]) == colormap.end()) {
      vector<int> v;
      v.push_back(i);
      colormap[a[i]] = v;
    } else {
      colormap[a[i]].push_back(i);
    }
  }
  vector<int> multicolor;
  for (auto itr = colormap.begin(); itr != colormap.end(); itr++) {
    if (itr->second.size() >= k) {
      for (int i = 0; i < k; i++) {
        color[itr->second[i]] = i + 1;
      }
    } else {
      for (int i = 0; i < itr->second.size(); i++) {
        multicolor.push_back(itr->second[i]);
      }
    }
  }
  int mc = multicolor.size();
  int counter = 0;
  int stoper = mc - mc % k;
  for (int i : multicolor) {
    if (counter == stoper) break;
    color[i] = (counter % k) + 1;
    counter++;
  }
  for (int ans : color) cout << ans << " ";
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
}
