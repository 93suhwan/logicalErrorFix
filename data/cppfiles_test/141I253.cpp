#include <bits/stdc++.h>
using namespace std;
void getNums(long long a, int* nums, int* returnSize) {
  int len = 0;
  while (a) {
    nums[len++] = a % 10;
    a /= 10;
  }
  *returnSize = len;
}
void printNum(int* nums, int numsSize) {
  bool f = true;
  for (int i = numsSize - 1; i >= 0; i--) {
    if (!nums[i] && f)
      continue;
    else {
      f = false;
      cout << nums[i];
    }
  }
  cout << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, s;
    cin >> a >> s;
    int arr[20] = {0}, srr[20] = {0};
    int aSize = 0, sSize = 0;
    getNums(a, arr, &aSize);
    getNums(s, srr, &sSize);
    int nums[20], numsSize = 0;
    bool flag = true;
    if (aSize == sSize) {
      int ka, ks;
      for (int i = 0, j = 0; j < sSize;) {
        if (j >= sSize) {
          flag = false;
          cout << "-1" << endl;
          break;
        }
        ka = arr[i++];
        ks = srr[j++];
        if (ka > ks) {
          flag = false;
          cout << "-1" << endl;
          break;
        }
        if (ks > 18) {
          flag = false;
          cout << "-1" << endl;
          break;
        }
        nums[numsSize++] = ks - ka;
      }
      if (flag) {
        printNum(nums, numsSize);
      }
    } else if (aSize < sSize) {
      int ka, ks;
      for (int i = 0, j = 0; j < sSize;) {
        if (j >= sSize) {
          flag = false;
          cout << "-1" << endl;
          break;
        }
        ka = arr[i++];
        ks = srr[j++];
        if (ka > ks) {
          ks += srr[j++] * 10;
        }
        if (ks - ka > 10) {
          flag = false;
          cout << "-1" << endl;
          break;
        }
        if (ks > 18) {
          flag = false;
          cout << "-1" << endl;
          break;
        }
        nums[numsSize++] = ks - ka;
      }
      if (flag) printNum(nums, numsSize);
    }
  }
  return 0;
}
