#ifndef QRUNTIMEERROR_H
#define QRUNTIMEERROR_H

#include <QString>
#include <stdexcept>
#include <string>

class QRuntimeError final : std::runtime_error
{
public:
    QRuntimeError(const QString& msg);

    QString qwhat() const noexcept;


private:
    QString m_msg;
};

#endif // QRUNTIMEERROR_H
