#include<iostream>
using namespace std;
#define len 15								//����һ������

typedef int ElemType;

typedef struct BiTNode
{
	ElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;

//���±������ҵ��ڵ�sӦ�ò����λ�ã��ڵ����ظ�ʱ����������ڵ�
void SearchTreeNode(BiTree &root, BiTree &s)	//ע�⣺ʹ�����ô���
{
	if (root == NULL)
		return;
	if (s->data > root->data)
	{
		if (root->rchild == NULL){
			root->rchild = s;
			return;	
		}
		SearchTreeNode(root->rchild, s);//sֵ���ڸ��ڵ�ֵ��δ����Ҷ�ӽڵ㣬�������Һ��ӱ���
	}

	else if (s->data < root->data)
	{
		if (root->lchild == NULL){
			root->lchild = s;
			return;
		}
		SearchTreeNode(root->lchild, s);//sֵС�ڸ��ڵ�ֵ��δ����Ҷ�ӽڵ㣬���������ӱ���
	}	
}

//����һ���ڵ㣬��Ϊ�գ�����ڵ㼴Ϊ���ڵ㣬�����Һ��ʵ�λ�ò���
void InsertNode(BiTree &tree, BiTree &s)	//ע�⣺ʹ�����ô���
{
	if (tree == NULL)
		tree = s;
	else
		SearchTreeNode(tree,s);
}

//����������������ÿ������һ����㣬�嵽���еĶ�������ȥ
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

//�����в���һ���ڵ�
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
		cout << "�ڵ��Ѿ�����" << endl;
	return pRoot;				//ÿһ���ݹ���ö�Ҫ���أ���ά��ԭ���ṹ�Ĳ���
}

//ɾ������ָ��Ԫ��key
void DeleteNode(BiTree &tree, ElemType key)		//ʹ������
{
	if (tree == NULL)
		return;
	if (key > tree->data)
		DeleteNode(tree->rchild, key);
	else if (key < tree->data)
		DeleteNode(tree->lchild,key);
	else
	{
		if (tree->lchild == NULL)		//������Ϊ�գ�ֻ��Ҫ�ؽ�������
		{
			BiTree tmp = tree;
			tree = tree->rchild;
			free(tmp);
		}
		else if (tree->rchild==NULL)		//������Ϊ�գ�ֻ��Ҫ�ؽ�������
		{
			BiTree tmp = tree;
			tree = tree->rchild;//�˴�д���ˣ�ӦΪtmp = tmp->lchild;
			free(tmp);
		}
		else
		{
			BiTree tmp1, tmp;		//tmpΪ��ɾ���ڵ㣬tmp1Ϊtmpǰ��
			tmp1 = tree;
			tmp = tree->lchild;
			while (tmp->rchild!=NULL)		//��ת������ָ��ֱ����ͷ
			{
				tmp1 = tmp;
				tmp = tmp->rchild;
			}
			tree->data = tmp->data;
			if (tmp1 != tree)
				tmp1->rchild=tmp->lchild;	//tmp�������ӵ�ǰ����������
			else
				tmp1->lchild = tmp->lchild;	//tmp�������ӵ�ǰ����������
			free(tmp);
		}
	}
}

//�������
void midOrderTraverse(BiTree tree)
{
	if (tree == NULL)
		return;
	midOrderTraverse(tree->lchild);
	cout << tree->data<<" ";
	midOrderTraverse(tree->rchild);
}

//����Ԫ��x���ڵĽڵ�
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
//�ǵݹ����Ԫ��x���ڵĽڵ�
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

//�ݹ�Ѱ�����ֵ
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
//�ǵݹ�Ѱ����Сֵ
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
	//����һ�������������������
	CreateOrderBinaryTree(tree,a);
	midOrderTraverse(tree);
	cout << endl;

	//ɾ��һ���ڵ㣬�������
	DeleteNode(tree, 47);
	midOrderTraverse(tree);
	cout << endl;

	//���һ���ڵ㣬���������
	Insert(tree, 100);
	midOrderTraverse(tree);
	cout << endl;

	//���ҽڵ�
	BiTree snode=SearchBST(tree, 23);
	if (snode == NULL)
		cout <<"���ҵĽڵ㲻����" <<endl;
	else
	{
		if (snode->lchild == NULL && snode->rchild == NULL)
			cout << "�ڵ�" <<snode->data<<"Ҷ�ӽڵ�"<< endl;
		else if (snode->lchild != NULL && snode->rchild == NULL)
			cout << "�ڵ�" << snode->data<<"����ڵ���"<<snode->lchild->data << endl;
		else if (snode->lchild == NULL && snode->rchild != NULL)
			cout << "�ڵ�" << snode->data << "����ڵ���" << snode->rchild->data << endl;
		else
			cout << "�ڵ�" << snode->data << "����ڵ���" << snode->lchild->data 
			<<" ,�ҽڵ���"<<snode->rchild->data<< endl;
	}

	snode=BST_search(tree, 23);
	if (snode != NULL)
		cout << snode->data << endl;
	else
		cout << "���ҽڵ㲻����" << endl;

	snode = findmax(tree);
	if (snode != NULL)
		cout <<"���ֵΪ" <<snode->data << endl;
	else
		cout << "��Ϊ��" << endl;

	snode = findmin(tree);
	if (snode != NULL)
		cout << "��СֵΪ" << snode->data << endl;
	else
		cout << "��Ϊ��" << endl;
	return 0;
}

