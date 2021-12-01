#ifndef REMOTECOMMAND_H
#define REMOTECOMMAND_H
#include "QString"


class RemoteCommand
{
public:
    RemoteCommand(QString number, QString name, QString value, QString source);
    RemoteCommand();


    QString getRemoteNumber() const;
    void setRemoteNumber(const QString &value);

    QString getRemoteName() const;
    void setRemoteName(const QString &value);

    QString getRemoteValue() const;
    void setRemoteValue(const QString &value);

    QString getRemoteSource() const;
    void setRemoteSource(const QString &value);

private:
    QString remoteNumber;
    QString remoteName;
    QString remoteValue;
    QString remoteSource;
};

#endif // REMOTECOMMAND_H
