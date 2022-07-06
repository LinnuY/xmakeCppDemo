#pragma once
#include <cstdlib>

namespace linuy
{
    template<class T>
    class Stack
    {
    private:
        const int MAX_SIZE = 1 << 10;
        int length;
        int size;
        int byte_size;
        T * head;
        T * end;

        void expansion()
        {
            length += MAX_SIZE;
            head = (T*) realloc(sizeof(T) * length);
            return true;
        }
    public:
        Stack()
        {
            size = 0;
            byte_size = sizeof(T)/sizeof(int);
            length = MAX_SIZE;
            head = (T*) malloc(sizeof(T) * length);
            end = head;
        }

        ~Stack()
        {
            free(head);
            head = nullptr;
            end = nullptr;
        }

        void pop()
        {
            size--;
            end -= byte_size;
        }

        void push(T & element)
        {
            if (size + 1= length)
            {
                expansion();
            }
            size++;
            end += byte_size;
            *end = element;
        }

        T top()
        {
            return *end;
        }

        int size()
        {
            return size;
        }

        bool empty()
        {
            return head == end;
        }
    };
}