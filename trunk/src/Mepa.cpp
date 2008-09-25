#include "../includes/Mepa.h"



void
Mepa::proximaInstrucao( )
{
	this->i++;
}

void
Mepa::proximaInstrucao( int vNovaPosicao )
{
	this->i = vNovaPosicao;
}

void
Mepa::CRCT( int vK )
{
	s++;
	M[s] = vK;
	proximaInstrucao( );
}

void
Mepa::CRVL( int k, int n )
{
	s++;
	M[s] = M[D[k] + n];
	proximaInstrucao( );
}

void
Mepa::SOMA( )
{
	M[s-1] += M[s];
	s--;
	proximaInstrucao( );
}

void
Mepa::SUBT( )
{
	M[s-1] = M[s-1] - M[s];
	s--;
	proximaInstrucao( );
}

void
Mepa::MULT( )
{
	M[s-1] *= M[s];
	s--;
	proximaInstrucao( );
}

void
Mepa::DIVI( )
{
	M[s-1] = M[s-1] / M[s];
	s--;
	proximaInstrucao( );
}

void
Mepa::CMIG( )
{
	if(M[s-1] == M[s])
	{
		M[s-1] = 1;
	}
	else
	{
		M[s-1] = 0;
	}
	s--;
	proximaInstrucao( );
}

void
Mepa::CMMA( )
{
	if ( M[s-1] > M[s] )
	{
		M[s-1] = 1;
	}
	else
	{
		M[s-1] = 0;
	}
	s--;
	proximaInstrucao( );
}

void
Mepa::CMME( )
{
	if(M[s-1] < M[s])
	{
		M[s-1] = 1;
	}
	else
	{
		M[s-1] = 0;
	}
	s--;
	proximaInstrucao( );
}


void
Mepa::CMAG( )
{
	if ( M[s-1] >= M[s] )
	{
		M[s-1] = 1;
	}
	else
	{
		M[s-1] = 0;
	}
	s--;
	proximaInstrucao( );
}

void
Mepa::CMEG( )
{
	if(M[s-1] <= M[s])
	{
		M[s-1] = 1;
	}
	else
	{
		M[s-1] = 0;
	}
	s--;
	proximaInstrucao( );
}

void
Mepa::CMDG( )
{
	if ( M[s-1] != M[s] )
	{
		M[s-1] = 1;
	}
	else
	{
		M[s-1] = 0;
	}
	s--;
	proximaInstrucao( );
}

void
Mepa::CONJ( )
{
	if ( M[s-1] == 1 && M[s] == 1 )
	{
		M[s-1] = 1;
	}
	else
	{
		M[s-1] = 0;
	}
	s--;
	proximaInstrucao( );
}

void
Mepa::DISJ( )
{
	if(M[s-1] == 1 || M[s] == 1)
	{
		M[s-1] = 1;
	}
	else
	{
		M[s-1] = 0;
	}
	s--;
	proximaInstrucao( );
}

void
Mepa::NEGA( )
{
	M[s] = 1 - M[s];
	proximaInstrucao( );
}

void
Mepa::INVR( )
{
	M[s] = - M[s];
	proximaInstrucao( );
}


void
Mepa::ARMZ( int k, int n )
{
	M[D[k]+n] = M[s];
	s--;
	proximaInstrucao( );
}

void
Mepa::LEIT( )
{
	s++;
	std::cin >> M[s];
	proximaInstrucao( );
}

void
Mepa::IMPR( )
{
	std::cout << M[s];
	s--;
	proximaInstrucao( );
}

void
Mepa::NADA( )
{
	proximaInstrucao( );
}

void
Mepa::DSVS( int p )
{
	proximaInstrucao( p );
}

void
Mepa::DSVF( int p )
{
	if(M[s] == 0)
	{
		proximaInstrucao( p );
	}
	else
	{
		proximaInstrucao( );
	}
	s--;
}

void
Mepa::INPP( )
{
	this->s = -1;
	D[0] = 0;
	proximaInstrucao( );
}

void
Mepa::AMEM( int m )
{
	s += m;
	proximaInstrucao( );
}

void
Mepa::DMEM( int n )
{
	s -= n;
	proximaInstrucao( );
}

void
Mepa::PARA( )
{

}

void
Mepa::CHPR( int L )
{
	s++;
	M[s] = i + 1;
	i = L;
}

void
Mepa::ENPR( int k )
{
	s++;
	M[s] = D[k];
	D[k] = s + 1;
	proximaInstrucao( );
}

void
Mepa::RTPR( int k, int n )
{
	D[k] = M[s];
	i = M[s-1];
	s -= (n+2);
}


void
Mepa::CRVI( int k, int n )
{
	s++;
	M[s] = M[ M[D[k] + n] ];
	proximaInstrucao( );
}

void
Mepa::ARMI( int k, int n )
{
	M[ M[D[k]+n] ] = M[s];
	s--;
	proximaInstrucao( );
}

void
Mepa::CREN( int k, int n )
{
	s++;
	M[s] = D[k] + n;
	proximaInstrucao( );
}
