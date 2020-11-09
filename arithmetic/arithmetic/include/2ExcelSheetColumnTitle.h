#ifndef _EXCEL_SHEET_COLUMN_TITLE_H
#define _EXCEL_SHEET_COLUMN_TITLE_H

#include "common.h"
#define DLL_EXPORT _declspec(dllexport)
#ifdef __cplusplus
extern "C"{
#endif
	DLL_EXPORT char * ExcelSheetColumnTitle(int n);
#ifdef __cplusplus
}
#endif
#endif