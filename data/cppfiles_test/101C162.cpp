#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
void solve(long long t) {
  long long n;
  cin >> n;
  vector<long long> ls(n);
  for (auto& x : ls) cin >> x;
  string s;
  cin >> s;
  vector<long long> bl{};
  vector<long long> rd{};
  for (long long i = 0; i < n; i++) {
    if (s[i] == 'R')
      rd.push_back(ls[i]);
    else
      bl.push_back(ls[i]);
  }
  sort(bl.begin(), bl.end());
  sort(rd.begin(), rd.end());
  bl = {bl.rbegin(), bl.rend()};
  long long idRed = 0;
  vector<long long> curRed{};
  for (long long i = 1; i <= n; i++) {
    while (!bl.empty() && bl.back() < i) bl.pop_back();
    if (!bl.empty()) {
      bl.pop_back();
      continue;
    }
    while (idRed < (long long)rd.size() && rd[idRed] <= i) {
      curRed.push_back(rd[idRed]);
      idRed++;
    }
    if (!curRed.empty()) {
      curRed.pop_back();
      continue;
    }
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
}
signed main() {
  bool multi = true;
  if (multi) {
    long long t;
    cin >> t;
    for (long long i = 0; i < t; i++) solve(i + 1);
  } else {
    solve(1);
  }
}
