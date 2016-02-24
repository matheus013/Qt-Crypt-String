#pragma once

#include <QObject>
#include <QVector>

class CryptXOR : public QObject {
    Q_OBJECT
    QVector<int> m_key;
    QVector<ushort> crypt(const QVector<ushort> input);
    QString toString(QVector<ushort> vector);
    QVector<ushort> toVector(QString input);
public:
    CryptXOR();
    QString crypt(const QString input);
    bool authenticate(QString tryPassword,QString encryptedPassword);


};
