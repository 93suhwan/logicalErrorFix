#include <bits/stdc++.h>
using namespace std;
long double PI = acosl(-1);
bool compare_int(int a, int b) { return (a > b); }
bool compare_string(string a, string b) { return a.size() < b.size(); }
bool compare_pair(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.second == b.second)
    return a.first < b.first;
  else
    return (a.second > b.second);
}
bool cmp(pair<string, int> x, pair<string, int> y) {
  return (x.second < y.second);
}
void NA() {
  printf("NO\n");
  exit(0);
}
void YA() {
  printf("YES\n");
  exit(0);
}
bool valid(string s1, string s2, string s3) {
  string t;
  map<char, int> vis;
  for (int i = 0; i < s2.size(); i++) {
    for (int j = 0; j < s1.size(); j++) {
      if (vis[s1[j]] == 0) t += s1[j];
    }
    vis[s2[i]]++;
  }
  return (t == s3);
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s, ans1, ans2;
    cin >> s;
    int len = s.size();
    map<char, int> cnt;
    map<char, bool> vis;
    for (int i = len - 1; i >= 0; i--) {
      if (vis[s[i]] == false) {
        vis[s[i]] = true;
        ans2 += s[i];
      }
    }
    bool ok = false;
    for (int i = 0; i < len; i++) {
      cnt[s[i]]++;
      long long int tot = 0, sum = 0;
      for (int j = 0; j < ans2.size(); j++) {
        if (cnt[ans2[j]] > 0) {
          sum += cnt[ans2[j]];
          tot += sum;
        } else {
          tot = 0;
          break;
        }
      }
      if (tot == len) {
        ans1 = s.substr(0, i + 1);
        reverse(ans2.begin(), ans2.end());
        ok = true;
        break;
      }
    }
    if (ok and valid(ans1, ans2, s))
      cout << ans1 << ' ' << ans2 << "\n";
    else
      cout << -1 << "\n";
  }
}
