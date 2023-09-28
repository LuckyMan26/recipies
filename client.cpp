
#include "client.h"

client::client()
{
    socket = new QTcpSocket();
    socket->connectToHost("127.0.0.1", 2323);
    QObject::connect(socket,&QTcpSocket::readyRead,this,&client::readyRead);
    QObject::connect(socket,&QTcpSocket::disconnected,socket,&QTcpSocket::deleteLater);

}

void client::readyRead(){
    QDataStream in(socket);
    if(in.status() == QDataStream::Ok){
        QString str;
        in >> str;
        qDebug() << "Client: " << str;
    }
    else{
             qDebug() << "Client: " << "read errot";
    }
}

void client::sendToServer(QString str){
    Data.clear();
    QDataStream out(&Data,QIODevice::WriteOnly);
    out << str;
    socket->write(Data);
}
