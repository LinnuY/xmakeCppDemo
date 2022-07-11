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
        int byte_size;
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
            byte_size = sizeof(T) / sizeof(int);
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
            if (size - 1 != 0)
                size--;
        }

        void push(const T &element)
        {
            if (size + 1 == length)
            {
                expansion();
            }
            size++;
            head[size] = element;
        }

        T top()
        {
            return *end;
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