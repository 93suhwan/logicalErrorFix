#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 69;
const int64_t INF = 100000000000000018LL;
long long check(long long mid, string s, vector<pair<char, long long>> v) {
  map<char, long long> mpp;
  for (long long i = 0; i <= mid; i++) {
    mpp[s[i]]++;
  }
  for (long long i = 0; i < (long long)v.size(); i++) {
    char a = v[i].first;
    long long x = v[i].second;
    if (mpp[a] < x) return 0;
  }
  return 1;
}
void solve() {
  string s;
  cin >> s;
  vector<long long> cnt(26, 0), actual(26, 0);
  vector<char> v;
  long long n = (long long)s.size(), i, j;
  for (i = n - 1; i >= 0; i--) {
    actual[s[i] - 'a']++;
    if (cnt[s[i] - 'a'] == 0) {
      v.push_back(s[i]);
      cnt[s[i] - 'a']++;
    }
  }
  string ultimate = "";
  reverse((v).begin(), (v).end());
  vector<pair<char, long long>> yoyo;
  for (i = 0; i < (long long)v.size(); i++) {
    char x = v[i];
    if (actual[x - 'a'] % (i + 1)) {
      cout << -1 << "\n";
      return;
    } else {
      ultimate += x;
      yoyo.push_back({x, actual[x - 'a'] / (i + 1)});
    }
  }
  long long l = 0, r = n - 1, mid, ans = -1;
  while (l <= r) {
    mid = l + (r - l) / 2;
    if (check(mid, s, yoyo)) {
      r = mid - 1;
      ans = mid;
    } else {
      l = mid + 1;
    }
  }
  if (ans == -1) {
    cout << -1 << "\n";
    return;
  }
  string st, s1;
  for (i = 0; i <= ans; i++) st += s[i];
  s1 = st;
  set<long long> no;
  for (i = 0; i < (long long)yoyo.size(); i++) {
    char z = yoyo[i].first;
    string second;
    for (j = 0; j < (long long)st.size(); j++) {
      if (z == st[j] || no.count(j)) {
        no.insert(j);
        continue;
      } else
        second += st[j];
    }
    s1 += second;
  }
  if (s1 == s) {
    cout << st << " " << ultimate << "\n";
    return;
  }
  cout << -1 << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
