#include <stdio.h>
#include <stdlib.h>

#define OK    1
#define ERROR 0

typedef char ElemType;
typedef int  Status;

typedef struct QNode{
    ElemType data;
    struct QNode * next;
}QNode, *QueuePtr;

typedef struct{
    QueuePtr front;         //��ͷָ��
    QueuePtr rear;          //��βָ��
}LinkQueue;

void visit(ElemType e);
//��ʼ������
Status InitQueue(LinkQueue *Q){

    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
    if(!Q->front)
        return ERROR;
    Q->front->next = NULL;
    printf("���г�ʼ���ɹ���\n");
    return OK;
}
//����
Status EnQueue(LinkQueue *Q, ElemType e){
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(QNode));
    if(!p)
        return ERROR;
    p->data = e;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
    return OK;
}
//��ʾ����Ԫ��
Status QueueTraverse(LinkQueue Q){
    QueuePtr p;
    p = Q.front;
    if(Q.front == Q.rear)return ERROR;
    while(p!=Q.rear){
        p = p->next;
        visit(p->data);
    }
    printf("\n");
    return OK;
}
//ɾ����ͷ
Status DeQueue(LinkQueue *Q, ElemType *e){

    QueuePtr p;

    if(Q->front == Q->rear)
        return ERROR;
    p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;
    if(Q->rear == p)
        Q->rear = Q->front;
    free(p);
    printf("ɾ����ͷ�ɹ���\n");
    return OK;
}
//���ٶ���
Status DestoryQueue(LinkQueue *Q){
    while(Q->front){
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }

    printf("���ٶ��гɹ���\n");
    return OK;
}
//�ж��Ƿ�Ϊ�ն���
 Status QueueEmpty(LinkQueue *Q){
    if(Q->front == Q->rear){
        printf("����Ϊ��\n");
        return ERROR;
    }
    printf("���в�Ϊ��\n");
    return OK;
}
//����г���
int QueueLength(LinkQueue Q){
    if(QueueEmpty(&Q) == 0){
        return 0;
    }
    else{
        QueuePtr p;
        int i=0;
        p = Q.front->next;
        while(p){
            i++;
            p = p->next;
        }
        return i;
    }
}

//��ȡ��ͷ
Status GetHead(LinkQueue Q, ElemType *e){
    if(QueueEmpty(&Q) == 0 ){
        return ERROR;
    }
    else{
        *e = Q.front->next->data;
        return OK;
    }
}

//��ն��У��ǵú����ٶ��е�����
Status ClearQueue(LinkQueue *Q){
    Q->rear = Q->front;
    return OK;
}
void visit(ElemType e){
    printf("%c  ", e);
}

int main()
{
    LinkQueue Q;
    ElemType e;
    InitQueue(&Q);
    QueueEmpty(&Q);
    printf("�������ַ���ӵ�������(�س�����������)��");
    while(1){

        scanf("%c", &e);
        if(e == 10){
            break;
        }
        EnQueue(&Q, e);
    }
    QueueEmpty(&Q);
    printf("���еĳ��ȣ�%d\n",QueueLength(Q));
    GetHead(Q, &e);
    printf("��ͷԪ�ص�ֵ�ǣ�%c\n", e);
    QueueTraverse(Q);
    DeQueue(&Q, &e);
    printf("ɾ����Ķ��еĳ��ȣ�%d\n",QueueLength(Q));
    GetHead(Q, &e);
    printf("ɾ����Ķ�ͷԪ�ص�ֵ�ǣ�%c\n", e);
    QueueTraverse(Q);
    ClearQueue(&Q);
    printf("��պ�Ķ��еĳ��ȣ�%d\n",QueueLength(Q));
    DestoryQueue(&Q);
    system("pause");
    return 0;
}
