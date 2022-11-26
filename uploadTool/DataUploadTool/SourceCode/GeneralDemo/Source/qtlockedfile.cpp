#include "qtlockedfile.h"

QtLockedFile::QtLockedFile()
    : QFile()
{
#ifdef Q_OS_WIN
    wmutex = 0;
    rmutex = 0;
#endif
    m_lock_mode = NoLock;
}

/*!
    Constructs an unlocked QtLockedFile object with file \a name. This
    constructor behaves in the same way as \e QFile::QFile(const
    QString&).

    \sa QFile::QFile()
*/
QtLockedFile::QtLockedFile(const QString &name)
    : QFile(name)
{
#ifdef Q_OS_WIN
    wmutex = 0;
    rmutex = 0;
#endif
    m_lock_mode = NoLock;
}

/*!
  Opens the file in OpenMode \a mode.

  This is identical to QFile::open(), with the one exception that the
  Truncate mode flag is disallowed. Truncation would conflict with the
  advisory file locking, since the file would be modified before the
  write lock is obtained. If truncation is required, use resize(0)
  after obtaining the write lock.

  Returns true if successful; otherwise false.

  \sa QFile::open(), QFile::resize()
*/
bool QtLockedFile::open(OpenMode mode)
{
    if (mode & QIODevice::Truncate) {
        qWarning("QtLockedFile::open(): Truncate mode not allowed.");
        return false;
    }
    return QFile::open(mode);
}

/*!
    Returns \e true if this object has a in read or write lock;
    otherwise returns \e false.

    \sa lockMode()
*/
bool QtLockedFile::isLocked() const
{
    return m_lock_mode != NoLock;
}

/*!
    Returns the type of lock currently held by this object, or \e
    QtLockedFile::NoLock.

    \sa isLocked()
*/
QtLockedFile::LockMode QtLockedFile::lockMode() const
{
    return m_lock_mode;
}

