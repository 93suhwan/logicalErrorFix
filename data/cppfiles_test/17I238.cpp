#include <bits/stdc++.h>
using namespace std;
const int N = 50000 + 5;
const int M = 1e9 + 7;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void quickSort(int a[], int b[], int l, int r) {
  int p = a[(l + r) / 2];
  int i = l, j = r;
  while (i < j) {
    while (a[i] < p) {
      i++;
    }
    while (a[j] > p) {
      j--;
    }
    if (i <= j) {
      int temp = a[i];
      a[i] = a[j];
      a[j] = temp;
      temp = b[i];
      b[i] = b[j];
      b[j] = temp;
      i++;
      j--;
    }
  }
  if (i < r) {
    quickSort(a, b, i, r);
  }
  if (l < j) {
    quickSort(a, b, l, j);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, vong1[N], vong2[N], vong3[N], vong4[N], vong5[N];
    int pos1[N], pos2[N], pos3[N], pos4[N], pos5[N];
    cin >> n;
    int a[7][N] = {};
    for (int i = 1; i <= n; i++)
      cin >> vong1[i] >> vong2[i] >> vong3[i] >> vong4[i] >> vong5[i],
          pos1[i] = pos2[i] = pos3[i] = pos4[i] = pos5[i] = i;
    for (int i = 1; i <= n; i++)
      a[1][i] = vong1[i], a[2][i] = vong2[i], a[3][i] = vong3[i],
      a[4][i] = vong4[i], a[5][i] = vong5[i];
    quickSort(vong1, pos1, 1, n);
    quickSort(vong2, pos2, 1, n);
    quickSort(vong3, pos3, 1, n);
    quickSort(vong4, pos4, 1, n);
    quickSort(vong5, pos5, 1, n);
    int ans = 0;
    int bangchanly[N] = {};
    for (int i = 1; i <= n; i++) {
      int q1 = lower_bound(vong1 + 1, vong1 + 1 + n, a[1][i]) - vong1;
      int q2 = lower_bound(vong2 + 1, vong2 + 1 + n, a[2][i]) - vong2;
      int q3 = lower_bound(vong3 + 1, vong3 + 1 + n, a[3][i]) - vong3;
      int q4 = lower_bound(vong4 + 1, vong4 + 1 + n, a[4][i]) - vong4;
      int q5 = lower_bound(vong5 + 1, vong5 + 1 + n, a[5][i]) - vong5;
      if (q1 >= 5 && q2 >= 5 && q3 >= 5 && q4 >= 5 && q5 >= 5) continue;
      for (int j = q1 + 1; j <= n; j++) bangchanly[pos1[j]]++;
      for (int j = q2 + 1; j <= n; j++) bangchanly[pos2[j]]++;
      for (int j = q3 + 1; j <= n; j++) bangchanly[pos3[j]]++;
      for (int j = q4 + 1; j <= n; j++) bangchanly[pos4[j]]++;
      for (int j = q5 + 1; j <= n; j++) bangchanly[pos5[j]]++;
      int x = 0;
      for (int j = 1; j <= n; j++) {
        if (bangchanly[j] >= 3) ++x;
        bangchanly[j] = 0;
      }
      if (x >= n - 1) {
        ++ans;
        cout << i << endl;
        break;
      }
    }
    if (ans == 0) cout << -1 << endl;
  }
}
