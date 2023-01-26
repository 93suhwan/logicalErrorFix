#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> A(n);
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
  }
  int leftLen = 1, rightLen = 1;
  for (int i = 1; i < n; ++i) {
    if (A[i] > A[i - 1])
      ++leftLen;
    else
      break;
  }
  for (int i = n - 2; i >= 0; --i) {
    if (A[i] > A[i + 1])
      ++rightLen;
    else
      break;
  }
  int _max = -1;
  int Alice = 0;
  int l = 0, r = n - 1;
  while (l <= r) {
    if (A[l] <= _max && A[r] <= _max) break;
    if (A[l] > _max && A[l] <= A[r] && rightLen % 2 == 0) {
      _max = A[l++];
      --leftLen;
    } else if (A[r] > _max && A[l] >= A[r] && leftLen % 2 == 0) {
      _max = A[r--];
      --rightLen;
    } else if (A[l] > _max) {
      _max = A[l++];
      --leftLen;
    } else if (A[r] > _max) {
      _max = A[r--];
      --rightLen;
    }
    Alice = 1 - Alice;
  }
  Alice == 1 ? printf("Alice") : printf("Bob");
  return 0;
}
