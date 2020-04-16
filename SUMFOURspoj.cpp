// Store the values if sum from two lists into another vector and sort it.
// Apparently sorting and hasmap complexity is both nlogn but sorting works much faster.
// The below solution gives TLE with the use of hashmap.

#include<bits/stdc++.h>
using namespace std;

int a[4000][4];

int main()
{
	ios::sync_with_stdio(false);
	int n;
	scanf("%d",&n);
	
	int a[n][4];
	
	map<int, int, greater<int> > m1;
	map<int, int, less<int> > m2;

	for(int i=0; i<n; i++)
		for(int j=0; j<4; j++)
			scanf("%d",&a[i][j]);

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			m1[a[i][0] + a[j][1]] += 1;
			m2[a[i][2] + a[j][3]] += 1;
		}
	}

	map<int, int>::iterator it1,it2;

	it1 = m1.begin();
	it2 = m2.begin();
	int res = 0;
	while(it1!=m1.end() && it2!=m2.end()){
		int x = it1->first;
		int y = it2->first;
		if((x + y)== 0){
			res += (m1[x]*m2[y]);
			it1++;
			it2++;
		}
		if(x + y < 0) it2++;
		if(x + y > 0) it1++;
	}
	printf("%d\n",res);
	system ("pause");
}	