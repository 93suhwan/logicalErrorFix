#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> arr) {
  for (int i = 1; i < arr.size(); i++) {
    if (i != arr[i]) return false;
  }
  return true;
}
void iterate(vector<int> &arr, int cnt, int n) {
  int st;
  if (cnt & 1)
    st = 1;
  else
    st = 2;
  int ed;
  if (cnt & 1)
    ed = n - 2;
  else
    ed = n - 1;
  for (int i = st; i <= ed; i += 2) {
    if (arr[i] > arr[i + 1]) swap(arr[i], arr[i + 1]);
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i < n + 1; i++) cin >> arr[i];
    int cnt = 0;
    while (!check(arr)) {
      cnt++;
      iterate(arr, cnt, n);
    }
    cout << cnt << endl;
  }
  return 0;
}
