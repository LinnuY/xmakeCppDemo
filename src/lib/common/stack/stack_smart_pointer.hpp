#pragma once
#include <cstdlib>
#include <memory>

namespace linuy
{
    template <class T>
    class StackSmartPointer
    {
    private:
        const int MAX_SIZE = 512;
        int length;
        int size;
        int byte_size;
        std::shared_ptr<T> head;
        std::shared_ptr<T> end;

        void expansion()
        {
            length += MAX_SIZE;
            head = std::make_shared()
            head = (T *)realloc(head, sizeof(T) * length);
        }

    public:
        Stack() : size(0), byte_size(sizeof(T) / sizeof(int)), length(MAX_SIZE)
        {
            head = std::make_shared(length, T);
            end = head;
        }

        ~Stack()
        {
            head.reset();
            end.reset();
        }

        void pop()
        {
            size--;
            end -= byte_size;
        }

        void push(const T &element)
        {
            if (size + 1 == length)
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
            return head == end;
        }
    };
}