#include <bits/stdc++.h>
using namespace std;
bool ketan(pair<string, long long> &p1, pair<string, long long> &p2) {
  for (long long i = 0; i < p1.first.length(); i++) {
    if (i % 2 == 0 && p1.first[i] != p2.first[i]) {
      return p1.first[i] > p2.first[i];
    }
    if (i % 2 == 1 && p1.first[i] != p2.first[i]) {
      return p1.first[i] < p2.first[i];
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m;
  cin >> n >> m;
  vector<pair<string, long long>> v;
  for (long long i = 0; i < n; i++) {
    string s;
    cin >> s;
    v.push_back(make_pair(s, i));
  }
  sort(v.begin(), v.end(), ketan);
  for (long long i = n - 1; i >= 0; i--) {
    cout << v[i].second + 1 << " ";
  }
  return 0;
}
