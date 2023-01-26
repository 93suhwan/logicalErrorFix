#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void omae_wa_mou_shindeiru(int tc) {
  long long n, m;
  cin >> n >> m;
  vector<long long> p(n), rot(n);
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    p[temp - 1] = i;
  }
  for (int i = 0; i < n; i++) {
    long long req = (n + p[i] - i) % n;
    rot[req]++;
  }
  vector<long long> ans;
  for (int i = 0; i < n; i++) {
    long long dis = n - rot[i];
    if ((dis + 1) / 2 <= m) ans.push_back(i);
  }
  cout << ans.size() << " ";
  for (auto it : ans) cout << it << " ";
  cout << "\n";
  ;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  for (int i = 1; i < tc + 1; i++) {
    omae_wa_mou_shindeiru(i);
  }
}
