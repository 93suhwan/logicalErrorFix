#include<bits/stdc++.h>
#define ll long long
#define sc second
#define mx 800010
#define inf 2e9
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin>>tc;

	while(tc--)
	{
		int n;
		cin>>n;

		int arr[n+5];
		int pos[n+5]= {};

		for( int i=0;i<n;i++ )
			cin>>arr[i], pos[arr[i]]= i;

		string s;
		cin>>s;

		set<int>st;
		std::vector<int> v;

		for( int i=0;i<s.size();i++ )
			if( s[i]=='1' )
				st.insert(arr[i]);
			else
				v.push_back(arr[i]);

		sort( v.begin(), v.end(), greater<int>() );

		for( auto x: v )
		{
			auto p= st.lower_bound(x);

			if(p==st.begin())
				continue;

			p--;

			int y= *p;

			swap( arr[pos[y]], arr[pos[x]] );
			st.erase(y);
		}

		for( int i=0;i<n;i++ )
			cout<<arr[i]<<" ";

		cout<<"\n";
	}
}