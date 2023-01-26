#include <bits/stdc++.h>
using namespace std;
int len;
long long ans;
int nums[20];
int nums1[20];
bool tenmore[20];
void work() {
  bool fl = 1;
  for (int i = 0; i < len; ++i) {
    if (tenmore[i]) {
      if (i - 2 < 0) {
        fl = 0;
        break;
      }
      nums[i - 2]--;
      nums[i] += 10;
    }
  }
  for (int i = 0; i < len; ++i)
    if (nums[i] < 0) {
      fl = 0;
      break;
    }
  if (!fl) return;
  long long cs = 1;
  for (int i = 0; i < len; ++i) {
    int j;
    int cnt = 0;
    if (nums[i] > 9)
      j = 9;
    else
      j = nums[i];
    while (j >= 0 && j <= 9 && nums[i] - j >= 0 && nums[i] - j <= 9) {
      ++cnt;
      --j;
    }
    cs *= cnt;
  }
  ans += cs;
}
void calc(int i) {
  if (i == len) {
    for (int j = 0; j < len; ++j) nums1[j] = nums[j];
    work();
    for (int j = 0; j < len; ++j) nums[j] = nums1[j];
    return;
  }
  tenmore[i] = 0;
  calc(i + 1);
  tenmore[i] = 1;
  calc(i + 1);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    ans = 0;
    string s = to_string(n);
    len = s.size();
    for (int i = 0; i < len; ++i) nums[i] = s[i] - '0';
    calc(0);
    cout << ans - 2 << endl;
  }
}
