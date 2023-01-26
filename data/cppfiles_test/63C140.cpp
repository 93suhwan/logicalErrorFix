#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
long long arr[N];
const long long mod = 1e9 + 7;
long long addt(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long mult(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long subt(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
long long expt(long long x, long long n, long long m) {
  long long ans = 1;
  while (n > 0) {
    if (n % 2 == 1) ans = (ans * x) % m;
    x = (x * x) % m;
    n /= 2;
  }
  return ans;
}
const long long N1 = 1005;
long long parent1[N1], parent2[N1], siz1[N1], siz2[N1];
void make_set1(long long v) {
  parent1[v] = v;
  siz1[v] = 1;
}
long long find_set1(long long v) {
  if (parent1[v] == v) return v;
  return parent1[v] = find_set1(parent1[v]);
}
void union_sets1(long long a, long long b) {
  a = find_set1(a);
  b = find_set1(b);
  if (a != b) {
    if (siz1[a] < siz1[b]) swap(a, b);
    parent1[b] = a;
    siz1[a] += siz1[b];
  }
}
void make_set2(long long v) {
  parent2[v] = v;
  siz2[v] = 1;
}
long long find_set2(long long v) {
  if (parent2[v] == v) return v;
  return parent2[v] = find_set2(parent2[v]);
}
void union_sets2(long long a, long long b) {
  a = find_set2(a);
  b = find_set2(b);
  if (a != b) {
    if (siz2[a] < siz2[b]) swap(a, b);
    parent2[b] = a;
    siz2[a] += siz2[b];
  }
}
void solution() {
  long long n, m, x, i, j, m1, m2, a, b;
  cin >> n >> m1 >> m2;
  for (i = 1; i <= n; i++) {
    make_set1(i);
    make_set2(i);
  }
  vector<pair<long long, long long> > v1, v2;
  for (i = 0; i < m1; i++) {
    cin >> a >> b;
    v1.push_back({a, b});
    union_sets1(a, b);
  }
  for (i = 0; i < m2; i++) {
    cin >> a >> b;
    v2.push_back({a, b});
    union_sets2(a, b);
  }
  vector<pair<long long, long long> > ans;
  for (i = 1; i < n; i++) {
    for (j = i + 1; j <= n; j++) {
      if (find_set1(i) != find_set1(j) && find_set2(i) != find_set2(j)) {
        ans.push_back({i, j});
        union_sets1(i, j);
        union_sets2(i, j);
      }
    }
  }
  cout << ((long long)(ans).size()) << "\n";
  for (auto pr : ans) {
    cout << pr.first << " " << pr.second << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long tc, cs;
  tc = 1;
  for (cs = 1; cs <= tc; cs++) {
    solution();
  }
  return 0;
}
