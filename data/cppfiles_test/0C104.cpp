#include <bits/stdc++.h>
using namespace std;
bool cmp(string& a, string& b) {
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] != b[i]) return pow(-1, i) * a[i] < pow(-1, i) * b[i];
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<string> arr(n);
  for (int i = 0; i < n; ++i) cin >> arr[i];
  map<string, int> mm;
  for (int i = 0; i < n; ++i) mm[arr[i]] = i;
  sort(arr.begin(), arr.end(), cmp);
  for (string str : arr) cout << mm[str] + 1 << ' ';
  return 0;
}
