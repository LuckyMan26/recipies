
#ifndef A_H
#define A_H


#include <QObject>


class A : public QObject
{
    Q_OBJECT
public:
    explicit A(QObject *parent = nullptr);
    Q_INVOKABLE void f();
signals:

};

#endif // A_H
