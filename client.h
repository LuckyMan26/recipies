
#ifndef CLIENT_H
#define CLIENT_H


#include <QObject>
#include <QTcpSocket>

class client : public QObject
{
    Q_OBJECT
    QTcpSocket* socket;
    QString name;
    QString password;
    QByteArray Data;
public:
    client();
    Q_INVOKABLE void sendToServer(QString str);
public slots:
    void readyRead();

signals:
    void g();

};

#endif // CLIENT_H
