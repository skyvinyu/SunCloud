#ifndef APPLICATIONEXCEPTION_H_
#define APPLICATIONEXCEPTION_H_

#include <stdexcept>
#include <string>

namespace fwk {
namespace tools {

class ApplicationException : public std::runtime_error {
public:
    ApplicationException(const std::string& what);
    ApplicationException(const std::string& what, unsigned line_number, const std::string& filename);
    ApplicationException(const std::string& what, int errorId, unsigned line_number, const std::string& filename);

    ApplicationException(const std::string& what, const std::exception& innerException);
    ApplicationException(const std::string& what, const std::exception& innerException, unsigned line_number, const std::string& filename);
    ApplicationException(const std::string& what, const std::exception& innerException, int errorId, unsigned line_number, const std::string& filename);

    virtual ~ApplicationException() throw();

    const unsigned lineNumber()const {return m_lineNumber;}
    const std::string& file()const {return m_file;}

    std::string getFullMessage(const std::string& separator = std::string(" - caused by : ")) const ;
    const std::exception* const getInnerException() const {return m_innerException;}

private:
    int         m_errorId;
    unsigned 	m_lineNumber;
    std::string m_file;
    const std::exception* m_innerException;
};


#define  ApplicationExceptionDef(MyClass)  \
class MyClass : public ApplicationException { \
public: \
    MyClass(const std::string& what) : ApplicationException(what) {} \
    MyClass(const std::string& what, unsigned line_number, const std::string& filename) \
        : ApplicationException(what, -1, line_number, filename) {}  \
    MyClass(const std::string& what, int errorId, unsigned line_number, const std::string& filename) \
        : ApplicationException(what, errorId, line_number, filename) {}  \
    MyClass(const std::string& what, const std::exception& innerException) \
        : ApplicationException(what, innerException) {}  \
    MyClass(const std::string& what, const std::exception& innerException, unsigned line_number, const std::string& filename) \
        : ApplicationException(what, innerException, -1, line_number, filename) {}  \
    MyClass(const std::string& what, const std::exception& innerException, int errorId, unsigned line_number, const std::string& filename) \
        : ApplicationException(what, innerException, errorId, line_number, filename) {}  \
};


ApplicationExceptionDef(IllegalException);
ApplicationExceptionDef(FileIOException);
ApplicationExceptionDef(OverflowException);
ApplicationExceptionDef(FieldMissingException);
ApplicationExceptionDef(StringException);
ApplicationExceptionDef(ContainerDimensionException);
ApplicationExceptionDef(ExternalLibraryException);
ApplicationExceptionDef(NotFoundException);
ApplicationExceptionDef(BadParameterException);
ApplicationExceptionDef(NotImplementedException);


#define  THROW(MyClass, MESSAGE) throw MyClass(MESSAGE, __LINE__, __FILE__)
#define  THROW_ID(MyClass, MESSAGE, ID) throw MyClass(MESSAGE, ID, __LINE__, __FILE__)
#define  RETHROW(MyClass, MESSAGE, INNER) throw MyClass(MESSAGE, INNER, __LINE__, __FILE__)
#define  RETHROW_ID(MyClass, MESSAGE, INNER, ID) throw MyClass(MESSAGE, INNER, ID, __LINE__, __FILE__)


}
}

#endif /* APPLICATIONEXCEPTION_H_ */
