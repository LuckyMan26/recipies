
#include "server.h"


server::server()
{

    if(this->listen(QHostAddress::Any,2023)){
        qDebug() << "fine\n";
    }
    else{
         qDebug() << "error\n";
    }
}


void server::connectToServer(qintptr socketDescriptor)
{
    QTcpSocket* socket_ = new QTcpSocket;
    socket_->setSocketDescriptor(socketDescriptor);
    connect(socket_,&QTcpSocket::readyRead,this,&server::readyRead);
    connect(socket_,&QTcpSocket::disconnected,socket_,&QTcpSocket::deleteLater);

    sockets.push_back(socket_);
}

void server::readyRead(){
    socket = (QTcpSocket*)sender();
    QDataStream in(socket);
    if(in.status() == QDataStream::Ok){
         qDebug() << "read...";
         QString str;
         in >> str;
         qDebug() << str;
    }
    else{
         qDebug() << "Error\n";
    }
}

void server::sendToClient(QString str){
    Data.clear();
    QDataStream out(&Data,QIODevice::WriteOnly);
    out << str;
    socket->write(Data);
}
