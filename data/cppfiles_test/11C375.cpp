#include <bits/stdc++.h>
using namespace std;
istream& operator>>(istream& in, vector<int>& a) {
  for (int i = 0; i < a.size(); ++i) in >> a[i];
  return in;
}
ostream& operator<<(ostream& out, vector<int>& a) {
  for (int i : a) out << i << ' ';
  return out;
}
istream& operator>>(istream& in, vector<long long>& a) {
  for (int i = 0; i < a.size(); ++i) in >> a[i];
  return in;
}
ostream& operator<<(ostream& out, vector<long long>& a) {
  for (long long i : a) out << i << ' ';
  return out;
}
istream& operator>>(istream& in, pair<int, int>& p) {
  in >> p.first >> p.second;
  return in;
}
ostream& operator<<(ostream& out, pair<int, int>& p) {
  out << p.first << ' ' << p.second;
  return out;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.setf(ios::fixed);
  cout.precision(10);
  int ttt;
  cin >> ttt;
  while (ttt--) {
    int n;
    cin >> n;
    vector<vector<int>> cnt;
    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      vector<int> t(26);
      for (auto i : s) t[i - 'a']++;
      t.push_back(s.size());
      cnt.push_back(t);
    }
    int ans = 0;
    for (int i = 0; i < 26; ++i) {
      int p = 0;
      int k = 0;
      for (int j = 0; j < n; ++j) {
        if (2 * cnt[j][i] > cnt[j].back()) {
          k++;
          p += -cnt[j].back() + 2 * cnt[j][i];
        }
      }
      vector<int> ad;
      for (int j = 0; j < n; ++j) {
        if (2 * cnt[j][i] <= cnt[j].back()) {
          ad.push_back(cnt[j].back() - 2 * cnt[j][i]);
        }
      }
      sort(ad.begin(), ad.end());
      for (int i = 0; i < ad.size(); ++i) {
        if (ad[i] < p) {
          p -= ad[i];
          k++;
        }
      }
      ans = max(ans, k);
    }
    cout << ans << '\n';
  }
}
