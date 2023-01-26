#include <iostream>
#include<vector>
#include<queue>
#include<fstream>
#include<algorithm>
#include<set>
#include<cmath>
#include<iomanip>
#include<string>
#include<map>
#include<bitset>
#include <valarray> 
#include <stack> 

using namespace std;
#define molnia_makvin ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0); 
#define vint vector<int>
#define v2int vector<vector<int>>
#define v2char vector<vector<char>>
#define vchar vector<char>
#define vintp vector<pair<int,int>>
#define vcharint vector<pair<char,int>>
#define gg return ;
#define endl '\n';
typedef string str;
typedef long long  ll;


template <typename T>
void rev(vector<T>& v) {
	reverse(v.begin(), v.end());
}

ll mod = 1000000000 + 7;
ll inf = 1e9;
const ll maxn = 2 * 100'000;

int l = 179; // нужная нам длина
int ans = 0;

// нам лень явно удалять вершины: заведем массив used -- была ли вершина удалена
bool used[maxn];
int s[maxn]; // размеры поддеревьев
vector<vector<int> > g;

void sizes(int v, int p = -1) {
    s[v] = 1;
    for (int u : g[v])
        if (u != p && !used[u])
            sizes(u, v), s[v] += s[u];
}

int centroid(int v, int p, int n) {
    for (int u : g[v])
        if (u != p && !used[u] && s[u] > n / 2)
            return centroid(u, v, n);
    return v;
}

void dfs(int v, int p, int d, vector<int>& t) {
    t.push_back(d);
    for (int u : g[v])
        if (u != p && !used[u])
            dfs(u, v, d + 1, t);
}

void solve(int v) {
    /* <единственный зависящий от конкретной задачи код> */
    sizes(v);
    vector<int> d(s[v], 0);
    d[0] = 1;
    for (int u : g[v]) {
        if (!used[u]) {
            vector<int> t;
            dfs(u, v, 1, t);
            for (int x : t)
                if (x <= l)
                    ans += d[l - x];
            for (int x : t)
                d[x]++;
        }
    }
    /* </единственный зависящий от конкретной задачи код> */

    used[v] = 1;
    for (int u : g[v]) {
        if (!used[u]) {
            solve(centroid(u, v, s[u]));
        }
    }

}

void solve() {
    ll n; cin >> n;
    if (n % 3 == 0) {
        cout << n / 3 << ' ' << n / 3 << endl;
    }
    else {
        cout << n / 3 + 1 << ' ' << n / 3 << endl;
    }
}

int main()
{
	molnia_makvin;
    int t; cin >> t;
    while (t--) {
        solve();
    }
}