#include "cryptxor.h"
#include <QDebug>

int main(){

    CryptXOR crypt;
    QString encrypted = crypt.crypt("123456");
//    qDebug() << encrypted;
    qDebug() << crypt.authenticate("matheus2",encrypted);
    return 0;
}
