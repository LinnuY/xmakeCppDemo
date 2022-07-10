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
        std::unique_ptr<T> head;

        void expansion()
        {
            length += MAX_SIZE;
            auto temp = std::make_unique<T>(length);
            for (int i = 0; i < size; i++)
            {
                temp[i] = head[i];
            }
            head = temp;
        }

    public:
        StackSmartPointer() : size(0), length(MAX_SIZE), head(std::make_unique<T>(length)) {}

        ~StackSmartPointer()
        {
            head.reset();
        }

        void pop()
        {
            size--;
        }

        void push(const T & element)
        {
            if (size + 1 == length)
            {
                expansion();
            }
            size++;
            head.get()[size] = element;
        }

        T top()
        {
            return head.get()[size];
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
            return !size;
        }
    };
}