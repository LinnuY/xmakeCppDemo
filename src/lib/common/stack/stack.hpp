#pragma once
#include <cstdlib>

namespace linuy
{
    template <class T>
    class Stack
    {
    private:
        const int MAX_SIZE = 512;
        int length;
        int size;
        T *head;

        void expansion()
        {
            length += MAX_SIZE;
            head = (T *)realloc(head, sizeof(T) * length);
        }

    public:
        Stack()
        {
            size = 0;
            length = MAX_SIZE;
            head = (T *)malloc(sizeof(T) * length);
        }

        ~Stack()
        {
            free(head);
            head = nullptr;
        }

        void pop()
        {
            if (size != 0)
                size--;
        }

        void push(const T &element)
        {
            if (size + 1 == length)
            {
                expansion();
            }
            size++;
        }

        T top()
        {
            return head[size];
        }

        int getSize()
        {
            return size;
        }

        int getLength()
        {
            return length;
        }

        bool empty()
        {
            return size == 0;
        }
    };
}