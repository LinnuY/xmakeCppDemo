#pragma once

namespace linuy
{
    template<class T>
    class Queue
    {
    private:

    public:
        Queue()
        {

        }

        ~Queue()
        {

        }

        Queue operator=(const Queue & queue)
        {

        }


        T & front()
        {

        }

        T & back()
        {

        }

        bool empty()
        {
            return length == 0;
        }

        bool size()
        {
            return _size;
        }

        void push(T & element)
        {
            if (length + 1 == size)
                expansion();
            length++;
            head[length] = element;
        }

        void pop()
        {
            head++;
            size--
        }
    };
}