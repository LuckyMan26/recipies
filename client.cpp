
#include "client.h"
#include <iostream>
client::client()
{
    socket = new QTcpSocket();
    socket->connectToHost("127.0.0.0", 2323);

    qDebug() << "Socket state after connection: " << socket->state();

    QObject::connect(socket,&QTcpSocket::readyRead,this,&client::readyRead);
    QObject::connect(socket,&QTcpSocket::disconnected,socket,&QTcpSocket::deleteLater);

}

void client::readyRead(){

    QDataStream in(socket);
    if(in.status() == QDataStream::Ok){
        QString str;
        in >> str;
        qDebug() << "Client: " << str;
        std::cout<<"Client\n";

    }
    else{
       qDebug() << "Client: " << "read error";
    }
}

void client::sendToServer(QString str){

    Data.clear();
    QDataStream out(&Data,QIODevice::WriteOnly);
    out << str;
    socket->write(Data);
}
