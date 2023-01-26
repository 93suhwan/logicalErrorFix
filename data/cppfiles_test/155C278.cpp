#include <bits/stdc++.h>
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
using namespace std;
bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
  return a.first < b.first;
}
void solve() {
  int t;
  cin >> t;
  while (t--) {
    vector<pair<long long, long long>> p1;
    vector<pair<long long, long long>> p2;
    vector<long long> v;
    long long n, zeros = 0, ones = 0;
    cin >> n;
    for (long long i = 0; i < n; i++) {
      long long x;
      cin >> x;
      v.push_back(x);
    }
    vector<long long> ans;
    string second;
    cin >> second;
    for (long long i = 0; i < n; i++) {
      if (second[i] == '0') {
        p1.push_back({v[i], i});
        zeros++;
      } else {
        ones++;
        p2.push_back({v[i], i});
      }
    }
    sort(p1.begin(), p1.end(), cmp);
    sort(p2.begin(), p2.end(), cmp);
    long long cont = 1;
    for (int i = 0; i < p1.size(); i++) {
      v[p1[i].second] = cont++;
    }
    for (int i = 0; i < p2.size(); i++) {
      v[p2[i].second] = cont++;
    }
    for (long long i = 0; i < n; i++) {
      cout << v[i] << " ";
    }
    cout << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
