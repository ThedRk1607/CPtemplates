#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,n) for(int i = a; i < int(n);i++ )
#define FORR(x,arr) for(auto& x:arr)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define ll              long long 
#define db 				double
#define pb              push_back
#define all(v)             v.begin(),v.end()
#define F               first
#define S               second
#define INF             1000000007
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll>
#define pii             pair<int,int>
#define nl  			"\n"
#define PI   			3.1415926536
#define eps 0.00000001
#define mp 				make_pair
#define lb lower_bound
#define ub upper_bound
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0x3f,sizeof(a))

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
 
template <typename A, typename B> A amax (A &a, B b){ if (b > a) a = b ; return a; }
template <typename A, typename B> A amin (A &a, B b){ if (b < a) a = b ; return a; }

struct ListNode {
  int val;
  ListNode*next;
     ListNode(int val){
     	this->val=val;
     	next=NULL;
     }

};

ListNode*reverseList(ListNode*head){
	ListNode*newHead=NULL;
	while(head!=NULL){
		ListNode*next=(head)->next;
		(head)->next=newHead;
		newHead=head;
		head=next;
	}

	return newHead;
}
//reverse using recursion
ListNode* reverseList1(ListNode* head) {
    if(!head || !(head->next))  return head;
    auto res = reverseList1(head->next);
    head->next->next = head;
    head->next = NULL;
    return res;
}


 void print(ListNode*head)
    {
       ListNode*temp=head;
        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
    }
 
    void push(int data,ListNode**head)
    {
       ListNode* temp = new ListNode(data);
      
        temp->next = *head;
        *head = temp;
    }

void solve(){
  ListNode*head=new ListNode(12);


    push(50,&head);
    push(70,&head);
    push(80,&head);
    push(90,&head);
     auto head1=reverseList1(head);
   print(head1);
  

}

	


 
 
 
	
 
int32_t main()
{
 
	#ifndef ONLINE_JUDGE
 
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	 #endif
   
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
 
   int T=1;//cin >> T;
   while(T--)solve();
  
	#ifdef DEBUG
		cerr << "Runtine is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
    
    return 0;
    
    }
