
#ifndef CONTRACT_H
#define	CONTRACT_H

#include "ApplicationException.h"

#define  RUNTIME_CHECK(checkType, exp, message) if(!(exp)) { \
throw fwk::tools::BadParameterException(std::string(checkType) + message + #exp, __LINE__, __FILE__); \
}

#ifdef DEBUG
#define  PRECONDITION(exp, message)	RUNTIME_CHECK("Precondition failed : ", exp, message)
#define  INVARIANT(exp, message)		RUNTIME_CHECK("Invariant failed : ", exp, message)
#define  POSTCONDITION(exp, message) RUNTIME_CHECK("Poscondition failed : ", exp, message)
#define  ASSERT(exp, message) RUNTIME_CHECK("Assertion failed : ", exp, message)
#else
#define  PRECONDITION(exp, message)	RUNTIME_CHECK("Precondition failed : ", exp, message)
#define  ASSERT(exp, message)
#define  INVARIANT(exp, message)
#define  POSTCONDITION(exp, message)
#endif

#define REAL_EQUALS(a, b) (abs(a-b)<std::numeric_limits<double>::epsilon())



#endif	/* CONTRACT_H */

