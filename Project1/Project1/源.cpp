#include<iostream>
#define MaxSize 50
using namespace std;
typedef struct LNode {
	int data;
	struct LNode* next;
}LinkNode;//单链表

typedef struct DNode {
	int data;
	struct DNode* next;
	struct DNode* prior;
}DLinkNode;//双链表

typedef struct { //栈
	int data[MaxSize];
	int top;
}SqStack;
typedef struct { //共享栈
	int data[MaxSize];
	int top1，top2;
}DStack;
typedef struct linknode { //共享栈
	int data;
	struct linknode* next;
}LinkStNode;
typedef struct {
	int data[MaxSize];
	int front, rear;
}SqQueue;//队列
void CreatList(LinkNode* L, int a[], int n) {
	LinkNode* S;
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
	for (int i = 0; i < n; i++) {
		S = (LinkNode*)malloc(sizeof(LinkNode));
		S->data = a[i];
		S->next = L->next;
		L->next = S;
	}
}//初始化链表
void CreaListR(LinkNode* L, int a[], int n) {
	LinkNode* s, * r;
	L = (LinkNode*)malloc(sizeof(LinkNode));
	r = L;
	for (int i = 0; i < n; i++) {
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];
		r->next;
		r = s;
	}
	r->next = NULL;
}//尾插法
void InitList(LinkNode* L) {
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
}//初始化链表
void DestoryLink(LinkNode* L) {
	LinkNode* pre = L, * p = L->next;
	while (L != NULL) {
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);
}//销毁链表
bool ListEmpty(LinkNode* L) {
	if (L->next == NULL) {
		return 1;
	}
	else
		return 0;
}//判断链表是否为空
int ListLength(LinkNode* L) {
	int n = 0;
	LinkNode* S = L;
	while (S->next != NULL) {
		n++;
		S = S->next;
	}
	return n;
}//求链表的长度
void DisList(LinkNode* L) {
	LinkNode* M = L->next;
	while (M->next != NULL) {
		cout << M->data << endl;
		M = M->next;
	}
}//输出链表
bool GetElem(LinkNode* L, int i, int& e) {//按序号求链表中的元素
	int j = 0;
	LinkNode* p = L;
	if (i <= 0)					//判断序号是否错误
		return false;
	while (j < i && p != NULL) {
		j++;
		p = p->next;	//按顺序寻找所求元素的位置
	}
	if (p == NULL) {
		return false;
	}
	else {
		e = p->data;
		return true;
	}
}
int locateELem(LinkNode* L, int e) {//按元素值查找
	int i = 1;
	LinkNode* p = L->next;
	while (p != NULL && e != p->data) {//判断条件
		p = p->next;
		i++;
	}
	if (p == NULL) {
		return 0;
	}
	else
		return i;

}
bool ListInsert(LinkNode*& L, int i, int e) {
	int j = 0;
	LinkNode* p = L, * s;
	if (i <= 0) {
		return false;
	}
	while (j < i - 1 && p != NULL) {//找到插入位置的前一个结点处
		p = p->next;
		j++;
	}
	if (p == NULL) {
		return false;
	}
	else {
		s = (LinkNode*)malloc(sizeof(LinkNode));//找到位置后将节点给s
		s->data = e;
		s->next = p->next;
		p->next = s;
		return true;

	}

}//在某节点处插入元素
bool ListDelete(LinkNode*& L, int i, int e) {
	int j = 0;
	LinkNode* p = L, * s;
	if (i <= 0) {
		return false;
	}
	while (j < i - 1 && p != NULL) {
		p = p->next;
		j++;
	}
	if (p == NULL) {
		return false;
	}
	else {
		s = p->next;
		if (s == NULL) {
			return false;
		}
		e = s->data;
		p->next = s->next;
		free(s);
		return true;
	}
}//删除某节点的元素


//双链表的头插法和尾插法
void CreatListF(DLinkNode*& L, int a[], int n) {
	DLinkNode* s;
	L = (DLinkNode*)malloc(sizeof(DLinkNode));
	L->prior = L->next = NULL;//前后指针置为NULL
	for (int i = 0; i < n; i++) {
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = a[i];
		s->next = L->next;
		if (L->next != NULL) {
			L->next->prior = s;
		}
		L->next = s;
		s->prior = L;
	}
}
void CreatListR(DLinkNode*& L, int a[], int n) {
	DLinkNode* s, * r;
	L = (DLinkNode*)malloc(sizeof(DLinkNode));
	r = L;
	for (int i = 0; i < n; i++) {
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = a[i];
		r->next = s;
		s->prior = r;
		r = s;
	}
	r->next = NULL;
}
bool DListInsert(DLinkNode*& L, int i, int e) {
	int j = 0;
	DLinkNode* p = L, * s;
	if (i <= 0)
		return false;
	while (j < i - 1 && &p != NULL) {
		j++;
		p = p->next;
	}
	if (p == NULL) {
		return false;
	}
	else {
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = e;
		s->next = p->next;
		if (p->next != NULL) {
			p->next->prior = s;
		}
		s->prior = p;
		p->next = s;
		return true;
	}
}
bool DListDelete(DLinkNode*& L, int i, int e) {
	int j = 0;
	DLinkNode* p = L, * s;
	if (i <= 0)
		return false;
	while (j < i - 1 && &p != NULL) {
		j++;
		p = p->next;
	}
	if (p == NULL) {
		return false;
	}
	else {
		s = p->next;
		if (s == NULL) {
			return false;
		}
		e = s->data;
		p->next = s->next;
		if (s->next != NULL) {
			s->next->prior = p;
		}
		free(p);
	}
}

//初始化栈
void InitStack(SqStack*& s) {
	s = (SqStack*)malloc(sizeof(SqStack));
	s->top = -1;								//栈空的条件
}
void DestoryStack(SqStack*& s) {
	free(s);
}
bool StackDestory(SqStack*& s) {
	if (s->top == -1) {
		return true;
	}
	return false;
}
bool Push(SqStack*& s, int e) {//入栈
	if (s->top == MaxSize - 1) {//栈满的条件
		return false;
	}
	s->top++;
	s->data[s->top] = e;
	return true;
}
bool Pop(SqStack*& s, int e) {//出栈
	if (s->top == -1) {
		return false;
	}
	e = s->data[s->top];
	s->top--;
	return true;
}
bool GetTop(SqStack* s, int& e) { //取栈顶元素
	if (s->top == -1) {
		return false;
	}
	e = s->data[s->top];
	return true;
}

//初始化链栈
void LinkStack(LinkStNode*& s) {
	s = (LinkStNode*)malloc(sizeof(LinkStNode));
	s->next = NULL;
}
//销毁栈
void DestoryLinkStack(LinkStNode*& s) {
	LinkStNode* pre = s, * p = s->next;
	while (p != NULL) {
		free(p);
		pre = p;
		p = pre->next;
	}
	free(pre);
}
bool LinkStackEmpty(LinkStNode* s) {
	return (s->next == NULL);
}
bool PushLinkStack(LinkStNode*& s, int e) {
	LinkStNode* p;
	p = (LinkStNode*)malloc(sizeof(LinkStNode));
	p->data = e;
	p->next = s->next;
	s->next = p;
	return true;
}
bool PopLinkStack(LinkStNode* s, int& e) {
	LinkStNode* p;
	if (s->next == NULL)
		return false;
	p = s->next;
	e = p->data;
	s->next = p->next;
	free(p);
	return true;
}
bool GetTopLinkStack(LinkStNode* s, int& e) {
	if (s->next == NULL)
		return false;
	e = s->next->data;
	return true;
}

//初始化队列
void InitQueue(SqQueue*& s) {
	s = (SqQueue*)malloc(sizeof(SqQueue));
	s->front = s->rear = -1;
}
void DestorySqQueue(SqQueue* s) {
	free(s);
}
bool SqQueueEmpty(SqQueue* s)
{
	return (s->front == s->rear);
}
bool enQueue(SqQueue*& s, int e) {
	if (s->rear == MaxSize - 1) {
		return false;
	}
	s->rear++;
	s->data[s->rear] = e;
	return true;
}
bool deQueue(SqQueue*& s, int& e) {
	if (s->front == s->rear) {
		return false;
	}
	s->front++;
	e = s->data[s->front];
	return true;
}