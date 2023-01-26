#include <iostream>
#include <iomanip>
#include <string>
#include <unordered_map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
#include <algorithm>
#include <utility>
#include <cmath>
#include <complex>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

#define llpoint complex<dd>
#define matrix(n, m, dtype, name) vector<vector<dtype>> name(n, vector<dtype>(m))

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef double dd;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> index_set;

const ll inf = 1e18 + 7;

/*---------------- Template---------------- */

// vectorize
template <typename T>
T sum(const vector<T> &x)
{
    T res = T();
    for (auto it : x)
    {
        res += it;
    }
    return res;
}

template <typename T>
T sum(const vector<T> &x, const ll mod)
{
    T res = T();
    for (auto it : x)
    {
        res = (res + it) % mod;
    }
    return res;
}

template <typename T>
T min(vector<T> &v)
{
    T r = v[0];
    for (auto &it : v)
        r = min(r, it);
    return r;
}

template <typename T>
T max(vector<T> &v)
{
    T r = v[0];
    for (auto &it : v)
        r = max(r, it);
    return r;
}

template <typename T>
int argmin(vector<T> &v)
{
    T minn = v[0];
    int ans = 0;
    for (int i = 1; i < v.size(); ++i)
    {
        if (v[i] < minn)
        {
            ans = i;
            minn = v[i];
        }
    }
    return ans;
}

template <typename T>
int argmax(vector<T> &v)
{
    T maxx = v[0];
    int ans = 0;
    for (int i = 1; i < v.size(); ++i)
    {
        if (v[i] > maxx)
        {
            ans = i;
            maxx = v[i];
        }
    }
    return ans;
}

// Module operator
ll norm_mod(const ll &x, const ll &mod)
{
    return ((x % mod + mod) % mod);
}

ll mul_mod(const ll &a, const ll &b, const ll &mod)
{
    return a * b % mod;
}

ll add_mod(const ll &a, const ll &b, const ll &mod)
{
    return norm_mod(a + b, mod);
}

// matrix
template<typename T>
struct Matrix
{
int n, m;
vector<vector<T>> data;
Matrix(int n, int m){
    this->n = n;
    this->m = m;
    data.resize(n, vector<T>(m));
}
Matrix(const vector<vector<T>> &v){
    this->n = v.size();
    this->m = (v.empty()) ? 0 : v[0].size();
    data = v;
}
static Matrix<T> identity(int n){
    vector<vector<T>> v(n, vector<T>(n));
    for (int i = 0; i < n; ++i)
        v[i][i] = 1;
    return Matrix(v);
}
const vector<T> &operator[](const int &id) const{
    return this->data[id];
}
vector<T> &operator[](const int &id){
    return this->data[id];
}
Matrix<T> operator*(const Matrix<T> &x){
    Matrix<T> res(this->n, x.m);
    assert(this->m == x.n);
    for (int i = 0; i < this->n; ++i){
        for (int j = 0; j < x.m; ++j){
            for (int z = 0; z < x.n; ++z){
                res[i][j] += (*this)[i][z] * x[z][j];
            }
        }
    }
    return res;
}
Matrix<T> operator%(const ll &mod){
    Matrix<T> res(*this);
    for (int i = 0; i < this->n; ++i){
        for (int j = 0; j < this->m; ++j){
            res[i][j] = norm_mod(res[i][j], mod);
        }
    }
    return res;
}
Matrix<T> pow(ll b, const ll & mod){
    assert(this->n == this->m);
    Matrix<T> res = Matrix::identity(this->n);
    Matrix<T> a(*this);
    while (b){
        if (b & 1)
            res = res * a % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return res;
}
friend ostream &operator << (ostream &out, const Matrix<T> x){
    for (auto & it: x.data)
        out << it << "\n";
    return out;
}
};

ll pow(ll a, ll b, const ll &mod)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = mul_mod(res, a, mod);
        b >>= 1;
        a = mul_mod(a, a, mod);
    }
    return res;
}

ll mul(ll a, ll b, const ll &mod)
{
    ll res = 0;
    while (b)
    {
        if (b & 1)
            res = add_mod(res, a, mod);
        b >>= 1;
        a = add_mod(a, a, mod);
    }
    return res;
}

bool is_prime(ll x)
{
    if (x == 2)
        return true;
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0)
            return false;
    return true;
}

void sieve(vector<int> &is_prime)
{
    int n = is_prime.size();
    for (int i = 0; i < is_prime.size(); ++i)
        is_prime[i] = i;
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i * i < n; ++i)
    {
        if (is_prime[i] == i)
        {
            for (int j = i * i; j < n; j += i)
                is_prime[j] = i;
        }
    }
}

void extended_euclid(const ll &a, const ll &b, ll &x, ll &y, ll &d)
{
    if (a == 0)
    {
        d = b;
        x = 0;
        y = 1;
    }
    else
    {
        extended_euclid(b % a, a, x, y, d);
        int temp = x;
        x = y - b / a * x;
        y = temp;
    }
}

ll inverse(ll &c, const ll &mod)
{
    ll x, y, d;
    extended_euclid(c, mod, x, y, d);
    return norm_mod(x, mod);
}


ll toHop(int n, int k, vector<vector<ll>> &res)
{
    if (k > n || n < 0 || k < 0)
        return 0;

    if (k == n || k == 0)
        return res[n][k] = 1;

    if (res[n][k] != -1)
        return res[n][k];
    return res[n][k] = toHop(n - 1, k - 1, res) + toHop(n - 1, k, res);
}

ll toHop(int n, int k, const ll &mod, const vector<ll> &gt, const vector<ll> &inv_gt)
{
    if (k > n)
        throw out_of_range("k phai <= n");
    return gt[n] * inv_gt[k] % mod * inv_gt[n - k] % mod;
}

pair<vector<ll>, vector<ll>> giaithua(int n, const ll &mod)
{
    vector<ll> gt(n + 1), inv_gt(n + 1);
    gt[0] = 1;
    inv_gt[0] = 1;
    for (int i = 1; i <= n; ++i)
        gt[i] = (gt[i - 1] * i) % mod, inv_gt[i] = inverse(gt[i], mod);
    return {gt, inv_gt};
}

template <typename T>
ostream &operator<<(ostream &out, vector<T> v)
{
    for (auto it : v)
        out << it << " \t";
    return out;
}

template <typename T1, typename T2>
ostream &operator<<(ostream &out, pair<T1, T2> p)
{
    out << "(" << p.first << ", " << p.second << ")";
    return out;
}

template <typename T1, typename T2>
ostream &operator<<(ostream &out, unordered_map<T1, T2> m)
{
    for (auto it : m)
    {
        out << it << " ";
    }
    return out;
}

// String manipulate

vector<string> split(string s, string del = " ")
{
    vector<string> res;
    int start = 0, end = s.find(del);
    while (end != -1)
    {
        res.push_back(s.substr(start, end - start));
        start = end + del.size();
        end = s.find(del, start);
    }
    res.push_back(s.substr(start, end - start));
    return res;
}

string join(vector<string> s, string del = " ")
{
    string res;
    for (int i = 0; i < s.size(); ++i)
    {
        res += s[i];
        if (i != s.size() - 1)
            res += del;
    }

    return res;
}

string strip(const string &s)
{
    int start = 0, end = s.size();
    while (s[start] == ' ')
        start++;
    while (s[end - 1] == ' ')
        end--;
    return s.substr(start, end - start);
}

string tolower(const string &s)
{
    string t = "";
    for (auto &c : s)
        t += char(tolower(c));
    return t;
}

string toupper(const string &s)
{
    string t = "";
    for (auto &c : s)
        t += char(toupper(c));
    return t;
}

template <typename T>
struct SegmentTree
{
    int n;
    vector<T> data;
    SegmentTree(int n)
    {
        this->n = n;
        data.resize(n << 2);
    }
    void build(const vector<T> &x, int start, int end, int node)
    {
        if (start == end)
            data[node] = x[start];
        else
        {
            int mid = (start + end) >> 1;
            build(x, start, mid, node << 1);
            build(x, mid + 1, end, node << 1 | 1);
            data[node] = data[node << 1] + data[node << 1 | 1];
        }
    }
    void build_utils(const vector<T> &x)
    {
        build(x, 1, n, 1);
    }
    void update(int index, T value, int start, int end, int node)
    {
        if (start == end)
        {
            data[node] = value;
        }
        else
        {
            int mid = (start + end) >> 1;
            if (mid >= index)
                update(index, value, start, mid, node << 1);
            else
                update(index, value, mid + 1, end, node << 1 | 1);
            data[node] = data[node << 1] + data[node << 1 | 1];
        }
    }
    void update_utils(int index, T value)
    {
        update(index, value, 1, n, 1);
    }
    T query(int left, int right, int start, int end, int node)
    {
        if (left <= start && end <= right)
            return data[node];
        if (end < left || right < start)
            return 0;
        int mid = (start + end) >> 1;
        return query(left, right, start, mid, node << 1) + query(left, right, start, mid, node << 1 | 1);
    }
    T query_utils(int left, int right)
    {
        return query(left, right, 1, n, 1);
    }
};

/*---------------- End of Template---------------- */

const ll mod = 1e9 + 7;
void solve(){
    int t;
    cin >> t;
    while (t--){
        int a, b, c, m;
        cin >> a >> b >> c >> m;
        int maxi = a - 1 + b - 1 + c - 1;
        vector<int> v({a, b, c});
        sort(v.begin(), v.end());
        v[2] -= v[0];
        v[1] -= v[0];
        v[0] = 0;
        v[2] -= v[1];
        v[1] = 0;

        int mini;
        if (v[2] > v[1])
            mini = v[2] - v[1] - 1;
        else
            mini = 0;
        if (mini <= m && m <= maxi)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

int main()
{
    // freopen("input.inp", "r", stdin);
    // freopen("output.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}