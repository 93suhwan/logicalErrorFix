#include <bits/stdc++.h>
using namespace std;
bool ok(vector<vector<long long int>> &joy, long long int shop,
        long long int dusto, long long int key) {
  vector<bool> satisfied(dusto);
  bool flag = 0;
  long long int cnt = 0, sum = 0;
  for (int i = 0; i < shop; i++) {
    cnt = 0;
    for (int j = 0; j < dusto; j++) {
      if (joy[i][j] >= key) {
        satisfied[j] = 1;
        cnt++;
      }
    }
    if (cnt >= 2) flag = 1;
  }
  for (int i = 0; i < dusto; i++) sum += satisfied[i];
  return (sum == dusto && flag == 1);
}
long long int bi_s(vector<vector<long long int>> &joy, long long int st,
                   long long int en, long long int shop, long long int dusto) {
  long long int mid;
  long long int ans = 0;
  while (st <= en) {
    mid = st + (en - st) / 2;
    if (ok(joy, shop, dusto, mid)) {
      ans = mid;
      st = mid + 1;
    } else
      en = mid - 1;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long int shop, dusto;
    cin >> shop >> dusto;
    vector<vector<long long int>> joy(shop, vector<long long int>(dusto));
    for (int i = 0; i < shop; i++)
      for (int j = 0; j < dusto; j++) {
        cin >> joy[i][j];
      }
    cout << bi_s(joy, 0, 1000000010, shop, dusto) << "\n";
  }
}
