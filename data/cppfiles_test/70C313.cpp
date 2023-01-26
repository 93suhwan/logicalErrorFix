#include <bits/stdc++.h>
using namespace std;
using big = long long;
const int N = 520020;
char a[N];
int n;
int cnt[N], rk[N];
bool ck(string s1, const string& s2, char c) {
  s1.erase(remove(s1.begin(), s1.end(), c), s1.end());
  return s1 == s2;
}
string solve() {
  set<char> vis;
  string order = "";
  for (int i = 'a'; i <= 'z'; ++i) {
    rk[i] = cnt[i] = 0;
  }
  for (int i = n; i >= 1; --i) {
    if (!vis.count(a[i])) {
      order.push_back(a[i]);
      vis.insert(a[i]);
    }
  }
  reverse(order.begin(), order.end());
  for (int i = 1; i <= n; ++i) {
    ++cnt[a[i]];
  }
  for (int i = 0; i < order.size(); ++i) {
    rk[order[i]] = i + 1;
  }
  int len = order.size();
  for (int i = 'a'; i <= 'z'; ++i) {
    if (!rk[i]) {
      continue;
    }
    if (cnt[i] % rk[i]) {
      return "-1";
    }
    cnt[i] /= rk[i];
  }
  vector<string> ss;
  int k = 1;
  for (int l = 1; l <= len; ++l) {
    int sm = 0;
    for (int i = l; i <= len; ++i) {
      sm += cnt[order[i - 1]];
    }
    string s;
    while (sm && k <= n) {
      s.push_back(a[k]);
      --sm;
      ++k;
    }
    if (sm > 0) {
      return "-1";
    }
    ss.push_back(s);
  }
  if (k <= n) {
    return "-1";
  }
  for (int i = 1; i < ss.size(); ++i) {
    if (!ck(ss[i - 1], ss[i], order[i - 1])) {
      return "-1";
    }
  }
  return ss.front() + " " + order;
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  int cas;
  cin >> cas;
  while (cas--) {
    cin >> (a + 1);
    n = strlen(a + 1);
    cout << solve() << "\n";
  }
}
