#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T& a, const T& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
};
template <typename T>
void view(T e) {
  cout << e << endl;
}
void view(vector<string>& v) {
  cout << endl;
  for (auto& s : v) {
    view(s);
  }
  cout << endl;
}
template <typename T>
void view(vector<T>& v) {
  for (auto& e : v) {
    cout << e << " ";
  }
  cout << endl;
}
template <typename T>
void view(vector<vector<T>>& vv) {
  cout << endl;
  for (auto& v : vv) {
    view(v);
  }
}
template <typename T>
using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
void start() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
}
void solve() {
  long long n;
  cin >> n;
  set<long long> st;
  for (long long i = 1; i * i <= n; i++) {
    if (i * i * i <= n) {
      st.insert(i * i * i);
    }
    st.insert(i * i);
  }
  cout << (long long)st.size() << "\n";
}
int32_t main() {
  start();
  long long t;
  cin >> t;
  while (t--) solve();
}
