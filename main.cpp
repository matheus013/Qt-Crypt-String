#include "cryptxor.h"
#include <QDebug>

int main(){

    CryptXOR crypt;
    QString encrypted = crypt.crypt("123456");
//    qDebug() << encrypted;
    QVector<int> vector;
    vector  << 1 << 79 << 47 << 31 << 109 << 59 << 23 << 131071 << 19 << 3 << 199 << 7 << 5 << 37 << 71 << 43 << 7 << 11 << 73
           << 163 << 127 << 193 << 53 << 157 << 179 << 13 << 101 << 3 << 83 << 151 << 149 << 173 << 107 << 181 << 8191
           << 139 << 127 << 197 << 29 << 31 << 61 << 17 << 2147483647 << 524287 << 89 << 97 << 191 << 67 << 41 << 113
           << 131 << 137 << 103 << 167;
    CryptXOR nocrypt(vector);
    qDebug() << "chave certa" << crypt.crypt(encrypted);
    qDebug() << "chave errada" << nocrypt.crypt(encrypted);
    qDebug() << crypt.authenticate("matheus2",encrypted);
    return 0;
}
