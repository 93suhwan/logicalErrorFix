#include <bits/stdc++.h>
using namespace std;
long long int MOD = 1000000007;
void solve() {
  long long int n, m, ans = 0;
  cin >> n;
  int arr[200001] = {
      0,
  };
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  string str;
  cin >> str;
  vector<pair<int, int> > zero;
  vector<pair<int, int> > one;
  for (int i = 0; i < n; i++) {
    int num = str[i] - '0';
    if (num == 0)
      zero.push_back({arr[i], i});
    else
      one.push_back({arr[i], i});
  }
  int num = 1;
  sort(zero.begin(), zero.end());
  sort(one.begin(), one.end());
  for (int i = 0; i < zero.size(); i++) {
    arr[zero[i].second] = num;
    num++;
  }
  for (int i = 0; i < one.size(); i++) {
    arr[one[i].second] = num;
    num++;
  }
  for (int i = 0; i < n; i++) {
    cout << arr[i] << ' ';
  }
  cout << '\n';
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}
