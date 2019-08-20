#include "QXMLParser.h"

/*
 * Author       : Anurag
 * email        : anurag.zxcv@gmail.com
 * File name            : QXMLParser.c
 * File description     : 
 * Version              : 0.1.0
 * Known issues         : Only findes the first occurrence
 * Updates
 *                      created 20th Aug 2019 v0.1.0
*/


int QXMLparse(tXmlParser* sXmlPtr, const char* sKey, char* sValue)
{

/*
 * Author       : Anurag
 * email        : anurag.zxcv@gmail.com
 * Function name                : QXMLparse
 * Function description         : 
 * Parameters                   
 *              sXmlPtr         : Pointer to xml struct
 *              sKey            : The xml tag for which the value is to be found
 *              sValue          : Found value is saved to this location
 * Return
 *                      QXML_ERROR_NO_TAG_FOUND
 *                      QXML_ERROR_NO_STOP_TAG
*/
	char 	eachLine[256];
	char* 	psStartBkmrk 	= NULL;
	char*	psStopBkmrk	= NULL;


	while(fgets(eachLine, sizeof(eachLine), sXmlPtr->fp ))
	{
		if(psStartBkmrk == NULL)
		{
			if( NULL == (psStartBkmrk = strstr(eachLine, sKey)) )
			{
				continue;
			}
		}
		if( (*(psStartBkmrk-1) == '<') && (*(psStartBkmrk + strlen(sKey)) == '>') )
		{
			break;
		}
		psStartBkmrk = NULL;	
	}

	if(psStartBkmrk == NULL)
	{
		return QXML_ERROR_NO_TAG_FOUND;
	}

	if( NULL != (psStopBkmrk = strstr(psStartBkmrk + strlen(sKey) + 1, sKey )) )
	{
		if(  ( *(psStopBkmrk-2) == '<' ) &&
				( *(psStopBkmrk-1) == '/' ) &&
				( *(psStopBkmrk + strlen(sKey)) == '>' ) )
		{
		        psStartBkmrk += (strlen(sKey)+1);
			psStopBkmrk -= 2; 
		}
	}

	if( psStopBkmrk == NULL )
	{
		return QXML_ERROR_NO_STOP_TAG;
	}

	strncpy(sValue, psStartBkmrk, psStopBkmrk - psStartBkmrk);

	return QXML_OK;
}

int QXMLinit( tXmlParser* sXmlPtr, const char* sFileName )
{	
/*
 * Author       : Anurag
 * email        : anurag.zxcv@gmail.com
 * Function name                : QXMLinit
 * Function description         : 
 * Parameters           
 *              sXmlPtr         : Pointer to xml struct
 *              sFileName       : Name of the xml file to parse
 * Return                       
 *                              QXML_OK
 *                              QXML_ERROR_NO_FILE_FOUND
*/
	if(NULL == (sXmlPtr->fp = fopen(sFileName, "r")))
	{
		return QXML_ERROR_NO_FILE_FOUND;
	}	
	return QXML_OK;
}



int QXMLdestroy(tXmlParser* sXmlPtr)
{

/*
 * Author       : Anurag
 * email        : anurag.zxcv@gmail.com
 * Function name                : QXMLdestroy
 * Function description         : 
 * Parameters           
 *              sXmlPtr         : Pointer to xml struct
 * Return                       
 *                              QXML_OK
 *                              QXML_ERROR_NO_FILE_FOUND
*/
	if(EOF == fclose(sXmlPtr->fp))
	{
		return QXML_ERROR_NO_FILE_FOUND;
	}
	return QXML_OK;
}
