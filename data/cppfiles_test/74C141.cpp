#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.14159265359;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long randint(long long a, long long b) {
  return uniform_int_distribution<long long>(a, b)(rng);
}
template <typename... Args>
void logger(string vars, Args&&... values) {
  cout << vars << " = ";
  string delim = "";
  (..., (cout << delim << values, delim = ", "));
  cout << endl;
}
void print(vector<int>& v) {
  cout << "[";
  for (int i = 0; i < v.size(); i++) {
    cout << v[i];
    if (i + 1 != v.size()) cout << ", ";
  }
  cout << "]" << endl;
}
void print(pair<int, int>& p) {
  cout << "{" << p.first << ", " << p.second << "}" << endl;
}
vector<int> junta(pair<int, int> a, pair<int, int> b) {
  int mini = 0;
  int maxi = 1;
  if (a.first > b.first) {
    mini = a.first - b.first;
    maxi += a.second;
  } else {
    mini = a.second - b.second;
    maxi += a.first;
  }
  vector<int> v;
  int cont = 0;
  for (int i = mini; i <= a.first + a.second && (cont++) < maxi; i += 2) {
    v.push_back(i);
  }
  return v;
}
signed main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    int n = (a + b);
    pair<int, int> t1 = {n / 2, (n + 1) / 2};
    pair<int, int> t2 = {(n + 1) / 2, n / 2};
    auto v1 = junta({a, b}, t1);
    auto v2 = junta({a, b}, t2);
    for (auto k : v2) {
      v1.push_back(k);
    }
    sort(v1.begin(), v1.end());
    auto un = unique(v1.begin(), v1.end());
    int cont = 0;
    for (auto i = v1.begin(); i != un; i++) {
      cont++;
    }
    cout << cont << '\n';
    for (auto i = v1.begin(); i != un; i++) {
      cout << *i << ' ';
    }
    cout << '\n';
  }
}
