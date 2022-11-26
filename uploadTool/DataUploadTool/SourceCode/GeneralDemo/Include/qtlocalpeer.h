#ifndef DATA_UPLOAD_QTLOCALPEER_H
#define DATA_UPLOAD_QTLOCALPEER_H

#include <QLocalServer>
#include <QLocalSocket>
#include <QDir>

#include "qtlockedfile.h"


class QtLocalPeer : public QObject
{
    Q_OBJECT

public:
    QtLocalPeer(QObject *parent = 0, const QString &appId = QString());
    bool isClient();
    bool sendMessage(const QString &message, int timeout);
    QString applicationId() const
        { return id; }

Q_SIGNALS:
    void messageReceived(const QString &message);

protected Q_SLOTS:
    void receiveConnection();

protected:
    QString id;
    QString socketName;
    QLocalServer* server;
    QtLockedFile lockFile;

private:
    static const char* ack;
};

#endif // DATA_UPLOAD_QTLOCALPEER_H
