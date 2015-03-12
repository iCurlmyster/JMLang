#ifndef JMTYPES_H
#define JMTYPES_H

typedef enum JMType {

	JMNull = 0,
	JMError,
	JMArray,
	JMString,
	JMNum,
	JMBool,
	JMFunc,
	JMAssign,
	JMVar,
	JMMethod,
	JMOperation

}JMType;

#endif
