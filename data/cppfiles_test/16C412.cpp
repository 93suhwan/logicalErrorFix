#include <bits/stdc++.h>
using namespace std;
void getArr(long long n, vector<string> &arr) {
  string x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    arr.push_back(x);
  }
}
bool check(vector<long long> &arr, int idx) {
  int a, b;
  a = b = 0;
  for (int i = 0; i < 5; i++) {
    if (i == idx)
      a += arr[i];
    else
      b += arr[i];
  }
  if (a > b) return true;
  return false;
}
void solve(long long k, string &s) {
  string temp = s;
  sort(temp.begin(), temp.end());
  int ans = 0;
  for (int i = 0; i < s.length(); i++) {
    if (temp[i] != s[i]) ans++;
  }
  cout << ans << endl;
}
int main() {
  long long n, t;
  cin >> t;
  string s;
  while (t--) {
    cin >> n;
    cin >> s;
    solve(n, s);
  }
  return 0;
}
