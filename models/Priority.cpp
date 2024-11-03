#ifndef PRIORITY
#define PRIORITY

template <class T>
class Priority
{
public:
    virtual ~Priority() = default;

    Priority() {}

    virtual void getPriority() = 0;

    virtual void setPriority(int priority) = 0;
};

#endif
