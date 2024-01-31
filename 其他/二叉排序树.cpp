#include<iostream>
using namespace std;
#define len 15								//定义一个长度

typedef int ElemType;

typedef struct BiTNode
{
	ElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;

//向下遍历，找到节点s应该插入的位置，节点有重复时，忽略这个节点
void SearchTreeNode(BiTree &root, BiTree &s)	//注意：使用引用传递
{
	if (root == NULL)
		return;
	if (s->data > root->data)
	{
		if (root->rchild == NULL){
			root->rchild = s;
			return;	
		}
		SearchTreeNode(root->rchild, s);//s值大于根节点值，未到达叶子节点，继续向右孩子遍历
	}

	else if (s->data < root->data)
	{
		if (root->lchild == NULL){
			root->lchild = s;
			return;
		}
		SearchTreeNode(root->lchild, s);//s值小于根节点值，未到达叶子节点，继续向左孩子遍历
	}	
}

//插入一个节点，树为空，插入节点即为根节点，否则找合适的位置插入
void InsertNode(BiTree &tree, BiTree &s)	//注意：使用引用传递
{
	if (tree == NULL)
		tree = s;
	else
		SearchTreeNode(tree,s);
}

//二叉排序树创建，每次增加一个结点，插到现有的二叉树上去
void CreateOrderBinaryTree(BiTree &tree,int *a)
{
	for (int i = 0; i < len; i++)
	{
		BiTree s = (BiTree)malloc(sizeof(BiTNode));
		s->data = a[i];
		s->lchild = NULL;
		s->rchild = NULL;
		InsertNode(tree,s);
	}
}

//在树中插入一个节点
BiTree Insert(BiTree pRoot,ElemType key)
{
	if (pRoot == NULL)
	{
		pRoot = (BiTree)malloc(sizeof(BiTNode));
		pRoot->data = key;
		pRoot->lchild = NULL;
		pRoot->rchild = NULL;
	}
	else if (key < pRoot->data)
		pRoot->lchild = Insert(pRoot->lchild, key);
	else if (key>pRoot->data)
		pRoot->rchild = Insert(pRoot->rchild, key);
	else
		cout << "节点已经存在" << endl;
	return pRoot;				//每一步递归调用都要返回，以维持原树结构的不变
}

//删除树中指定元素key
void DeleteNode(BiTree &tree, ElemType key)		//使用引用
{
	if (tree == NULL)
		return;
	if (key > tree->data)
		DeleteNode(tree->rchild, key);
	else if (key < tree->data)
		DeleteNode(tree->lchild,key);
	else
	{
		if (tree->lchild == NULL)		//左子树为空，只需要重接右子树
		{
			BiTree tmp = tree;
			tree = tree->rchild;
			free(tmp);
		}
		else if (tree->rchild==NULL)		//右子树为空，只需要重接左子树
		{
			BiTree tmp = tree;
			tree = tree->rchild;//此处写错了，应为tmp = tmp->lchild;
			free(tmp);
		}
		else
		{
			BiTree tmp1, tmp;		//tmp为被删除节点，tmp1为tmp前驱
			tmp1 = tree;
			tmp = tree->lchild;
			while (tmp->rchild!=NULL)		//左转，向右指，直到尽头
			{
				tmp1 = tmp;
				tmp = tmp->rchild;
			}
			tree->data = tmp->data;
			if (tmp1 != tree)
				tmp1->rchild=tmp->lchild;	//tmp左子树接到前驱右子树上
			else
				tmp1->lchild = tmp->lchild;	//tmp左子树接到前驱左子树上
			free(tmp);
		}
	}
}

//中序遍历
void midOrderTraverse(BiTree tree)
{
	if (tree == NULL)
		return;
	midOrderTraverse(tree->lchild);
	cout << tree->data<<" ";
	midOrderTraverse(tree->rchild);
}

//查找元素x所在的节点
BiTree SearchBST(BiTree &tree, ElemType key)
{
	if (tree == NULL)
		return NULL;
	if (key > tree->data)
		SearchBST(tree->rchild,key);
	else if (key < tree->data)
		SearchBST(tree->lchild, key);
	else
		return tree;
}
//非递归查找元素x所在的节点
BiTree BST_search(BiTree root, ElemType x)
{
	BiTree p = root;
	while (p!= NULL)
	{
		if (x < p->data)
			p = p->lchild;
		else if (x > p->data)
			p = p->rchild;
		else
			return p;
	}
	return NULL;
}

//递归寻找最大值
BiTree findmax(BiTree pRoot)
{
	BiTree p = pRoot;
	if (p == NULL)
		return NULL;
	else
	{
		if (p->rchild != NULL)
			findmax(p->rchild);
		else
			return p;
	}
}
//非递归寻找最小值
BiTree findmin(BiTree pRoot)
{
	BiTree p = pRoot;
	if (p == NULL)
		return NULL;
	while (p->lchild != NULL)
		p=p->lchild;
	return p;
}

int main()
{
	int a[len] = { 62, 88, 58, 47, 35, 73, 51, 99, 37, 93, 23, 27, 45, 21, 12};
	
	BiTree tree = NULL;
	//创建一个二叉树，并中序遍历
	CreateOrderBinaryTree(tree,a);
	midOrderTraverse(tree);
	cout << endl;

	//删除一个节点，中序遍历
	DeleteNode(tree, 47);
	midOrderTraverse(tree);
	cout << endl;

	//添加一个节点，并中序遍历
	Insert(tree, 100);
	midOrderTraverse(tree);
	cout << endl;

	//查找节点
	BiTree snode=SearchBST(tree, 23);
	if (snode == NULL)
		cout <<"查找的节点不存在" <<endl;
	else
	{
		if (snode->lchild == NULL && snode->rchild == NULL)
			cout << "节点" <<snode->data<<"叶子节点"<< endl;
		else if (snode->lchild != NULL && snode->rchild == NULL)
			cout << "节点" << snode->data<<"的左节点是"<<snode->lchild->data << endl;
		else if (snode->lchild == NULL && snode->rchild != NULL)
			cout << "节点" << snode->data << "的左节点是" << snode->rchild->data << endl;
		else
			cout << "节点" << snode->data << "的左节点是" << snode->lchild->data 
			<<" ,右节点是"<<snode->rchild->data<< endl;
	}

	snode=BST_search(tree, 23);
	if (snode != NULL)
		cout << snode->data << endl;
	else
		cout << "查找节点不存在" << endl;

	snode = findmax(tree);
	if (snode != NULL)
		cout <<"最大值为" <<snode->data << endl;
	else
		cout << "树为空" << endl;

	snode = findmin(tree);
	if (snode != NULL)
		cout << "最小值为" << snode->data << endl;
	else
		cout << "树为空" << endl;
	return 0;
}

