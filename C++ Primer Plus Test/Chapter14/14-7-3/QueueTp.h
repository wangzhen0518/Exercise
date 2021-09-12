#ifndef QUEUETP_H_
#define QUEUETP_H_

template <typename T>
class QueueTp
{
private:
    T *q;
    int head;
    int rear;
    int size;
    int num;

public:
    QueueTp(int len = 10)
    {
        q = new T[len];
        head = rear = 0;
        size = len;
        num = 0;
    }
    ~QueueTp()
    {
        delete[] q;
    }
    bool isfull() const { return num == size; }
    bool isempty() const { return num == 0; }
    bool push(const T &t)
    {
        if (num == size)
        {
            return false;
        }
        else
        {
            q[rear] = t;
            rear = (rear + 1) % size;
            num++;
            return true;
        }
    }
    bool pop(T &t)
    {
        if (num == 0)
            return false;
        else
        {
            t = q[head];
            head = (head + 1) % size;
            num--;
            return true;
        }
    }
};

#endif
