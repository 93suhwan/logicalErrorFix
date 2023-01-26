#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  long long int T;
  scanf("%lld", &T);
  for (long long int z = 0; z < T; z++) {
    long long int n;
    scanf("%lld", &n);
    long long int arr[n];
    for (long long int i = 0; i < n; i++) {
      scanf("%lld", &arr[i]);
    }
    double avg1 = 0.0;
    double avg2 = 0.0;
    long long int maxindex = 0;
    long long int maxi = arr[0];
    for (long long int i = 0; i < n; i++) {
      if (arr[i] >= maxi) {
        maxi = arr[i];
        maxindex = i;
      }
    }
    avg1 = (double)maxi;
    double sumi = 0;
    for (long long int i = 0; i < n; i++) {
      if (i != maxindex) {
        sumi += arr[i];
      }
    }
    avg2 = (double)(sumi / (n - 1));
    avg2 += avg1;
    printf("%lf \n", avg2);
  }
  return 0;
}
