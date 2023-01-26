#include <bits/stdc++.h>
using namespace std;
const int DIM = 1e5 + 5;
int T, n, m, arr[DIM], cnt[DIM], v[DIM], s[DIM][3][2];
int aib[305][305];
int query(int l, int p) {
  int sum = 0;
  for (; p >= 1; p -= (p & -p)) {
    sum += aib[l][p];
  }
  return sum;
}
void update(int l, int p) {
  for (; p <= m; p += (p & -p)) {
    aib[l][p]++;
  }
}
int get_pos(int x) {
  if (s[x][0][1] != 0) {
    int val = s[x][0][0];
    s[x][0][0]--;
    s[x][0][1]--;
    return val;
  }
  if (s[x][1][1] != 0) {
    int val = s[x][1][0];
    s[x][1][0]--;
    s[x][1][1]--;
    return val;
  }
  int val = s[x][2][0];
  s[x][2][0]--;
  s[x][2][1]--;
  return val;
}
int main() {
  for (cin >> T; T; T--) {
    cin >> n >> m;
    memset(arr, 0, sizeof(arr));
    for (int i = 1; i <= n * m; i++) {
      cin >> arr[i];
    }
    memset(aib, 0, sizeof(aib));
    memset(cnt, 0, sizeof(cnt));
    memset(s, 0, sizeof(s));
    memcpy(v, arr, sizeof(arr));
    sort(arr + 1, arr + n * m + 1);
    cnt[1] = 1;
    int k = 1;
    for (int i = 2; i <= n * m; i++) {
      if (arr[i] == arr[k]) {
        cnt[k]++;
      } else {
        k++;
        arr[k] = arr[i];
        cnt[k] = 1;
      }
    }
    for (int i = 1; i <= k; i++) cnt[i] += cnt[i - 1];
    for (int i = 1; i <= k; i++) {
      int x, y;
      int a = cnt[i - 1] + 1;
      int b = cnt[i];
      x = a / m + (a % m == 0 ? 0 : 1);
      y = a % m;
      if (y == 0) y = m;
      if (y != 1) {
        s[i][0][0] = x * m;
        s[i][0][1] = m - y + 1;
      }
      x = b / m + (b % m == 0 ? 0 : 1);
      y = b % m;
      if (y == 0) y = m;
      if (y != m) {
        s[i][2][0] = b;
        s[i][2][1] = y;
      }
      s[i][1][0] = b - s[i][2][1];
      s[i][1][1] = (b - a + 1) - s[i][0][1] - s[i][2][1];
    }
    int ans = 0;
    for (int i = 1; i <= n * m; i++) {
      int st = 1;
      int dr = k;
      while (st <= dr) {
        int mid = (st + dr) >> 1;
        if (arr[mid] <= v[i])
          st = mid + 1;
        else
          dr = mid - 1;
      }
      int val_pos = get_pos(dr);
      int x = val_pos / m + (val_pos % m == 0 ? 0 : 1);
      int y = val_pos % m;
      if (y == 0) y = m;
      ans += query(x, y);
      update(x, y);
    }
    cout << ans << "\n";
  }
  return 0;
}
