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

        void expansion()
        {
            length += MAX_SIZE;
            head.reset(std::make_shared<T>(length));
        }

    public:
        StackSmartPointer() : size(0), byte_size(sizeof(T) / sizeof(int)), length(MAX_SIZE), head(std::make_shared<T>(length)) {}

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