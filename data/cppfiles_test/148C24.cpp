#include <bits/stdc++.h>
using namespace std;
const long long INF = 1001001001;
const long long LINF = 1001001001001001001;
const long long MOD = 998244353;
void solve() {
  long long w, h;
  cin >> w >> h;
  long long k;
  cin >> k;
  vector<long long> hor1(k);
  for (long long i = 0; i < (long long)(k); i++) cin >> hor1[i];
  cin >> k;
  vector<long long> hor2(k);
  for (long long i = 0; i < (long long)(k); i++) cin >> hor2[i];
  cin >> k;
  vector<long long> ver1(k);
  for (long long i = 0; i < (long long)(k); i++) cin >> ver1[i];
  cin >> k;
  vector<long long> ver2(k);
  for (long long i = 0; i < (long long)(k); i++) cin >> ver2[i];
  sort((hor1).begin(), (hor1).end());
  sort((hor2).begin(), (hor2).end());
  sort((ver1).begin(), (ver1).end());
  sort((ver2).begin(), (ver2).end());
  long long W = max(abs(hor1[0] - hor1.back()), abs(hor2[0] - hor2.back()));
  long long H = max(abs(ver1[0] - ver1.back()), abs(ver2[0] - ver2.back()));
  cout << (max(W * h, w * H)) << endl;
  return;
}
int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int t;
  cin >> t;
  for (long long _ = 0; _ < (long long)(t); _++) solve();
  return 0;
}
