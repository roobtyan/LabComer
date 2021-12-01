#include "remotecommand.h"

RemoteCommand::RemoteCommand(QString number, QString name, QString value, QString source)
{
    this -> remoteNumber = number;
    this -> remoteValue = value;
    this -> remoteName = name;
    this -> remoteSource = source;
}

RemoteCommand::RemoteCommand()
{

}

QString RemoteCommand::getRemoteNumber() const
{
    return remoteNumber;
}

void RemoteCommand::setRemoteNumber(const QString &value)
{
    remoteNumber = value;
}

QString RemoteCommand::getRemoteName() const
{
    return remoteName;
}

void RemoteCommand::setRemoteName(const QString &value)
{
    remoteName = value;
}

QString RemoteCommand::getRemoteValue() const
{
    return remoteValue;
}

void RemoteCommand::setRemoteValue(const QString &value)
{
    remoteValue = value;
}

QString RemoteCommand::getRemoteSource() const
{
    return remoteSource;
}

void RemoteCommand::setRemoteSource(const QString &value)
{
    remoteSource = value;
}
