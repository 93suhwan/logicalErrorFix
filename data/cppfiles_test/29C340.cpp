#include <bits/stdc++.h>
using namespace std;
void Anwar_Rizk() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
void solve() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (auto& i : nums) cin >> i;
  long long ones = count(nums.begin(), nums.end(), 1);
  long long zeros = count(nums.begin(), nums.end(), 0);
  cout << (long long)pow(2, zeros) * ones << "\n";
}
int main() {
  Anwar_Rizk();
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
