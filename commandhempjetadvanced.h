#ifndef COMMANDHEMPJETADVANCED_H
#define COMMANDHEMPJETADVANCED_H

#include <QWidget>

namespace Ui {
class CommandHempJetAdvanced;
}

class CommandHempJetAdvanced : public QWidget
{
    Q_OBJECT

public:
    explicit CommandHempJetAdvanced(QWidget *parent = nullptr);
    ~CommandHempJetAdvanced();

    /**
     * @brief 指令生成
     * @param riseTime_HEMPJET
     * @param closeTime_HEMPJET
     * @param riseVoltage_HEMPJET
     * @param holdVoltage_HEMPJET
     * @param closeVoltage_HEMPJET
     * @param VoltageSet_ad_HEMPJET
     * @return
     */
    QString hempJetAdvancedValues(QString riseTime_HEMPJET, QString closeTime_HEMPJET, QString riseVoltage_HEMPJET,
                                  QString holdVoltage_HEMPJET, QString closeVoltage_HEMPJET, QString VoltageSet_ad_HEMPJET);

private slots:
    void on_pushButton_clicked();

signals:

    void sendHempJetAdvancedCommand(QString str);

private:
    Ui::CommandHempJetAdvanced *ui;
};

#endif // COMMANDHEMPJETADVANCED_H
