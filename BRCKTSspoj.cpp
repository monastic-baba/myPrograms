#include<bits/stdc++.h>
using namespace std;

#define Maxm 1000005
#define endl '\n'


///////////////////////////segtree///////////////////////// 

class Node
{
	public:

		int opening=0;
		int closing=0;
		Node(int m, int n)
		{
			opening = m;
			closing = n;
		};
		~Node();	
};

Node* tree[4*Maxm+1];



Node* combine(Node* l, Node* r){

	int balanced = min(l->opening, r->closing);
	int o = l->opening + r->opening - balanced;
	int c = l->closing + r->closing - balanced;

	return new Node(o, c);

}

 
void buildTree(int a[], int s, int e, int idx){
    
    if(s==e){

    	tree[idx] = ((a[s]==1)?new Node(1,0):new Node(0,1));
        return;
    }
    
    int mid = (s+e)/2;
    buildTree(a, s, mid, 2*idx);
    buildTree(a, mid+1, e, 2*idx+1);
 
    Node* left = tree[2*idx];
    Node* right = tree[2*idx+1];
 
    tree[idx] = combine(left, right);
    return;
}
 
 
Node* query(int s,int e, int qs,int qe, int idx){
    //no overlap
    if(e<qs || s>qe){
        return new Node(0, 0);
    }
 
    //complete overlap
    if(s>=qs && e<=qe){
        return tree[idx];
    }
 
    //partial overlap call on both sides
    int mid = (s+e)/2; 
    Node* left = query(s, mid, qs, qe, 2*idx);
    Node* right = query(mid+1, e, qs, qe, 2*idx+1);
    return combine(left, right);
 
}
 
 
void update(int s, int e, int i, int idx){
    if(i<s||i>e){
        return;
    }
 
    if(s==e){
        swap(tree[idx]->opening, tree[idx]->closing);
        return;
    }

    int mid=(s+e)/2;
    update(s, mid, i, 2*idx);
    update(mid+1, e, i, 2*idx+1);
    tree[idx] = combine(tree[2*idx], tree[2*idx+1]);
    
    return;
}
 
/////////////////////////////////////////////////////////////////

int main()
{
	for(int k=1; k<=10; k++){
		int n,q;
		cin>>n;
		int a[n];
		string s;
		cin>>s>>q;
		for(int i=0; i< (int)s.length(); i++) a[i] = ((s[i]=='(')?1:-1);
		buildTree(a, 0, n-1, 1);
		cout<<"Test "<<k<<":"<<endl;
		Node* queryRes;
		while(q--){
			int x;
			cin>>x;
			if(x==0){
				queryRes = query(0, n-1, 0, n-1, 1);
				cout<<((queryRes->opening==0 && queryRes->closing==0)?"YES":"NO")<<endl;
			}
			else update(0, n-1, x-1, 1);
		}
		cout<<endl;
	}
}