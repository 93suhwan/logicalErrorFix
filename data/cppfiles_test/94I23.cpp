#include <bits/stdc++.h>
using namespace std;
int a, b;
int len;
long long ans;
int nums[20];
int nums1[20];
void work() {
  long long cs = 1;
  for (int i = 0; i < len; ++i) {
    int j;
    int cnt = 0;
    if (nums[i] > 9)
      j = 9;
    else
      j = nums[i];
    while (j >= 0 && nums[i] - j >= 0 && nums[i] - j <= 9) {
      ++cnt;
      --j;
    }
    cs *= cnt;
  }
  ans += cs;
}
bool changei(int i) {
  int nexti = i - 2;
  if (nexti < 0) return 0;
  if (nums[nexti] == 0) {
    nums[nexti] = 9;
    return changei(nexti);
  }
  nums[nexti]--;
  return 1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    ans = 0;
    string s = to_string(n);
    len = s.size();
    for (int i = 0; i < len; ++i) nums[i] = s[i] - '0';
    work();
    for (int i = len - 1; i >= 2; --i) {
      for (int j = 0; j < len; ++j) nums1[j] = nums[j];
      nums[i] += 10;
      if (changei(i)) work();
      for (int j = 0; j < len; ++j) nums[j] = nums1[j];
    }
    cout << ans - 2 << endl;
  }
}
