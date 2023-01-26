#include <bits/stdc++.h>
using namespace std;
bool even(long long int x) { return (x % 2 == 0); }
bool odd(long long int x) { return (x % 2 != 0); }
bool compare(pair<int, int> p1, pair<int, int> p2) {
  if (p1.first == p2.first)
    return p1.second <= p2.second;
  else
    return p1.first > p2.first;
}
vector<long long int> presum(vector<long long int> v) {
  vector<long long int> res(v.size());
  res[0] = v[0];
  for (int i = 1; i < v.size(); i++) {
    res[i] = res[i - 1] + v[i];
  }
  return res;
}
void precision(int a) { cout << setprecision(a) << fixed; }
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    int me = INT_MAX, maxe = INT_MIN;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      if (v[i] < me) {
        me = v[i];
      }
    }
    sort(v.begin(), v.end());
    int meb = INT_MAX;
    while (meb != me) {
      meb = me;
      for (int i = 0; i < n; i++) {
        v[i] = v[i] & me;
        if (v[i] < me) {
          me = v[i];
        }
      }
    }
    for (int i = 0; i < n; i++) maxe = max(v[i], maxe);
    cout << maxe << endl;
  }
}
