#include <bits/stdc++.h>
 
#define INF 2147483647
#define LINF 9223372036854775807
#define NINF -2147483648
#define M 1000000007
#define M1 998244353
#define A 26
#define K 31
#define P 2137
 
using namespace std;
using ll=long long;
using pi=pair<int,int>;
using pl=pair<ll,ll>;
using vi=vector<int>;
using vl=vector<ll>;
using gr=vector<vector<int> >;
using grl=vector<vector<ll> >;
using st=stack<int>;
using stl=stack<ll>;
using qu=queue<int>;
using qul=queue<ll>;
using pq=priority_queue<int>;
using pql=priority_queue<ll>;
using piq=priority_queue<pair<int, int> >;
using piql=priority_queue<pair<ll, ll> >;
using ma=map<int, int>;
using ms=map<string, int>;
using mal=map<ll, ll>;
using mp=map<pair<int, int>, int>;
using mpl=map<pair<ll, ll>, int>;
 
#define fp(x, a, b) for (int (x) = (a); (x) < (b); (x)++)
#define f(x, n) for (int (x) = 0; (x) < (n); (x)++)
#define fnp(x, a, b) for (int (x) = (b) - 1; (x) >= (a); (x)--)
#define fn(x, n) for (int (x) = (n - 1); (x) >= 0; (x)--)
#define sgn(x) (x) > 0 ? 1 : (x) == 0 ? 0 : -1
#define ab(a, b) (a) - (b) < 0 ? (b) - (a) : (a) - (b)
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) (a) * (b) / gcd((a), (b))
#define x first
#define y second
#define mp make_pair 
#define pb push_back
#define pu push
#define to top
#define fr front
#define s(x) x.size()
#define all(x) x.begin(), x.end()
#define ans(x) cout<<(x)<<"\n";
#define yes printf("YES\n");
#define no printf("NO\n");
#define debarr(x, n) f(i, (n)){cout<<(x)[i]<<" ";}cout<<"\n";
#define debmat(x, n, m) f(i, (n)){f(j, (m)){cout<<(x)[i][j]<<" ";}cout<<"\n";}
#define debgr(x, n) f(i, (n)){f(j, s((x)[i])){cout<<(x)[i][j]<<" ";}cout<<"\n";}
#define fl cout.flush();

void norm(ll& _a0, ll& _b0)
{
	ll _g0 = gcd(_a0, _b0);
	_a0 /= _g0;
	_b0 /= _g0;
}

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

class mint
{
	public:
	ll _x;
	ll _m;
	ll mintPow(ll _a0, ll _b0)
	{
		if(_b0 == 0)
			return (ll)1;
		else if(_b0 % 2 == 0)
		{
			ll _buff = (mintPow(_a0, _b0 / 2) % _m);
			return (_buff * _buff) % _m;
		}
		else
			return (_a0 * mintPow(_a0, _b0 - 1)) % _m;
	}
	ll mintInv(ll _a0)
	{
		return mintPow(_a0, _m - 2);
	}
	ll pow(ll _b0){return mintPow(_x, _b0);}
	ll inv(){return mintInv(_x);}
	
	mint(){_x = 0;_m = M;}
	mint(ll _m0){_x = 0;_m = _m0;}
	mint(ll _x0, ll _m0){_x = _x0 % _m0;_m = _m0;}
	
	friend ostream& operator<<(ostream& _o, const mint& _x0);
	
	mint operator=(const mint& _y0){_x = _y0._x;return *this;}
	mint operator^=(const mint& _b0){_x = mintPow(_x, _b0._x);return *this;}
	mint operator+(const mint& _y0){mint _z0 = mint((_x + _y0._x) % _m, _m);return _z0;}
	mint operator+=(const mint& _y0){_x = (_x + _y0._x) % _m;return *this;}
	mint operator-(const mint& _y0){mint _z0 = mint((_x - _y0._x + _m) % _m, _m);return _z0;}
	mint operator-=(const mint& _y0){_x = (_x - _y0._x + _m) % _m;return *this;}
	mint operator*(const mint& _y0){mint _z0 = mint((_x * _y0._x) % _m, _m);return _z0;}
	mint operator*=(const mint& _y0){_x = (_x * _y0._x) % _m;return *this;}
	mint operator/(const mint& _y0){mint _z0 = mint((_x * mintInv(_y0._x)) % _m, _m);return _z0;}
	mint operator/=(const mint& _y0){_x = (_x * mintInv(_y0._x)) % _m;return *this;}
	mint operator%(const mint& _y0){mint _z0 = mint((_x % _y0._x) % _m, _m);return _z0;}
	mint operator%=(const mint& _y0){_x = (_x % _y0._x) % _m;return *this;}
	bool operator==(const mint& _y0){return _x == _y0._x;}
	bool operator!=(const mint& _y0){return _x != _y0._x;}
	bool operator>=(const mint& _y0){return _x >= _y0._x;}
	bool operator<=(const mint& _y0){return _x <= _y0._x;}
	bool operator>(const mint& _y0){return _x > _y0._x;}
	bool operator<(const mint& _y0){return _x < _y0._x;}
	
	mint operator=(const ll& _y0){_x = _y0;return *this;}
	mint operator^=(const ll& _b0){_x = mintPow(_x, _b0);return *this;}
	mint operator+(const ll& _y0){mint _z0 = mint((_x + _y0) % _m, _m);return _z0;}
	mint operator+=(const ll& _y0){_x = (_x + _y0) % _m;return *this;}
	mint operator-(const ll& _y0){mint _z0 = mint((_x - _y0 + _m) % _m, _m);return _z0;}
	mint operator-=(const ll& _y0){_x = (_x - _y0 + _m) % _m;return *this;}
	mint operator*(const ll& _y0){mint _z0 = mint((_x * _y0) % _m, _m);return _z0;}
	mint operator*=(const ll& _y0){_x = (_x * _y0) % _m;return *this;}
	mint operator/(const ll& _y0){mint _z0 = mint((_x * mintInv(_y0)) % _m, _m);return _z0;}
	mint operator/=(const ll& _y0){_x = (_x * mintInv(_y0)) % _m;return *this;}
	mint operator%(const ll& _y0){mint _z0 = mint((_x % _y0) % _m, _m);return _z0;}
	mint operator%=(const ll& _y0){_x = (_x % _y0) % _m;return *this;}
	bool operator==(const ll& _y0){return _x == _y0;}
	bool operator!=(const ll& _y0){return _x != _y0;}
	bool operator>=(const ll& _y0){return _x >= _y0;}
	bool operator<=(const ll& _y0){return _x <= _y0;}
	bool operator>(const ll& _y0){return _x > _y0;}
	bool operator<(const ll& _y0){return _x < _y0;}
};

ostream& operator<<(ostream& _o, const mint& _x0)
{
	_o << _x0._x;
	return _o;
}
 
void input();
void compute();
 
int main()
{
	int T = 1;
	scanf("%d", &T);
	while(T--)
	{
		input();
		compute();
	}
	return 0;
}

ll n;
ll m;
ll k;
 
void input()
{
	cin >> n >> m >> k;
}
void compute()
{
	if((n % 2 == 0) && (m % 2 == 0) && (k % 2 == 0))
	{
		yes
	}
	else if((n % 2 == 1) && (m % 2 == 0) && (k % 2 == 1) && (k >= m / 2))
	{
		yes
	}
	else if((n % 2 == 0) && (m % 2 == 1) && (k % 2 == 0) && (k >= n / 2))
	{
		yes
	}
	else
	{
		no
	}
}
