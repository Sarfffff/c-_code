#include<iostream>
#define MaxSize 50
using namespace std;
typedef struct LNode {
	int data;
	struct LNode* next;
}LinkNode;//������

typedef struct DNode {
	int data;
	struct DNode* next;
	struct DNode* prior;
}DLinkNode;//˫����

typedef struct { //ջ
	int data[MaxSize];
	int top;
}SqStack;
typedef struct { //����ջ
	int data[MaxSize];
	int top1��top2;
}DStack;
typedef struct linknode { //����ջ
	int data;
	struct linknode* next;
}LinkStNode;
typedef struct {
	int data[MaxSize];
	int front, rear;
}SqQueue;//����
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
}//��ʼ������
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
}//β�巨
void InitList(LinkNode* L) {
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
}//��ʼ������
void DestoryLink(LinkNode* L) {
	LinkNode* pre = L, * p = L->next;
	while (L != NULL) {
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);
}//��������
bool ListEmpty(LinkNode* L) {
	if (L->next == NULL) {
		return 1;
	}
	else
		return 0;
}//�ж������Ƿ�Ϊ��
int ListLength(LinkNode* L) {
	int n = 0;
	LinkNode* S = L;
	while (S->next != NULL) {
		n++;
		S = S->next;
	}
	return n;
}//������ĳ���
void DisList(LinkNode* L) {
	LinkNode* M = L->next;
	while (M->next != NULL) {
		cout << M->data << endl;
		M = M->next;
	}
}//�������
bool GetElem(LinkNode* L, int i, int& e) {//������������е�Ԫ��
	int j = 0;
	LinkNode* p = L;
	if (i <= 0)					//�ж�����Ƿ����
		return false;
	while (j < i && p != NULL) {
		j++;
		p = p->next;	//��˳��Ѱ������Ԫ�ص�λ��
	}
	if (p == NULL) {
		return false;
	}
	else {
		e = p->data;
		return true;
	}
}
int locateELem(LinkNode* L, int e) {//��Ԫ��ֵ����
	int i = 1;
	LinkNode* p = L->next;
	while (p != NULL && e != p->data) {//�ж�����
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
	while (j < i - 1 && p != NULL) {//�ҵ�����λ�õ�ǰһ����㴦
		p = p->next;
		j++;
	}
	if (p == NULL) {
		return false;
	}
	else {
		s = (LinkNode*)malloc(sizeof(LinkNode));//�ҵ�λ�ú󽫽ڵ��s
		s->data = e;
		s->next = p->next;
		p->next = s;
		return true;

	}

}//��ĳ�ڵ㴦����Ԫ��
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
}//ɾ��ĳ�ڵ��Ԫ��


//˫�����ͷ�巨��β�巨
void CreatListF(DLinkNode*& L, int a[], int n) {
	DLinkNode* s;
	L = (DLinkNode*)malloc(sizeof(DLinkNode));
	L->prior = L->next = NULL;//ǰ��ָ����ΪNULL
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

//��ʼ��ջ
void InitStack(SqStack*& s) {
	s = (SqStack*)malloc(sizeof(SqStack));
	s->top = -1;								//ջ�յ�����
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
bool Push(SqStack*& s, int e) {//��ջ
	if (s->top == MaxSize - 1) {//ջ��������
		return false;
	}
	s->top++;
	s->data[s->top] = e;
	return true;
}
bool Pop(SqStack*& s, int e) {//��ջ
	if (s->top == -1) {
		return false;
	}
	e = s->data[s->top];
	s->top--;
	return true;
}
bool GetTop(SqStack* s, int& e) { //ȡջ��Ԫ��
	if (s->top == -1) {
		return false;
	}
	e = s->data[s->top];
	return true;
}

//��ʼ����ջ
void LinkStack(LinkStNode*& s) {
	s = (LinkStNode*)malloc(sizeof(LinkStNode));
	s->next = NULL;
}
//����ջ
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

//��ʼ������
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