#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QSettings>

#define gSettings Settings::instance()

class Settings : public QObject
{
    Q_OBJECT
public:
    explicit Settings(QObject *parent = nullptr);

    static Settings &instance();

    void saveSplitterState(const QByteArray &value);
    QByteArray splitterState() const;

    void saveMaximized(bool value);
    bool isMaximized() const;

    void savePortName(const QString &value);
    QString portName() const;
    void saveBaudRate(int value);
    int baudRate() const;
    void saveDataBits(int value);
    int dataBits() const;
    void saveParity(int value);
    int parity() const;
    void saveStopBits(int value);
    int stopBits() const;
    void saveFlowControl(int value);
    int flowControl() const;

    void saveAppFont(const QFont &font);
    QFont appFont();
    void saveSessionFont(const QFont &font);
    QFont sessionFont();

signals:

private:
    QSettings *m_settings = nullptr;
};

#endif // SETTINGS_H
