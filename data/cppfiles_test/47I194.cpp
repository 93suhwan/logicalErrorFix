#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
#define pb push_back
#define sz size()
#define ff first
#define ss second
#define mod 1000000007 
#define pie 3.14159265359
const ll inf=1e15;
#define minheap priority_queue<int , vector<int> , greater<int> > 
#define maxheap priority_queue<int> 	
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) ;
#define debug(n) cout<<#n<<" "<<n<<"\n";
#define pii pair<ll,pair<ll,ll>>
#define pi pair<ll,ll>
int main()
{
	//fast;
	ll n,k,i,j;
	cin>>n>>k;
	vector<ll> v(n);
	cout<<"and 1 2"<<endl;
	
	ll and12;
	cin>>and12;
	cout<<"or 1 2"<<endl;
	ll or12;
	cin>>or12;
	cout<<"and 1 3"<<endl;
	ll and13;
	cin>>and13;
	cout<<"or 1 3"<<endl;
	ll or13;
	cin>>or13;
	cout<<"or 2 3"<<endl;
	ll or23;
	cin>>or23;
	ll and23;
	cout<<"and 2 3"<<endl;
	cin>>and23;
	// A+B=(A&B)+(A|B) ;-(
	or23=(and23+or23);
	or12=(or12+and12);
	or13=(or13+and13);
	
	ll a1=0;
	a1=(or12-or23);
	a1=(a1+or13)/2;
	
	ll a2=(and12|((or12^(a1))));
	ll a3=(and13|((or13^(a1))));
	v[0]=a1;
	v[1]=a2;
	v[2]=a3;
	for(i=4;i<=n;i++)
	{
		cout<<"and 1 "<<i<<endl;
		ll and1i;
		cin>>and1i;
		cout<<"or 1 "<<i<<endl;
		ll or1i;
		cin>>or1i;
		v[i-1]=((and1i|((or1i^(a1)))));
	}
	
	sort(v.begin(),v.end());
	cout<<"finish ";
	cout<<v[k-1]<<"\n";
}