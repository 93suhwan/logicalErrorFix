#include <bits/stdc++.h>
using namespace std;
void go() {
  long long n;
  cin >> n;
  pair<long long, long long> a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  string s;
  cin >> s;
  if (s.find('0') == string::npos) {
    for (long long i = 0; i < n; i++) cout << a[i].first << " ";
    cout << "\n";
  } else {
    long long cnt = 0;
    vector<pair<long long, long long>> liked, disliked;
    for (long long i = 0; i < n; i++) {
      if (s[i] == '0') {
        disliked.push_back(a[i]);
        cnt++;
      } else {
        liked.push_back(a[i]);
      }
    }
    sort(a, a + n);
    sort(disliked.begin(), disliked.end());
    sort(liked.begin(), liked.end());
    vector<long long> ans(n);
    for (long long i = 0; i < cnt; i++) {
      ans[disliked[i].second] = a[i].first;
    }
    for (long long i = 0; i < liked.size(); i++) {
      ans[liked[i].second] = a[i + cnt].first;
    }
    for (long long i = 0; i < n; i++) cout << ans[i] << " ";
    cout << "\n";
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  t = 1;
  cin >> t;
  while (t--) {
    go();
  }
  return 0;
}
