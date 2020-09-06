#include <iostream>
#define null NULL
using namespace std;

struct node{
	int exp;
	int coef;
	struct node *Next;
};

void input(node *p);
node *sum(node *p,node *u);
void print(node *p);

int main()
{
	struct node *a=new node;
	input(a);
	struct node *b=new node;
	input(b);
	print(a);cout<<endl;
	print(b);cout<<endl;
	print(sum(a,b));
	return 0;
}

void input(node *p)
{
	p->Next=NULL;
	node *u=new node;
	while(cin>>u->coef>>u->exp){
		if(u->coef==0&&u->exp==-1)break;
		p->Next=u;
		u->Next=NULL;
		p=u;
		u=new node;
	}
}

node *sum(node *p,node *u)
{
	node *a,*b,*l;
	node *h=new node;
	h->Next=NULL;
	l=h;
	a=p->Next;b=u->Next;
	while(a!=NULL&&b!=NULL){
		if(a->exp>b->exp){
			node *m=new node;
			m->exp=a->exp;
			m->coef=a->coef;
			m->Next=NULL;
			l->Next=m;
			l=m;
			a=a->Next;
		}
		else if(a->exp<b->exp){
			node *m=new node;
			m->exp=b->exp;
			m->coef=b->coef;
			m->Next=null;
			l->Next=m;
			l=m;
			b=b->Next;
		}
		else
		{
			if(a->coef+b->coef!=0)
			{
				node *m=new node;
				m->coef=a->coef+b->coef;
				m->exp=a->exp;
				m->Next=null;
				l->Next=m;
				l=m;
				b=b->Next;
				a=a->Next;
			}
			else{
				b=b->Next;
				a=a->Next;	
			}
		}
	}
		if(a==null&&b!=null){
			while(b!=null){
				node *m=new node;
				m->exp=b->exp;
				m->coef=b->coef;
				m->Next=null;
				l->Next=m;
				l=m;
				b=b->Next;
			}
		}
		else if(a!=null&&b==null){
			while(a!=null){
				node *m=new node;
				m->exp=a->exp;
				m->coef=a->coef;
				m->Next=null;
				l->Next=m;
				l=m;
				a=a->Next;
			}
		}
	return h;
}


void print(node *p)
{
	node *u;
	if(p->Next==NULL) {cout<<'0';return;} //特殊情况 全部为0时为空 特意输出0 
	for(u=p->Next;u!=null;u=u->Next){
		if(u->coef!=1&&u->coef!=-1&&u->coef!=0) cout<<u->coef;
		else if(u->coef==-1&&u->exp==0) cout<<"-1";	//最后一个为-1时候，要输出-1。 
		else if(u->coef==-1) cout<<"-";
		else if(u->exp==0&&u->coef!=0) cout<<u->coef;
		if(u->exp>1)cout<<"X^"<<u->exp;
		else if(u->exp==1)cout<<"X";
		if(u->Next!=NULL&&u->Next->coef>0) cout<<"+";	
	}
}
