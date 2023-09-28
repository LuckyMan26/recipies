
#include "server.h"


server::server()
{

    if(this->listen(QHostAddress::Any,2323)){
        qDebug() << "fine\n";
    }
    else{
         qDebug() << "error\n";
    }

}


void server::incommingConnection(qintptr socketDescriptor)
{
    socket= new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);

    connect(socket,&QTcpSocket::readyRead,this,&server::readyRead);
    connect(socket,&QTcpSocket::disconnected,socket,&QTcpSocket::deleteLater);

    sockets.push_back(socket);
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

    qDebug()<<"1";

    Data.clear();
    QDataStream out(&Data,QIODevice::WriteOnly);
    out << str;
    for(int i=0;i<sockets.size();i++)
        sockets[i]->write(Data);
}
