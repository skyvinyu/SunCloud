#include "ApplicationException.h"

#include <string>
#include <stdio.h>

#if _MSC_VER
#define snprintf _snprintf
#endif

namespace fwk{
namespace tools{

std::string buildMessage(const std::string& what, int errorId, unsigned line_number, const std::string& filename){
    std::string msg = what;

    if (errorId > -1) {
        char number[10];
        if (snprintf(number, 10, "%d", errorId)) {
            std::string tmp(number);
            msg += ": Id" + tmp;
        }
    }
    if (!filename.empty()) {
        msg += ": " + filename ;
    }
    if (line_number > 0) {
        char number[10];
        if (snprintf(number, 10, "%d", line_number)) {
            std::string tmp(number);
            msg += "(" + tmp + ")";
        }
    }

    return msg;
}

ApplicationException::ApplicationException(const std::string& what)
        :   std::runtime_error(buildMessage(what, -1, 0, "")),
            m_errorId(-1),
            m_lineNumber(-1),
            m_file(""),
            m_innerException(0){
}

ApplicationException::ApplicationException(const std::string& what, unsigned line_number, const std::string& filename)
        :   std::runtime_error(buildMessage(what, -1, line_number, filename)),
            m_errorId(-1),
            m_lineNumber(line_number),
            m_file(filename),
            m_innerException(0){
}

ApplicationException::ApplicationException(const std::string& what, int errorId, unsigned line_number, const std::string& filename)
        :   std::runtime_error(buildMessage(what, errorId, line_number, filename)),
            m_errorId(errorId),
            m_lineNumber(line_number),
            m_file(filename),
            m_innerException(0){
}

ApplicationException::ApplicationException(const std::string& what, const std::exception& innerException)
        :   std::runtime_error(buildMessage(what, -1, 0, "")),
            m_errorId(-1),
            m_lineNumber(0),
            m_file(""),
            m_innerException(&innerException){
}

ApplicationException::ApplicationException(const std::string& what, const std::exception& innerException, unsigned line_number, const std::string& filename)
        :   std::runtime_error(buildMessage(what, -1, line_number, filename)),
            m_errorId(-1),
            m_lineNumber(line_number),
            m_file(filename),
            m_innerException(&innerException){
}

ApplicationException::ApplicationException(const std::string& what, const std::exception& innerException, int errorId, unsigned line_number, const std::string& filename)
        :   std::runtime_error(buildMessage(what, errorId, line_number, filename)),
            m_errorId(errorId),
            m_lineNumber(line_number),
            m_file(filename),
            m_innerException(&innerException){
}

ApplicationException::~ApplicationException() throw() {

}

std::string ApplicationException::getFullMessage(const std::string& separator) const {
    std::string fullMessage = what();
    auto pInner = m_innerException;
    while (pInner) {
        fullMessage += separator;
        fullMessage += pInner->what();
        auto pAppInner = dynamic_cast<const ApplicationException* const>(pInner);
        if (pAppInner) {
            pInner = pAppInner->getInnerException();
        } else {
            pInner = 0;
        }
    }
    return fullMessage;
}



}
}

