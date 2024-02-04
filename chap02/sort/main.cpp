#include <QApplication>
#include <QDebug>
#include "sortdialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QString greeting = "Hello World!";
    QByteArray buffer(greeting.toUtf8());
    buffer.append("!");
    qInfo() << buffer;

    qInfo() << buffer.rightJustified(18,'.');
    qInfo() << buffer.at(buffer.length() - 1);

    QString modified(buffer);
    qInfo() << modified;

    //Basic encoding and decoding
    qInfo() << buffer.toBase64();
    qInfo() << buffer.toHex();
    SortDialog *dialog = new SortDialog;
    dialog->setColumnRange('C', 'F');


    QString data = "Hello world how are you";
    QStringList lst = data.split(" ");
    qInfo() << lst;

    foreach(QString str,lst)
    {
        qInfo() << str;
    }

    lst.sort(Qt::CaseInsensitive);
    qInfo() << lst;

    QString myvar = "Hello";
    if(lst.contains(myvar))
    {
        QVariant index = lst.indexOf(myvar);
        qInfo() << lst.value(index.toInt())<<" in postion: "<<index;
    }
    dialog->show();
    return app.exec();
}
