
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

    void connectToServer(qintptr socketDescriptor);
    void sendData(QByteArray Data);
    server();
    void sendToClient(QString Data);
public slots:
    void readyRead();
};

#endif // SERVER_H
