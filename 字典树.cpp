#include <iostream>
#include <string.h>
using namespace std;

const int MAX=26,base='a';
char s1[12],ss[12];

struct Trie{
	int num;
	bool flag;
	Trie *son[MAX];
	Trie()
    {
        num=1;flag=false;
        memset(son,NULL,sizeof(son));
    }
}; 

Trie *NewTrie()
{
	Trie *temp = new Trie;
	return temp;
}

void Insert(Trie *root,char *s)
{
	Trie *temp = root;
	while(*s){
		if(temp->son[*s-base]==NULL)
			temp->son[*s-base]=NewTrie();
		else
			temp->son[*s-base]->num++;
		temp=temp->son[*s-base];
		s++;
	}
	temp->flag=true;
}

int Search(Trie *root,char *s)
{
	Trie *temp = root;
	while(*s){
		if(temp->son[*s-base]==NULL) return 0;
		temp = temp->son[*s-base];
		s++;
	}
	return temp->num;
}

int main()
{
	##基于hdu 1251 统计题
	Trie *root = NewTrie();
	root->num=0;
	while(gets(s1)&&strcmp(s1,"")!=0)  
    {
        if(strcmp(s1," ")==0)
        	break;
        Insert(root,s1);
    }
    while(cin>>ss)
    {
        int  ans=Search(root,ss);
        cout<<ans<<endl;
    }
	return 0;
}
