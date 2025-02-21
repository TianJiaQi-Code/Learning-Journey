//循环队列的结构
typedef struct
{
    int* a;
    int front;
    int rear;
    int k;
} MyCircularQueue;

//开辟空间并初始化
MyCircularQueue* myCircularQueueCreate(int k)
{
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    //多开一个方便区分空和满
    obj->a = (int*)malloc(sizeof(int) * (k + 1));
    obj->front = obj->rear = 0;
    obj->k = k;
    return obj;
}

//判断队列是否为空
bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
    return obj->front == obj->rear;
}

bool myCircularQueueIsFull(MyCircularQueue* obj)
{
    return (obj->rear + 1) % (obj->k + 1) == obj->front;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
    if (myCircularQueueIsFull(obj))
        return false;
    obj->a[obj->rear] = value;
    obj->rear++;
    obj->rear %= (obj->k + 1);
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
    if (myCircularQueueIsEmpty(obj))
        return false;

    obj->front++;
    obj->front %= (obj->k + 1);
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj)
{
    if (myCircularQueueIsEmpty(obj))
        return -1;
    else
        return obj->a[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj)
{
    if (myCircularQueueIsEmpty(obj))
        return -1;
    else
        return obj->a[(obj->rear + obj->k) % (obj->k + 1)];
}

void myCircularQueueFree(MyCircularQueue* obj)
{
    free(obj->a);
    free(obj);
}