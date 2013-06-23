#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include "tools/enums.h"
#include "tools/interfaces/identifiable.h"
#include <string>

void warning(EX_CODE);
void warning(unity::tools::interfaces::Identifiable *, EX_CODE);
void warning(std::string, EX_CODE);

void error(EX_CODE);
void error(unity::tools::interfaces::Identifiable *, EX_CODE);
void error(std::string, EX_CODE);

void critical(EX_CODE);
void critical(unity::tools::interfaces::Identifiable *, EX_CODE);
void critical(std::string, EX_CODE);

void fatal(EX_CODE);
void fatal(unity::tools::interfaces::Identifiable *, EX_CODE);
void fatal(std::string, EX_CODE);

#endif // EXCEPTIONS_H
