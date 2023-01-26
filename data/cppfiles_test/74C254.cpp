#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
long long gcd(long long a, long long b) { return (!b) ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
void taskpe53() {
  long long c[110][110] = {};
  for (int i = (0); i < (110); i++) c[0][i] = 1;
  for (int i = (1); i < (100); i++) c[i][i] = 1;
  for (int i = (1); i < (110); i++) c[1][i] = i;
  int cnt = 0;
  long long N = 1e6;
  for (int i = (1); i < (101); i++)
    for (int j = (i + 1); j < (101); j++) {
      c[i][j] = c[i][j - 1] + c[i - 1][j - 1];
      if (c[i][j] > N) c[i][j] = N + 1;
    }
  for (int i = (1); i < (101); i++)
    for (int j = (i); j < (101); j++)
      if (c[i][j] > N) cnt++;
  cout << " n = " << N << " ";
  cout << c[10][23] << " = c[10,23]\n";
  cout << cnt << "\n";
  return;
}
int getValue(string s) {
  int res = 0;
  string tmp = "", suit = "";
  string poke = "234567891JQKA";
  int a[5] = {};
  for (int i = 0; i < s.size(); i += 3) {
    tmp.push_back(s[i]);
    suit.push_back(s[i + 1]);
    for (int j = (0); j < (poke.size()); j++)
      if (poke[j] == s[i]) a[i / 3] = j + 1;
  }
  int vis[5] = {};
  for (int i = (0); i < (5); i++) {
    for (int j = (i + 1); j < (5); j++)
      if (a[i] == a[j]) {
        vis[i] = vis[j] = 1;
        int x = 0, y1 = 0, z = 0, y = 0;
        for (int k = (0); k < (5); k++)
          if (!vis[k]) x = (suit[k] - 'a' + 1);
        for (int k = (0); k < (5); k++)
          if (!vis[k]) y1 += (suit[k] - 'a' + 1);
        for (int k = 4; k >= 0; k--)
          if (!vis[k]) z = (suit[k] - 'a' + 1);
        y = y1 - x - z;
        if (x != z and x != y and y != z) res = max(res, a[i] + 700);
        if (a[3] == a[4])
          res += a[2];
        else
          res += a[4];
      }
  }
  sort(tmp.begin(), tmp.end()), sort(suit.begin(), suit.end()), sort(a, a + 5);
  if (tmp == "1AJKQ") return 1000;
  if (suit[0] == suit[4] and a[0] == a[4] + 4) res = max(res, a[0] + 900);
  if (a[0] == a[3] or a[1] == a[4]) {
    res = max(res, (a[2]) + 800);
    if (a[0] == a[3])
      res += a[4];
    else
      res += a[0];
  }
  if (suit[0] == suit[4]) res = max(res, a[4] + 600);
  if (a[0] == a[1] - 1 and a[1] == a[2] - 1 and a[2] == a[3] - 1 and
      a[3] == a[4] - 1)
    res = max(res, a[4] + 500);
  if (a[0] == a[2] or a[1] == a[3] or a[2] == a[4]) res = max(res, a[2] + 400);
  if ((a[1] == a[2] and a[3] == a[4]) or (a[0] == a[1] and a[3] == a[4]) or
      (a[0] == a[1] and a[2] == a[3]))
    res = max(res, a[3] + 300);
  if (a[0] == a[1] or a[1] == a[2] or a[2] == a[3] or a[3] == a[4]) {
    res = max(res, a[1] * (a[0] == a[1]) + a[1] * (a[1] == a[2]) +
                       a[3] * (a[2] == a[3]) + a[3] * (a[3] == a[4]) + 200);
    if (a[0] == a[1] or a[1] == a[2] or a[2] == a[3])
      res += a[4];
    else
      res += a[2];
  }
  res = max(res, a[4] + 100);
  return res;
}
void taskpe54() {
  string s;
  int cnt = 0;
  while (getline(cin, s)) {
    int ma1 = 0, ma2 = 0;
    if (s.size() < 29) continue;
    ma1 = getValue(s.substr(0, 14));
    ma2 = getValue(s.substr(15, 29));
    if (ma1 > ma2) cnt++;
  }
  cout << cnt;
  return;
}
bool is_lychrel_number(int x) {
  vector<int> a;
  while (x) {
    a.push_back(x % 10);
    x /= 10;
  }
  int number = 0;
  while (number++ <= 50) {
    int len = a.size();
    vector<int> b = a;
    reverse(a.begin(), a.end());
    vector<int> sum = a;
    if (number > 1 and a == b) return false;
    int flag = 0;
    for (int i = (0); i < (len); i++) {
      sum[i] += b[i] + flag;
      if (sum[i] > 9)
        sum[i] -= 10, flag = 1;
      else
        flag = 0;
    }
    if (flag) sum.push_back(flag), len++;
    a.clear();
    a = sum;
    sum.clear();
  }
  return true;
}
void taskpe55() {
  int cnt = 0;
  int N = 1e4;
  cout << "N = " << N << "\n";
  for (int i = (1); i < (N); i++) {
    if (is_lychrel_number(i)) cnt++;
  }
  cout << cnt;
  return;
}
void taskA() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = (0); i < (n); i++) cin >> a[i], b[i] = i + 1;
    if (a == b) {
      cout << "0\n";
      continue;
    }
    int x = 1, ans = 0;
    while (a != b) {
      if (x == 1) {
        for (int i = 0; i < n - 2; i += 2) {
          if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);
        }
      } else {
        for (int i = 1; i < n - 1; i += 2) {
          if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);
        }
      }
      x *= -1;
      ans++;
    }
    cout << ans << "\n";
  }
  return;
}
void taskB() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, n;
    cin >> a >> b;
    set<int> ans;
    for (int c = (0); c < (2); c++) {
      int q = (a + b + c) / 2, p = (a + b - c) / 2;
      for (int x = (0); x <= (q); x++) {
        int y = b - q + x;
        int z = a - q + x;
        if (y <= p and y >= 0) ans.insert(x + y);
        if (z <= p and z >= 0) ans.insert(z + x);
      }
    }
    cout << ans.size() << "\n";
    for (auto it : ans) cout << it << " ";
    cout << "\n";
  }
  return;
}
void taskC() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int, int> > a;
    for (int i = (0); i < (n); i++) {
      int k;
      cin >> k;
      int y = 0;
      for (int j = (0); j < (k); j++) {
        int x;
        cin >> x;
        y = max(y, x - j);
      }
      a.push_back({y + 1, k});
    }
    sort(a.begin(), a.end());
    int ans = a[0].first, tmp = ans + a[0].second;
    if (n == 1) {
      cout << ans << "\n";
      continue;
    }
    for (int i = (1); i < (n); i++) {
      if (tmp >= a[i].first) {
        tmp += a[i].second;
        ;
        continue;
      }
      ans += (a[i].first - tmp);
      tmp = a[i].first + a[i].second;
      ;
    }
    cout << ans << "\n";
  }
  return;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  auto start = high_resolution_clock::now();
  taskB();
  auto end = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(end - start);
  return 0;
}
