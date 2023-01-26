#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
using ll = long long;
using ld = long double;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<long>;
using vll = vector<long long>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using mii = map<int, int>;
using mll = map<long long, long long>;
using umii = unordered_map<int, int>;
using umll = unordered_map<long long, long long>;
const long long mod = 1e9 + 7, inf = 1e18;
const int Mod_N = 10e5 + 5;
void solveTestCases() {
  ll n, k;
  cin >> n >> k;
  vll array(n);
  ll arrSum = 0;
  for (int i = 0; i < n; i++) {
    cin >> array[i];
    arrSum += array[i];
  }
  sort(array.begin(), array.end());
  stack<ll> x;
  for (auto i = 1; i < n; i++) {
    x.push(array[i] - array[0]);
  }
  ll count = 0;
  ll Min = INT_MAX;
  while (!x.empty() && arrSum > k) {
    Min = min(Min, count + (arrSum - k + count) / (count + 1));
    arrSum -= x.top();
    x.pop();
    count++;
  }
  if (arrSum > k) {
    count += (arrSum - k + count) / (count + 1);
  }
  cout << min(Min, count) << "\n";
}
int main() {
  ll t = 1;
  cin >> t;
  while (t--) {
    solveTestCases();
  }
}
