#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const unsigned gen_seed =
    std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);
const int N = 1000500;
int mindiv[N + 1];
struct sega {
  sega(){};
  sega(int v) { add(v); };
  map<int, int> deg;
  int numbad = 0;
  void add(int v) {
    while (v > 1) {
      deg[mindiv[v]]++;
      if (deg[mindiv[v]] == 0) numbad--;
      v /= mindiv[v];
    }
  }
  void rem(int v) {
    while (v > 1) {
      deg[mindiv[v]]--;
      if (deg[mindiv[v]] == -1) numbad++;
      v /= mindiv[v];
    }
  }
  void killjoin(sega& f) {
    if (f.deg.size() > deg.size()) {
      swap(f.deg, deg);
      swap(numbad, f.numbad);
    }
    for (auto x : f.deg) {
      if (deg[x.first] < 0) numbad--;
      deg[x.first] += x.second;
      if (deg[x.first] < 0) numbad++;
    }
  }
  bool isbad() { return numbad > 0; }
};
int main() {
  vector<long long> pr;
  std::vector<int> isp(N + 1, 0);
  for (int i = 2; i <= N; ++i) {
    if (mindiv[i] == 0) {
      mindiv[i] = i;
      pr.push_back(i);
      isp[i] = 1;
    }
    for (int j = 0; j < (int)pr.size() && pr[j] <= mindiv[i] && i * pr[j] <= N;
         ++j)
      mindiv[i * pr[j]] = pr[j];
  }
  int n;
  scanf("%d", &n);
  std::vector<int> a(n);
  char c[1000500];
  for (int i = 0; i < n; i++) {
    if (i < n - 1)
      scanf("%d", &a[i]);
    else
      scanf("%d\n", &a[i]);
  }
  scanf("%s", c);
  string s(c);
  vector<sega> q;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    sega cur;
    if (s[i] == '*')
      cur.add(a[i]);
    else
      cur.rem(a[i]);
    while (cur.isbad()) {
      if (q.empty()) break;
      cur.killjoin(q.back());
      q.pop_back();
    }
    if (cur.isbad() == false) {
      q.emplace_back(std::move(cur));
    }
    ans += q.size();
  }
  cout << ans;
}
