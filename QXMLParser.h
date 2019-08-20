#ifndef _QXML_HEADER_
#define _QXML_HEADER_

#include <string.h>
#include <stdio.h>

typedef struct sXmlParser
{
	FILE *fp;
}tXmlParser;

enum QXML_ERROR
{
	
	QXML_ERROR_NO_FILE_FOUND	= -3,
	QXML_ERROR_NO_STOP_TAG	= -2,
	QXML_ERROR_NO_TAG_FOUND = -1,
	QXML_OK			= 1
};

int QXMLparse(tXmlParser*, const char* , char* );
int QXMLinit( tXmlParser* , const char*  );
int QXMLdestroy(tXmlParser* );


#endif /*_QXML_HEADER_*/
