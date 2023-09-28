
#ifndef SERVER_H
#define SERVER_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
class server : public QTcpServer
{
    Q_OBJECT
    QTcpSocket* socket;
    QVector<QTcpSocket*> sockets;
    QByteArray Data;
public:



    server();
    Q_INVOKABLE void sendToClient(QString Data);
public slots:
    void readyRead();
    void incommingConnection(qintptr socketDescriptor);

};

#endif // SERVER_H
