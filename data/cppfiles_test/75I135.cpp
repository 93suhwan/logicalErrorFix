#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  long long A[n];
  for (int i = 0; i < n; scanf("%lld", &A[i++]))
    ;
  int left = 0, right = n - 1;
  for (; A[left] < A[left + 1], left < right; left++)
    ;
  for (; (A[right] < A[right - 1]) && (right > left); right--)
    ;
  right = n - right;
  left++;
  if ((right % 2 == 0) && (left % 2 == 0))
    printf("Bob\n");
  else
    printf("Alice\n");
}
