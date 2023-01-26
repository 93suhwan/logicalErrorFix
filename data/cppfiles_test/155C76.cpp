#include <bits/stdc++.h>
using namespace std;
bool mycomp(pair<long long, long long> a, pair<long long, long long> b) {
  return (a.second < b.second);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) cin >> a[i];
    string s;
    cin >> s;
    vector<pair<long long, long long>> p(n);
    for (long long i = 0; i < n; i++) {
      p[i].first = a[i];
      p[i].second = i;
    }
    sort(p.begin(), p.end());
    long long maxi = n;
    for (long long i = n - 1; i >= 0; i--) {
      if (s[p[i].second] == '1') {
        p[i].first = maxi;
        maxi--;
      } else
        continue;
    }
    for (long long i = n - 1; i >= 0; i--) {
      if (s[p[i].second] == '0') {
        p[i].first = maxi;
        maxi--;
      } else
        continue;
    }
    sort(p.begin(), p.end(), mycomp);
    for (auto it : p) {
      cout << it.first << " ";
    }
    cout << "\n";
  }
  return 0;
}
