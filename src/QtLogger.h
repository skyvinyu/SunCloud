#ifndef QTLOGGER_H
#define QTLOGGER_H

#include <QDebug>

#include <boost/thread.hpp>
#include <boost/interprocess/detail/os_thread_functions.hpp>

#define CODE_LOCATION __FILE__ << " (" << __LINE__ << ") @ " << __FUNCTION__ << ": "
#define GET_PID ";  pid = " << boost::interprocess::ipcdetail::get_current_process_id() << "; "
#define GET_THREAD_ID ";  tid = " << boost::this_thread::get_id() << "; "

#ifdef DDEBUG
    #define DEBUG_LOG
#else
    #define RUNTIME_LOG
    //#define NO_LOG
#endif

#ifdef DEBUG_LOG

//#define FWK_DEBUG(arg)   qDebug()    << GET_PID << GET_THREAD_ID << arg;
//#define FWK_WARNING(arg) qWarning()  << GET_PID << GET_THREAD_ID << arg;
//#define FWK_ERROR(arg)   qCritical() << GET_PID << GET_THREAD_ID <<  arg);

#define FWK_DEBUG(arg)   qDebug()    << arg;
#define FWK_WARNING(arg) qWarning()  << arg;
#define FWK_ERROR(arg)   qCritical() << arg);

#endif

#ifdef RUNTIME_LOG

#define FWK_DEBUG(arg)
#define FWK_WARNING(arg) qWarning()  << arg;
#define FWK_ERROR(arg)   qCritical() << arg);

#endif

#ifdef NO_LOG

#define FWK_DEBUG(arg)
#define FWK_INFO(arg)
#define FWK_WARNING(arg)
#define FWK_ERROR(arg)

#endif

namespace altran {
namespace suncloud {



}
}

#endif // QTLOGGER_H
