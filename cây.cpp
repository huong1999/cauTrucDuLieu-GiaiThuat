#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

//khai basocau truc cua 1 nut
struct node{
	int data;				//gia tri cua nut
	node *left,*right;		//dia chi nut trai,nut phai
};
typedef node *Tree;
//khoi tao cay
void init(Tree &root){
	root = NULL;
}

//khoi tao 1 nut cho cay
Tree make_node(int x){
	Tree p = new node;
	p->data = x;
	p->left = p->right = NULL;
	return p;
}
//iem tra cay rong
bool empty_tree(Tree root)
{
   if(root == NULL)
   		return true;

   else
   		return false;
}

//chèn 1 nút vào cây có san
void insert(Tree &root,int x){
	if(root){
		if(root->data == x)
			return;
		else
			if(x<root->data)
				insert(root->left,x);
			else
				insert(root->right,x);
		
	}
	else
	{
		Tree p = make_node(x);
		root = p;
	}
}
void decode_huff(Tree root, string s) {
    int i=0;
    node *p = root;
    while(s[i]!='\0'){
        if(s[i]=='0')
            p=p->left;
        else if(s[i]=='1')
            p=p->right;
        if(p->data!='\0'){
            cout<<p->data;
            p = root;
        }
        i++;
    }
}
void create(Tree &root,string s){
//	int n;
//	cin>>n;
//	int x;
	
	for(int i=0;i<s.size();i++){
		cin>>x;
		insert(root,x);
	}
}
Tree search_node(Tree &root,int x){
	Tree p = root;		//khai bao 1 nút p tro den goc
	while(p!=NULL){
		if(p->data==x)		//khi tìm that node co gia tri bang x thì tra ve node dang xét
			return p;
		else if(x>p->data)
			p=p->right;
		else
			p=p->left;
	}
	return NULL;		//tra ve null neu ko tìm thây nút nào có gtri bang x
}

int main(){
	/* tree: 50
		    /  \
		  30    70
		  /\	 /\
		20  40  60 90
	
	*/
	
	Tree root;
	init(root);
	create(root);
	int x;
	cin>>x;
	search_node(root,x);
}





