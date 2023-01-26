#include <bits/stdc++.h>
using namespace std;
void generate(string s, int left, int right, vector<string>& arr) {
  if (left == 0 && right == 0) {
    arr.push_back(s);
  }
  if (left < right) generate(s + ')', left, right - 1, arr);
  if (left > 0) generate(s + '(', left - 1, right, arr);
}
void solve() {
  int n;
  cin >> n;
  int left = n, right = n;
  vector<string> a;
  generate("", left, right, a);
  for (auto& s : a) cout << s << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) solve();
}
