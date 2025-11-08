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
node* builttree(node* &root){
	int data;
	cout<<"enter data"<<endl;
	cin>>data;
	if(data==-1){
		return NULL;
	}
	root=new node(data);
	cout<<"enter left child of "<<data<<endl;
	root->left=builttree(root->left);
	cout<<"enter right child of "<<data<<endl;
	root->right=builttree(root->right);
	return root;
}
void inorder(node* root){
	if(root==NULL){
		return ;
	}
	inorder(root->left);
	cout<<root->data;
	inorder(root->right);
	cout<<endl;
}
void preorder(node* root){
	if(root==NULL){
		return ;
	}
		cout<<root->data;
	preorder(root->left);
	preorder(root->right);
	cout<<endl;
}
void postorder(node* root){
	if(root==NULL){
		return ;
	}
	postorder(root->left);
	postorder(root->right);
		cout<<root->data;
		cout<<endl;
}
int main(){
	node* root=builttree(root);
	cout<<"inorder traversal is:"<<endl;
	inorder(root);
	cout<<"preorder traversal"<<endl;
	preorder(root);
	cout<<"postorder traversal"<<endl;
	postorder(root);
	return 0;
}
