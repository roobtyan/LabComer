#ifndef COMMANDOPENHEMPJET_H
#define COMMANDOPENHEMPJET_H

#include <QWidget>

namespace Ui {
class CommandOpenHempjet;
}

class CommandOpenHempjet : public QWidget
{
    Q_OBJECT

public:
    explicit CommandOpenHempjet(QWidget *parent = nullptr);
    ~CommandOpenHempjet();

    /**
     * @brief openHempjet指令
     * @param VoltageSet_HEMPJET
     * @param P1_HEMPJET
     * @param P2_HEMPJET
     * @param Pressure_HEMPJET
     * @param TimeDuration_HEMPJET
     * @return
     */
    QString openHempJet(QString VoltageSet_HEMPJET, QString P1_HEMPJET, QString P2_HEMPJET,
                        QString Pressure_HEMPJET, QString TimeDuration_HEMPJET);

signals:

    void sendOpenHempJetCommandToMainWindow(QString str);

private slots:
    void on_pushButton_clicked();

private:
    Ui::CommandOpenHempjet *ui;
};

#endif // COMMANDOPENHEMPJET_H
