#include "qruntimeerror.h"

QRuntimeError::QRuntimeError(const QString& msg)
    :
      std::runtime_error(msg.toUtf8().constData()),
      m_msg(msg)
{
}

QString QRuntimeError::qwhat() const noexcept
{
    return m_msg;
}
