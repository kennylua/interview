#include "stdafx.h"
#include "leetcode.h"
#include "helper.h"

std::string LongestPalindromeDP(std::string f_inStr )
{
	bool **ptrTable        = NULL;
	unsigned int uiStrLen = 0;
	unsigned int nMax     = 0;
	unsigned int nStart   = 0;
	unsigned int nIteri   = 0;
	unsigned int nIterj   = 0;
	unsigned int nLen     = 0;

	uiStrLen = f_inStr.length();
	ptrTable = Create2DArray<bool>( uiStrLen , uiStrLen );
	for( nIteri = 0; nIteri < uiStrLen; nIteri++ )
	{
		ptrTable[ nIteri ][ nIteri ] = true;
	}
	nStart = 0;
	nMax   = 1;

	for( nIteri = 0, nIterj = 1; nIterj < uiStrLen; nIteri++, nIterj++ )
	{
		if( f_inStr.at( nIteri ) == f_inStr.at( nIterj ) )
		{
			nMax   = 2;
			nStart = nIteri;
			ptrTable[ nIteri ][ nIterj ] = true;
		}
	}

	for( nLen = 2; nLen < uiStrLen; nLen++ )
		for( nIteri = 0; ( nIteri + nLen ) < uiStrLen; nIteri++ )
		{
			nIterj = nIteri + nLen;
			if( f_inStr.at( nIteri ) == f_inStr.at( nIterj) && true == ptrTable[ nIteri ][ nIterj ] )
			{
				nMax = nLen;
				nStart = nIteri;
				ptrTable[ nIteri ][ nIterj ] = true;
			}
		}
	
		return f_inStr.substr( nStart, nMax );
}

bool IsAMatch( const char *f_pstrSrc, const char *f_pstrPattern )
{
	_ASSERT( NULL != f_pstrSrc );
	_ASSERT( NULL != f_pstrPattern );

	if( '\0' == *f_pstrPattern ) return ( '\0' == *f_pstrSrc );


}
