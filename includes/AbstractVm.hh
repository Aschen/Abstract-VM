#ifndef ABSTRACTVM_HH_
# define ABSTRACTVM_HH_

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <sstream>
#include <iomanip>

# define int8	char
# define int16	short
# define int32	int


typedef enum    e_flag
{
    INTERACTIVE = 42,
    NORMAL
}               eFlag;

typedef enum	e_operandType
{
    Int8 = 0,
    Int16,
    Int32,
    Float,
    Double,
    Null
}        		eOperandType;

typedef enum    e_InstrType
{
    PUSH = 0,
    ASSERT,
    POP,
    DUMP,
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    PRINT,
    EXIT
}               eInstrType;

typedef enum    e_TokenType
{
    INSTR = 0,
    VINSTR,
    NTYPE,
    DTYPE,
    NUMBER,
    DECIMAL,
    SEP,
    UNKNOWN
}               eTokenType;

typedef std::pair<eTokenType, std::string>      Token;
typedef std::map<std::string, eTokenType>       TokenMap;

typedef std::pair<eOperandType, std::string>    Value;
typedef std::pair<eInstrType, Value>            Instruction;
typedef std::map<std::string, eOperandType>     TypeMap;
typedef std::map<std::string, eInstrType>       InstructionMap;

typedef std::vector<Token>::const_iterator      TokenCIterator;

# define MAX(x, y) ((x > y) ? (x) : (y))

#endif /* !_ABSTRACTVM_HH_ */
