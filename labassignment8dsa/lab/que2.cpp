#include<iostream>
using namespace std;
class node{
	public:
	int data;
	node* left;
	node* right;
		node(int d){
			data=d;
			left=NULL;
			right=NULL;
		}
};
bool search(node* root,int key){
	if(root==NULL){
		return false;
	}
else if(key==root->data){
		return true;
	}
	else if(key<root->data){
		return search(root->left,key);
	}
	else if(key>root->data){
		return search(root->right,key);
	}
}
int min(node* root){
	if(root==NULL){
		return -1;
	}
	while(root->left){
		root=root->left;
	}
	return root->data;
}
int max(node* root){
	if(root==NULL){
		return -1;
	}
	while(root->right){
		root=root->right;
	}
	return root->data;
}
node* insucc(node* root,int key){
	if(root==NULL){
		return NULL;
	}
	node* succ=NULL;
	int succs;
	while(root){
		if(key<root->data){
			succ=root;
			root=root->left;
		}
		else{
			root=root->right;
		}
	}
	return succ;
}
node* preoder(node* root,int key){
	node* preod=NULL;
	while(root){
		if(key>root->data){
			preod=root;
			root=root->right;
		}
		else{
			root=root->left;
		}
	}
	return preod;
}
node* insert(node* root,int data){
	if(root==NULL){
		return new node(data);
	}
	if(data<root->data){
	root->left=insert(root->left,data);
	}
	else{
		root->right=insert(root->right,data);
	}
	return root;
}
int main(){
	node* root=NULL;
	int n;
	cout<<"enter number of noides"<<endl;
	cin>>n;
	cout<<"enter values"<<endl;
	for(int i=0;i<n;i++){
		int val;
		cout<<"enter value"<<endl;
		cin>>val;
		root=insert(root,val);
	}
	int key;
	cout<<"enter key to search"<<endl;
	cin>>key;
	bool ans=search(root,key);
	if(ans){
		cout<<"found"<<endl;
	}
	else{
		cout<<"not found"<<endl;
	}
	cout<<"max element is "<<max(root)<<endl;
	cout<<"min element is"<<min(root)<<endl;
	int value;
	cout<<"enter value to find succ"<<endl;
	cin>>value;
node* succ=	insucc(root,value);
cout<<"succ is"<<succ->data;
cout<<endl;
int a;
	cout<<"enter value to find prec"<<endl;
	cin>>a;
	node* pred=preoder(root,a);
	cout<<"pred is"<<pred->data<<endl;
	return 0;
}


