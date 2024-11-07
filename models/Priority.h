#ifndef PRIORITY_H
#define PRIORITY_H

template <class T>
class Priority
{
public:
    virtual ~Priority() = default;

    Priority() {}

    virtual T getPriority() = 0;

    virtual void setPriority(T priority) = 0;
};

#endif
