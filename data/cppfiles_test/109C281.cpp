#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
using namespace std;
long long digits[10];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t, n, i, j, k, l, m;
  cin >> t;
  for (i = 0; i < t; i++) {
    cin >> n;
    long long total = 0, number_of_digits_left = 0;
    string nums, sorted_nums;
    cin >> nums;
    sorted_nums = nums;
    for (j = 0; j <= 9; j++) {
      digits[j] = 0;
    }
    for (j = n - 1; j >= 0; j--) {
      if (nums[j] > '0') number_of_digits_left++;
      digits[nums[j] - '0']++;
    }
    if (nums[n - 1] == '0') {
      for (j = 0; j < n - 1; j++) {
        if (nums[j] != '0') {
          swap(nums[j], nums[n - 1]);
          total++;
          break;
        }
      }
    }
    for (; number_of_digits_left > 0; number_of_digits_left--) {
      total += (nums[n - 1] - '0');
      nums[n - 1] = '0';
      for (j = 0; j < n - 1; j++) {
        if (nums[j] != '0') {
          swap(nums[j], nums[n - 1]);
          total++;
          break;
        }
      }
    }
    cout << total << "\n";
  }
  return 0;
}
