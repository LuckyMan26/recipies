
#ifndef CLIENT_H
#define CLIENT_H


#include <QObject>
#include <QTcpSocket>

class client
{
    Q_OBJECT
    QTcpSocket* socket;
    QString name;
    QString password;
    QByteArray Data;
public:
    client();
    void sendToServer(QString str);
public slots:
    void readyRead();

};

#endif // CLIENT_H
