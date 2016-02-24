#include "cryptxor.h"

QVector<ushort> CryptXOR::crypt(const QVector<ushort> input) {
    QVector<ushort> output = input;
    for (int i = 0; i < input.size(); i++)
        output[i] ^= m_key[i % (sizeof(m_key) / sizeof(char)) ];
    return output;
}

QString CryptXOR::toString(QVector<ushort> vector){
    QString result = "";
    for (QVector<ushort>::iterator i = vector.begin();i != vector.end() ;++i)
        result += uchar(*i);
    return result;
}

QVector<ushort> CryptXOR::toVector(QString input) {
    QVector<ushort> result;
    for (QString::iterator i = input.begin(); i != input.end(); ++i)
        result  <<  (*i).cell();
    return result;
}

CryptXOR::CryptXOR() {
    m_key  << 79 << 47 << 31 << 109 << 59 << 23 << 131071 << 19 << 3 << 199 << 7 << 5 << 37 << 71 << 43 << 7 << 11 << 73
           << 163 << 127 << 193 << 53 << 157 << 179 << 13 << 101 << 3 << 83 << 151 << 149 << 173 << 107 << 181 << 8191
           << 139 << 127 << 197 << 29 << 31 << 61 << 17 << 2147483647 << 524287 << 89 << 97 << 191 << 67 << 41 << 113
           << 131 << 137 << 103 << 167 << 1;
}

QString CryptXOR::crypt(const QString input) {
    QVector<ushort> vector = toVector(input);
    return toString(crypt(vector));
}

bool CryptXOR::authenticate(QString tryPassword, QString encryptedPassword) {
    return tryPassword == crypt(encryptedPassword);
}

