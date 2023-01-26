#include <bits/stdc++.h>
using namespace std;
string bintoString(long long x) { return bitset<64>(x).to_string(); }
inline int power(int a, int b) {
  int x = 1;
  while (b) {
    if (b & 1) x *= a;
    a *= a;
    b >>= 1;
  }
  return x;
}
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first == b.first) {
    return a.second > b.second;
  } else {
    return a.first < b.first;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<pair<long long, long long>> vp;
    for (int i = 0; i < n; i++) {
      long long x, y;
      cin >> x >> y;
      vp.push_back({x, y});
    }
    sort(vp.begin(), vp.end(), cmp);
    int h[1001] = {0};
    vector<vector<long long>> ans;
    for (int i = vp.size() - 1; i >= 0; i--) {
      for (int j = vp[i].first; j <= vp[i].second; j++) {
        if (h[j] == 0) {
          vector<long long> t = {vp[i].first, vp[i].second, j};
          ans.push_back(t);
        }
      }
      h[vp[i].first] = 1;
      h[vp[i].second] = 1;
    }
    for (auto i : ans) {
      cout << i[0] << " " << i[1] << " " << i[2] << "\n";
    }
  }
  return 0;
}
