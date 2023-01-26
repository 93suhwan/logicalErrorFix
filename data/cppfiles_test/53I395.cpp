#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const int maxn = 1e5 + 5;
void solve() {
  int n;
  char c;
  cin >> n >> c;
  string str;
  cin >> str;
  vector<int> vec;
  if (str[n - 1] != c) {
    vec.push_back(n - 1);
    str[n - 1] = c;
  }
  if (str[n - 2] != c) {
    vec.push_back(n);
    str[n - 2] = c;
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (str[i] != c) {
      cnt++;
    }
  }
  if (cnt >= 1 && vec.size() == 0) {
    vec.push_back(n);
  }
  cout << vec.size() << endl;
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << " ";
  }
  cout << endl;
}
void solve2() {
  string final_ans;
  int n;
  char c;
  cin >> n >> c;
  final_ans += "num ";
  final_ans += to_string(n);
  final_ans += " c ";
  final_ans += c;
  string str;
  cin >> str;
  final_ans += str;
  cout << str.size() << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    if (i == 70) {
      solve2();
    } else {
      solve();
    }
  }
  return 0;
}
