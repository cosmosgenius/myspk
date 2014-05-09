#ifndef MICACCESS_H
#define MICACCESS_H

#include<QAudioInput>

class MicAccess : public QIODevice
{
    Q_OBJECT
public:
    MicAccess(const QAudioFormat &format, QObject *parent);
    ~MicAccess();


    void start();
    void stop();

    qreal level() const { return m_level; }

    qint64 readData(char *data, qint64 maxlen);
    qint64 writeData(const char *data, qint64 len);

private:
    const QAudioFormat m_format;
    quint32 m_maxAmplitude;
    qreal m_level; // 0.0 <= m_level <= 1.0


signals:
    void update();
};

#endif // MICACCESS_H
