#include <bits/stdc++.h>
using namespace std;
void hinataVSsakura(void);
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long T = 1;
  cin >> T;
  while (T--) {
    hinataVSsakura();
  }
  return 0;
}
void hinataVSsakura(void) {
  long long n;
  cin >> n;
  map<long long, long long> mpp;
  vector<pair<long long, long long>> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i].first;
    arr[i].second = i;
    mpp[i] = arr[i].first;
  }
  vector<pair<long long, long long>> pos, neg;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0')
      neg.push_back({mpp[i], i});
    else
      pos.push_back({mpp[i], i});
  }
  sort(neg.begin(), neg.end());
  sort(pos.begin(), pos.end());
  vector<long long> ans(n);
  long long j = 1;
  for (int i = 0; i < neg.size(); i++) {
    ans[neg[i].second] = j++;
  }
  for (int i = 0; i < pos.size(); i++) {
    ans[pos[i].second] = j++;
  }
  for (auto x : ans) cout << x << " ";
  cout << endl;
}
