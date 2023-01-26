#include <bits/stdc++.h>
using namespace std;
template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
const int INF = 1005000000;
const long long MOD = 998244353LL;
int ni() {
  int x;
  cin >> x;
  return x;
}
long long nl() {
  long long x;
  cin >> x;
  return x;
}
double nd() {
  double x;
  cin >> x;
  return x;
}
string next() {
  string x;
  cin >> x;
  return x;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int Q = ni();
  for (int q = 0; q < (Q); q++) {
    int N = ni();
    multimap<int, int> nums;
    for (int i = 0; i < (N); i++) {
      int n = ni();
      nums.insert({n, i});
    }
    vector<pair<int, int>> talks;
    while (((int)(nums).size()) > 1) {
      int L = nums.begin()->first;
      int Li = nums.begin()->second;
      nums.erase(nums.begin());
      if (L > 0) {
        int R = nums.rbegin()->first;
        int Ri = nums.rbegin()->second;
        talks.push_back({Li, Ri});
        nums.erase(nums.find(R));
        nums.insert({L - 1, Li});
        nums.insert({R - 1, Ri});
      }
    }
    cout << ((int)(talks).size()) << '\n';
    for (pair<int, int> p : talks) {
      cout << p.first + 1 << ' ' << p.second + 1 << '\n';
    }
  }
}
