#include "QXMLParser.h"
#include <stdio.h>

void main()
{
	tXmlParser var;
	char value[32] = {0};	
        int err;

	QXMLinit(&var, "sample.xml");
	if( QXML_OK == (err = QXMLparse(&var, "LINE2", value) ))
	{
		printf("Found: >%s<\n", value);
	}
	else
	{
		printf("not Found!\n");
		printf("Err: %d\n",err);
	}
	if( QXML_OK == (err = QXMLparse(&var, "LINE1", value) ))
	{
		printf("Found: >%s<\n", value);
	}
	else
	{
		printf("not Found!\n");
		printf("Err: %d\n",err);
	}	
	QXMLdestroy(&var);
}
