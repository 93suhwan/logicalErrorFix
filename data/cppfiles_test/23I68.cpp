//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
//~ #pragma GCC target ("avx2")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define shandom_ruffle random_shuffle

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int nax=107;
const ll mod=998244353;

int n, k;

struct bn
{
	ll a=0;
	ll b=0;
	const int d=50;
	bn()
	{
		
	}
	bn(ll aa, ll bb)
	{
		a=aa;
		b=bb;
	}
	void flip(int v)
	{
		if (v<=d)
			a^=(1LL<<v);
		else
			b^=(1LL<<(v-d));
	}
	int daj(int v)
	{
		if (v<=d)
			return (a>>v)&1;
		else
			return (b>>(v-d))&1;
	}
	void ustal(int v, int w)
	{
		if (w!=daj(v))
			flip(v);
	}
};

bool operator <(bn a, bn b)
{
	if (a.a!=b.a)
		return a.a<b.a;
	return a.b<b.b;
}

bool operator ==(bn a, bn b)
{
	return (a.a==b.a && a.b==b.b);
}

bool operator !=(bn a, bn b)
{
	return !(a==b);
}

bn operator |(bn a, bn b)
{
	return bn(a.a|b.a, a.b|b.b);
}

bn operator &(bn a, bn b)
{
	return bn(a.a&b.a, a.b&b.b);
}

bn operator ^(bn a, bn b)
{
	return bn(a.a^b.a, a.b^b.b);
}

bn nal[nax];

ll sil[nax];

ll wyn=1;

set<bn> ist;

bn zero;

int main()
{
	scanf("%d%d", &n, &k);
	for (int i=1; i<=k; i++)
	{
		int a, b;
		scanf("%d", &a);
		//~ a=2;
		while(a--)
		{
			scanf("%d", &b);
			//~ b=i+a;
			nal[i].flip(b);
		}
	}
	sil[0]=1;
	for (int i=1; i<=n; i++)
		sil[i]=(sil[i-1]*i)%mod;
	for (int i=1; i<=k; i++)
		ist.insert(nal[i]);
	ist.insert(nal[0]);
	for (int i=1; i<=n; i++)
	{
		nal[0].flip(i);
		ist.insert(nal[0]);
		nal[0].flip(i);
	}
	for (int i=1; i<=n; i++)
		nal[0].flip(i);
	ist.insert(nal[0]);
	vector<bn> kolejka;
	for (bn i : ist)
		kolejka.push_back(i);
	while(!kolejka.empty())
	{
		if ((int)ist.size()>n*n/2+3*n+7)
		{
			printf("0\n");
			return 0;
		}
		bn j=kolejka.back();
		kolejka.pop_back();
		for (int i=1; i<=k; i++)
		{
			if ((j&nal[i])!=zero)
			{
				for (bn l : {j&nal[i], j|nal[i]})
				{
					if (!ist.count(l))
					{
						ist.insert(l);
						kolejka.push_back(l);
					}
				}
			}
		}
	}
	for (bn i : ist)
	{
		for (bn j : ist)
		{
			if (i==j)
				break;
			bn lacz=(i&j);
			if (lacz==zero || lacz==j || lacz==i)
				continue;
			bn wez=(i^j);
			if (ist.count(wez))
			{
				//~ wypisz(i);
				//~ wypisz(j);
				//~ wypisz(i^j);
				printf("0\n");
				return 0;
			}
		}
	}
	//~ debug() << imie(ist.size());
	//~ for (bn i : ist)
		//~ wypisz(i);
	vector<bn> oni;
	for (bn i : ist)
		oni.push_back(i);
	int r=ist.size();
	vector<unsigned long long> hasz(r);
	map<unsigned long long,int> iluma;
	map<unsigned long long,vi> ktoma;
	for (int i=r-1; i>=0; i--)
	{
		for (int j=i+1; j<r; j++)
			if ((oni[j]&oni[i])==oni[i])
				hasz[i]+=hasz[j];
		iluma[hasz[i]]++;
		ktoma[hasz[i]].push_back(i);
		hasz[i]+=rand();
		hasz[i]+=rand()*(10000LL);
		hasz[i]+=rand()*(10000000LL);
	}
	for (auto i : iluma)
	{
		if (i.second>1)
		{
			if (i.second>2)
			{
				for (int a : ktoma[i.first])
				{
					for (int b : ktoma[i.first])
					{
						if (a==b)
							break;
						if ((oni[a]&oni[b])!=zero)
						{
							printf("0\n");
							return 0;
						}
					}
				}
			}
			for (int j=1; j<=i.second; j++)
				wyn=(wyn*j)%mod;
		}
	}
	printf("%lld\n", wyn);
	return 0;
}
