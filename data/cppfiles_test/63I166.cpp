#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long n) {
  if (n == 0)
    return 1;
  else if (n % 2 == 0)
    return power((x * x), n / 2);
  else
    return (x * power((x * x), (n - 1) / 2));
}
long long C(long long n, long long r) {
  if (r > n - r) r = n - r;
  long long ans = 1;
  int i;
  for (i = 1; i <= r; i++) {
    ans = ((ans) * (n - r + i));
    ans = (ans) / i;
  }
  return ans;
}
long long modularExponentiation(long long x, long long n, long long M) {
  if (n == 0)
    return 1;
  else if (n % 2 == 0)
    return modularExponentiation((x * x) % M, n / 2, M);
  else
    return (x % M * modularExponentiation((x * x) % M, (n - 1) / 2, M) % M) % M;
}
long long modInverse(long long A, long long M) {
  return modularExponentiation(A, M - 2, M);
}
long long prime_factorisation(long long temp) {
  int i, count = 0;
  for (i = 2; i * i <= temp; i++) {
    while (temp % i == 0) {
      temp = temp / i;
      count++;
    }
  }
  if (temp > 1) count++;
  return count;
}
long long divisors(long long temp, long long k) {
  int i, temp1 = 1, t1;
  for (i = 1; i <= temp / i; i++) {
    if (temp % i == 0) {
      t1 = temp / i;
      if (t1 <= k)
        return t1;
      else if (i <= k) {
        temp1 = i;
      }
    }
  }
  return temp1;
}
long long find(long long i, vector<int> &arr) {
  if (arr[i] == i)
    return i;
  else {
    arr[i] = find(arr[i], arr);
  }
  return arr[i];
}
void union1(long long xr, long long yr, vector<int> &arr, vector<int> &siz) {
  xr = find(xr, arr);
  yr = find(yr, arr);
  if (siz[xr] < siz[yr]) {
    arr[xr] = arr[yr];
    siz[yr] += siz[xr];
  } else {
    arr[yr] = arr[xr];
    siz[xr] += siz[yr];
  }
}
void solve() {
  long long n, m1, m2, temp1, temp2, temp3, temp4, i, j, max, count = 0, ans;
  cin >> n >> m1 >> m2;
  vector<int> arr1(n + 7, 0);
  vector<int> arr2(n + 7, 0);
  vector<int> siz1(n + 7, 0);
  vector<int> siz2(n + 7, 0);
  vector<int> v1;
  vector<int> v2;
  vector<int> v3;
  vector<int> v4;
  int edge1[n + 7][n + 7];
  int edge2[n + 7][n + 7];
  memset(edge1, 0, sizeof(edge1));
  memset(edge2, 0, sizeof(edge2));
  for (i = 1; i <= n; i++) {
    arr1[i] = i;
    siz1[i] = 1;
    arr2[i] = i;
    siz2[i] = 1;
  }
  for (i = 0; i < m1; i++) {
    cin >> temp1 >> temp2;
    union1(temp1, temp2, arr1, siz1);
    edge1[temp1][temp2] = 1;
    edge1[temp2][temp1] = 1;
  }
  for (i = 0; i < m2; i++) {
    cin >> temp1 >> temp2;
    union1(temp1, temp2, arr2, siz2);
    edge2[temp1][temp2] = 1;
    edge2[temp2][temp1] = 1;
  }
  max = -1;
  for (i = 1; i <= n; i++) {
    count = 0;
    v1 = arr1;
    v2 = arr2;
    v3 = siz1;
    v4 = siz2;
    for (j = 1; j <= n; j++) {
      if (i != j) {
        if (edge1[i][j] == 0 && edge2[i][j] == 0) {
          temp1 = find(i, v1);
          temp2 = find(j, v1);
          temp3 = find(i, v2);
          temp4 = find(j, v2);
          if (temp1 != temp2 && temp3 != temp4) {
            count++;
            union1(i, j, v1, v3);
            union1(i, j, v2, v4);
          }
        }
      }
    }
    if (count > max) {
      max = count;
      ans = i;
    }
  }
  if (max == -1)
    cout << "0" << endl;
  else {
    cout << max << endl;
    for (i = 1; i <= n; i++) {
      if (i != ans) {
        if (edge1[i][ans] == 0 && edge2[i][ans] == 0) {
          temp1 = find(i, arr1);
          temp2 = find(ans, arr1);
          temp3 = find(i, arr2);
          temp4 = find(ans, arr2);
          if (temp1 != temp2 && temp3 != temp4) {
            union1(i, ans, arr1, siz1);
            union1(i, ans, arr2, siz2);
            cout << i << " " << ans;
            cout << endl;
          }
        }
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
