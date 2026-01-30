#include "interface.h"
#include "pimpl.h"

Widget::~Widget()
{
}

Widget::Widget()
{
}

void Widget::doSomething()
{
    return impl()->doSomething();
}