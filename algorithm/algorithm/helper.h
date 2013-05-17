#ifndef _HELPER_H_
#define _HELPER_H_

template <typename T>
T** Create2DArray( unsigned int f_inX, unsigned int f_inY )
{
	T           *ptrNew      = NULL;
	T          **ptrReturn   = NULL;
	unsigned int nAllocSize  = 0;
	unsigned int uiIter      = 0;

	nAllocSize = sizeof( T *) * f_inY + f_inY * f_inX * sizeof( T );
	ptrNew     = ( T * )malloc( nAllocSize );
	ptrReturn  = reinterpret_cast< T ** >( ptrNew );
	for( uiIter = 0; uiIter < f_inY; uiIter++ )
	{
		ptrReturn[ uiIter ] = (T *)( (char *)ptrNew + sizeof( T * ) * f_inY + uiIter * f_inX * sizeof( T ) );
	}

	return ptrReturn;
}

#endif