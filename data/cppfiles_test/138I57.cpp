#include <bits/stdc++.h>
int pai[505000];
int valor[505000];
std::priority_queue<int, std::vector<int>, std::greater<int>> el_usados[505000];
int capacidade[505000];
std::priority_queue<int> n_usados[505000];
int find(int a) {
  if (pai[a] == a) {
    return a;
  }
  return pai[a] = find(pai[a]);
}
long long resp = 0;
void Union(int a, int b) {
  a = find(a);
  b = find(b);
  if (a != b) {
    resp -= valor[a] + valor[b];
    if (el_usados[b].size() + n_usados[b].size() >
        el_usados[a].size() + n_usados[a].size())
      std::swap(a, b);
    pai[b] = a;
    capacidade[a] += capacidade[b];
    int v1 = valor[a] + valor[b];
    while (el_usados[b].size()) {
      el_usados[a].push(el_usados[b].top());
      el_usados[b].pop();
    }
    while (n_usados[b].size()) {
      n_usados[a].push(n_usados[b].top());
      n_usados[b].pop();
    }
    for (;;) {
      if (!el_usados[a].size() || !n_usados[a].size()) break;
      if (el_usados[a].top() < n_usados[a].top()) {
        int x = el_usados[a].top(), y = n_usados[a].top();
        n_usados[a].pop();
        el_usados[a].pop();
        el_usados[a].push(y);
        n_usados[a].push(x);
        v1 += y - x;
      } else
        break;
    }
    valor[a] = v1;
    resp += valor[a];
  }
}
int bonus = 205000;
int main() {
  for (int i = 0; i != 505000; ++i) {
    pai[i] = i;
  }
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int n, m, q;
  std::cin >> n >> m >> q;
  std::pair<int, int> vals1[n], vals2[m];
  for (int i = 0; i != n; ++i) {
    int x;
    std::cin >> x;
    vals1[i] = {x, i};
    valor[i] = x;
    el_usados[i].push(x);
    capacidade[i] = 1;
    resp += x;
  }
  for (int j = 0; j != m; ++j) {
    int i = j + bonus;
    int x;
    std::cin >> x;
    vals2[j] = {x, i};
    valor[i] = x;
    n_usados[i].push(x);
  }
  std::sort(vals1, &vals1[n]);
  std::sort(vals2, &vals2[m]);
  std::vector<std::pair<int, std::pair<int, int>>> eventos;
  for (int i = 1; i != n; ++i) {
    eventos.push_back({vals1[i].first - vals1[i - 1].first,
                       {vals1[i].second, vals1[i - 1].second}});
  }
  for (int i = 1; i != m; ++i) {
    eventos.push_back({vals2[i].first - vals2[i - 1].first,
                       {vals2[i].second, vals2[i - 1].second}});
  }
  {
    int cur1 = 0, cur2 = 0;
    int last = -1;
    for (;;) {
      if (cur1 == n || cur2 == m) break;
      if (vals1[cur1].first > vals2[cur2].first) {
        if (last != -1) {
          eventos.push_back({abs(vals2[cur2].first - vals1[last].first),
                             {vals2[cur2].second, vals1[last].second}});
        }
        ++cur2;
        continue;
      } else {
        eventos.push_back({abs(vals2[cur2].first - vals1[cur1].first),
                           {vals2[cur2].second, vals1[cur1].second}});
        last = cur1;
        ++cur1;
        continue;
      }
    }
    cur1 = 0, cur2 = 0;
    last = -1;
    for (;;) {
      if (cur1 == n || cur2 == m) break;
      if (vals1[cur1].first < vals2[cur2].first) {
        if (last != -1) {
          eventos.push_back({abs(vals2[cur2].first - vals1[last].first),
                             {vals2[cur2].second, vals1[last].second}});
        }
        ++cur1;
        continue;
      } else {
        eventos.push_back({abs(vals2[cur2].first - vals1[cur1].first),
                           {vals2[cur2].second, vals1[cur1].second}});
        last = cur2;
        ++cur2;
        continue;
      }
    }
  }
  long long resps[q];
  for (int i = 0; i != q; ++i) {
    int x;
    std::cin >> x;
    eventos.push_back({x + 1, {-1, i}});
  }
  std::sort(eventos.begin(), eventos.end());
  for (auto& x : eventos) {
    if (x.second.first == -1) {
      resps[x.second.second] = resp;
    } else {
      Union(x.second.second, x.second.first);
    }
  }
  for (int i = 0; i != q; ++i) {
    std::cout << resps[i] << "\n";
  }
}
