#ifndef COMMON_H_
#define COMMON_H_

#define SERIALDATA_SIZE		521

typedef struct 
{
	unsigned char buff[SERIALDATA_SIZE];
	unsigned int index;
} TmpSerialData_Type;

void CCommon1Process(void);

#endif



