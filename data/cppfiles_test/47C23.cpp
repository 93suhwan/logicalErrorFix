#include <bits/stdc++.h>
using namespace std;
void swap(vector<long long int> &v, long long int i, long long int j) {
  if (i < 0 || j >= v.size()) {
    return;
  }
  auto temp = v[i];
  v[i] = v[j];
  v[j] = temp;
  return;
}
void swap(long long int &a, long long int &b) {
  long long int temp = a;
  a = b;
  b = temp;
}
void dv(vector<long long int> g1) {
  for (auto i = g1.begin(); i != g1.end(); ++i) {
    cout << *i << " ";
  }
}
long long int invert(long long int a) {
  if (a == 0) {
    return 1;
  } else if (a == 1) {
    return 0;
  } else {
    return -1;
  }
}
long long int fact(long long int n) {
  long long int res = 1;
  for (long long int i = 2; i <= n; i++) res = res * i % 1000000007;
  return res;
}
long long int nCr(long long int n, long long int r) {
  return (fact(n) / (fact(r) * fact(n - r))) % 1000000007;
}
long long int nCr1(long long int a, long long int b) {
  if (b > a) {
    return 0;
  } else {
    long long int ans = 1;
    for (long long int i = b + 1; i < a + 1; ++i) {
      ans = ans * i % 1000000007;
    }
    return ans;
  }
}
long long int func(long long int a) {
  if (a % 2 == 0) {
    return -1;
  } else {
    return 1;
  }
}
long long int sumofdigits(long long int n) {
  long long int sum = 0;
  while (n) {
    sum += n % 10;
    n = n / 10;
  }
  return sum;
}
long long int poweroftwo(long long int n) {
  if (n <= 0) {
    return -1;
  }
  long long int ans = 0;
  while (n != 1) {
    n = n / 2;
    ans++;
  }
  return ans;
}
long long int noofdigits(long long int n) {
  if (n <= 0) {
    return 0;
  }
  long long int ans = 0;
  while (n) {
    ans++;
    n = n / 10;
  }
  return ans;
}
long long int nooofonesinbits(long long int n) {
  long long int count = 0;
  while (n) {
    count += n & 1;
    n >>= 1;
  }
  return count;
}
long long int __ceil(long long int a, long long int b) {
  return (a + b - 1) / b;
}
long long int __pow(long long int a, long long int b) {
  if (b == 0) {
    return 1;
  }
  long long int res = __pow(a, b / 2);
  if (b % 2) {
    return res * res * a;
  } else {
    return res * res;
  }
}
int main() {
  long long int n, k;
  cin >> n >> k;
  vector<long long int> a;
  long long int x1, x2, y1, y2, z1, z2;
  cout << "and " << 1 << ' ' << 2 << endl;
  cin >> x1;
  cout << "or " << 1 << ' ' << 2 << endl;
  cin >> x2;
  cout << "and " << 2 << ' ' << 3 << endl;
  cin >> y1;
  cout << "or " << 2 << ' ' << 3 << endl;
  cin >> y2;
  cout << "and " << 1 << ' ' << 3 << endl;
  cin >> z1;
  cout << "or " << 1 << ' ' << 3 << endl;
  cin >> z2;
  long long int ab, bc, ca;
  ab = (long long int)(x1 | x2) + (long long int)(x1 & x2);
  bc = (long long int)(y1 | y2) + (long long int)(y1 & y2);
  ca = (long long int)(z1 | z2) + (long long int)(z1 & z2);
  long long int x = (ab - bc + ca) / 2;
  a.push_back(x);
  a.push_back(ab - x);
  a.push_back(ca - x);
  for (long long int i = 3; i < n; ++i) {
    long long int t1, t2;
    cout << "and 1 " << i + 1 << endl;
    cin >> t1;
    cout << "or 1 " << i + 1 << endl;
    cin >> t2;
    long long int temp = (long long int)(t1 | t2) + (long long int)(t1 & t2);
    a.push_back(temp - a[0]);
  }
  sort(a.begin(), a.end());
  cout << "finish " << a[k - 1] << endl;
  dv(a);
  cout << endl;
}
