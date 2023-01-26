#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const long long mod = 1000000007;
const long long MAX = (long long)1 << 60;
long long dx[] = {1, 0, -1, 0};
long long dy[] = {0, 1, 0, -1};
void solve(long long nr) {
  string t;
  cin >> t;
  map<char, long long> mp, count;
  for (long long i = 0; i < t.length(); i++) {
    mp[t[i]] = i;
    count[t[i]]++;
  }
  vector<pair<long long, char>> a;
  for (auto it : mp) {
    a.push_back({it.second, it.first});
  }
  sort(a.begin(), a.end());
  long long temp = 0;
  for (long long i = 0; i < a.size(); i++) {
    if (count[a[i].second] % (i + 1) != 0) {
      cout << -1 << "\n";
      return;
    } else {
      temp += count[a[i].second] / (i + 1);
    }
  }
  string s = t.substr(0, temp);
  string r = "";
  for (long long i = 0; i < a.size(); i++) {
    r += s;
    if (r.size() > t.size()) {
      cout << -1 << "\n";
      return;
    } else {
      string k = "";
      for (auto it : s) {
        if (it != a[i].second) {
          k += it;
        }
      }
      s = k;
    }
  }
  if (r != t) {
    cout << -1 << "\n";
  } else {
    string order;
    for (auto it : a) {
      order += it.second;
    }
    cout << t.substr(0, temp) << " " << order << "\n";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long T = 1;
  cin >> T;
  for (long long nr = 1; nr <= T; nr++) {
    solve(nr);
  }
  return 0;
}
