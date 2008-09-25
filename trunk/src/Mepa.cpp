#include "../includes/Mepa.h"
#include "../includes/structP.h"



Mepa::Mepa( const char* vNomeEntrada, int tamD, int tamP, int tamM )
{
	D.resize(tamD,VAZIO);
	P.resize(tamP);
	M.resize(tamM,VAZIO);

	this->i =  0;
	this->s  = -1;

	std::cout << "boga";
	this->pRelatorio = new Printer( vNomeEntrada );

	/* abre arquivo de entrada */
	this->mArqEntrada.open( vNomeEntrada, std::fstream::in );
	this->mArqEntrada.seekg( 0, std::ios_base::beg );
}

Mepa::Mepa( const char* vNomeEntrada, const char* vNomeSaida, int tamD, int tamP, int tamM )
{
	D.resize(tamD,VAZIO);
	P.resize(tamP);
	M.resize(tamM,VAZIO);

	/* seta ponteiro para nulo */
	this->i =  0;
	this->s = -1;

	this->pRelatorio = new Printer( vNomeEntrada, vNomeSaida );

	/* abre arquivo de entrada */
	this->mArqEntrada.open( vNomeEntrada, std::fstream::in );
	this->mArqEntrada.seekg( 0, std::ios_base::beg );
	// lembrar de passar o nome do arquivo de saida para a classe de imprimir a merda la
}

Mepa::~Mepa()
{
	/* fecha arquivo de entrada */
	this->mArqEntrada.close();

	delete
	this->pRelatorio;
}

void Mepa::executa( )
{
	bool
	Para = false;

	this->carregaP( );

	while( !Para )
	{
		switch ( P[this->i].comando )
		{
			case crct:
				this->CRCT( P[this->i].argumentos[0] );
				break;
			case soma:
				this->SOMA( );
				break;
			case subt:
				this->SUBT( );
				break;
			case mult:
				this->MULT( );
				break;
			case divi:
				this->DIVI( );
				break;
			case invr:
				this->INVR( );
				break;
			case conj:
				this->CONJ( );
				break;
			case disj:
				this->DISJ( );
				break;
			case nega:
				this->NEGA( );
				break;
			case cmme:
				this->CMME( );
				break;
			case cmma:
				this->CMMA( );
				break;
			case cmig:
				this->CMIG( );
				break;
			case cmdg:
				this->CMDG( );
				break;
			case cmeg:
				this->CMEG( );
				break;
			case cmag:
				this->CMAG( );
				break;
			case dsvs:
				this->DSVS( P[this->i].label );
				break;
			case dsvf:
				this->DSVF( P[this->i].label );
				break;
			case nada:
				this->NADA( );
				break;
			case leit:
				this->LEIT( );
				break;
			case impr:
				this->IMPR( );
				break;
			case inpp:
				this->INPP( );
				break;
			case amem:
				this->AMEM( P[this->i].argumentos[0] );
				break;
			case para:
				this->PARA( );
				Para = true;
				break;
			case crvl:
				this->CRVL( P[this->i].argumentos[0], P[this->i].argumentos[1] );
				break;
			case armz:
				this->ARMZ( P[this->i].argumentos[0], P[this->i].argumentos[1] );
				break;
			case chpr:
				this->CHPR( P[this->i].label );
				break;
			case enpr:
				this->ENPR( P[this->i].argumentos[0] );
				break;
			case dmem:
				this->DMEM( P[this->i].argumentos[0] );
				break;
			case rtpr:
				this->RTPR( P[this->i].argumentos[0], P[this->i].argumentos[1] );
				break;
			case crvi:
				this->CRVI( P[this->i].argumentos[0], P[this->i].argumentos[1] );
				break;
			case armi:
				this->ARMI( P[this->i].argumentos[0], P[this->i].argumentos[1] );
				break;
			case cren:
				this->CREN( P[this->i].argumentos[0], P[this->i].argumentos[1] );
				break;
		}
	}
}

void
Mepa::carregaP( )
{
	unsigned int
	linha = 0;

	std::string
	linhaExtraida;

	int
	arg;

	structP
	tempStruct;

	while ( mArqEntrada.good() && linha <= P.size() )
	{
		mArqEntrada >> linhaExtraida;

		std::cout << linhaExtraida;

		if ( linhaExtraida == "AMEM" )
		{
			tempStruct.comando = amem;

			this->mArqEntrada >> arg;
			tempStruct.argumentos.push_back( arg );
		}
		else if ( linhaExtraida == "ARMI" )
		{
			tempStruct.comando = armi;

			this->mArqEntrada >> arg;
			tempStruct.argumentos.push_back( arg );
			this->mArqEntrada >> arg;
			tempStruct.argumentos.push_back( arg );
		}
		else if ( linhaExtraida == "ARMZ" )
		{
			tempStruct.comando = armz;

			this->mArqEntrada >> arg;
			tempStruct.argumentos.push_back( arg );
			this->mArqEntrada >> arg;
			tempStruct.argumentos.push_back( arg );
		}
		else if ( linhaExtraida == "CHPR" )
		{
			tempStruct.comando = chpr;

			this->mArqEntrada >> tempStruct.label;
		}
		else if ( linhaExtraida == "CMAG" )
		{
			tempStruct.comando = cmag;
		}
		else if ( linhaExtraida == "CMDG" )
		{
			tempStruct.comando = cmdg;
		}
		else if ( linhaExtraida == "CMEG" )
		{
			tempStruct.comando = cmeg;
		}
		else if ( linhaExtraida == "CMIG" )
		{
			tempStruct.comando = cmig;
		}
		else if ( linhaExtraida == "CMMA" )
		{
			tempStruct.comando = cmma;
		}
		else if ( linhaExtraida == "CMME" )
		{
			tempStruct.comando = cmme;
		}
		else if ( linhaExtraida == "CONJ" )
		{
			tempStruct.comando = conj;
		}
		else if ( linhaExtraida == "CRCT" )
		{
			tempStruct.comando = crct;

			this->mArqEntrada >> arg;
			tempStruct.argumentos.push_back( arg );
		}
		else if ( linhaExtraida == "CREN" )
		{
			tempStruct.comando = cren;

			this->mArqEntrada >> arg;
			tempStruct.argumentos.push_back( arg );
			this->mArqEntrada >> arg;
			tempStruct.argumentos.push_back( arg );
		}
		else if ( linhaExtraida == "CRVI" )
		{
			tempStruct.comando = crvi;

			this->mArqEntrada >> arg;
			tempStruct.argumentos.push_back( arg );
			this->mArqEntrada >> arg;
			tempStruct.argumentos.push_back( arg );
		}
		else if ( linhaExtraida == "CRVL" )
		{
			tempStruct.comando = crvl;

			this->mArqEntrada >> arg;
			tempStruct.argumentos.push_back( arg );
			this->mArqEntrada >> arg;
			tempStruct.argumentos.push_back( arg );
		}
		else if ( linhaExtraida == "DISJ" )
		{
			tempStruct.comando = disj;
		}
		else if ( linhaExtraida == "DIVI" )
		{
			tempStruct.comando = divi;
		}
		else if ( linhaExtraida == "DMEM" )
		{
			tempStruct.comando = dmem;

			this->mArqEntrada >> arg;
			tempStruct.argumentos.push_back( arg );
		}
		else if ( linhaExtraida == "DSVF" )
		{
			tempStruct.comando = dsvf;

			this->mArqEntrada >> tempStruct.label;
		}
		else if ( linhaExtraida == "DSVS" )
		{
			tempStruct.comando = dsvs;

			this->mArqEntrada >> tempStruct.label;
		}
		else if ( linhaExtraida == "ENPR" )
		{
			tempStruct.comando = enpr;

			mArqEntrada >> arg;
			tempStruct.argumentos.push_back( arg );
		}
		else if ( linhaExtraida == "IMPR" )
		{
			tempStruct.comando = impr;
		}
		else if ( linhaExtraida == "INPP" )
		{
			tempStruct.comando = inpp;
		}
		else if ( linhaExtraida == "INVR" )
		{
			tempStruct.comando = invr;
		}
		else if ( linhaExtraida == "LEIT" )
		{
			tempStruct.comando = leit;
		}
		else if ( linhaExtraida == "MULT" )
		{
			tempStruct.comando = mult;
		}
		else if ( linhaExtraida == "NADA" )
		{
			tempStruct.comando = nada;
		}
		else if ( linhaExtraida == "NEGA" )
		{
			tempStruct.comando = nega;
		}
		else if ( linhaExtraida == "PARA" )
		{
			tempStruct.comando = para;
		}
		else if ( linhaExtraida == "RTPR" )
		{
			tempStruct.comando = rtpr;

			this->mArqEntrada >> arg;
			tempStruct.argumentos.push_back( arg );
			this->mArqEntrada >> arg;
			tempStruct.argumentos.push_back( arg );
		}
		else if ( linhaExtraida == "SOMA" )
		{
			tempStruct.comando = soma;
		}
		else if ( linhaExtraida == "SUBT" )
		{
			tempStruct.comando = subt;
		}
		else
		{
			this->labels[linhaExtraida] = linha;
		}

		P[linha] = tempStruct;
		linha++;

		std::cout << tempStruct.comando;
	}
}

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
	M[s] = M[ D[k] + n ];

	proximaInstrucao( );
}

void
Mepa::SOMA( )
{
	M[s - 1] += M[s];
	s--;

	proximaInstrucao( );
}

void
Mepa::SUBT( )
{
	M[s - 1] = M[s - 1] - M[s];
	s--;

	proximaInstrucao( );
}

void
Mepa::MULT( )
{
	M[s - 1] *= M[s];
	s--;

	proximaInstrucao( );
}

void
Mepa::DIVI( )
{
	M[s - 1] = M[s - 1] / M[s];
	s--;

	proximaInstrucao( );
}

void
Mepa::CMIG( )
{
	if ( M[s - 1] == M[s] )
	{
		M[s - 1] = 1;
	}
	else
	{
		M[s - 1] = 0;
	}
	s--;

	proximaInstrucao( );
}

void
Mepa::CMMA( )
{
	if ( M[s - 1] > M[s] )
	{
		M[s - 1] = 1;
	}
	else
	{
		M[s - 1] = 0;
	}
	s--;

	proximaInstrucao( );
}

void
Mepa::CMME( )
{
	if ( M[s - 1] < M[s] )
	{
		M[s - 1] = 1;
	}
	else
	{
		M[s - 1] = 0;
	}
	s--;

	proximaInstrucao( );
}


void
Mepa::CMAG( )
{
	if ( M[s - 1] >= M[s] )
	{
		M[s - 1] = 1;
	}
	else
	{
		M[s - 1] = 0;
	}
	s--;

	proximaInstrucao( );
}

void
Mepa::CMEG( )
{
	if(M[s - 1] <= M[s])
	{
		M[s - 1] = 1;
	}
	else
	{
		M[s - 1] = 0;
	}
	s--;

	proximaInstrucao( );
}

void
Mepa::CMDG( )
{
	if ( M[s - 1] != M[s] )
	{
		M[s - 1] = 1;
	}
	else
	{
		M[s - 1] = 0;
	}
	s--;

	proximaInstrucao( );
}

void
Mepa::CONJ( )
{
	if ( M[s - 1] == 1 && M[s] == 1 )
	{
		M[s - 1] = 1;
	}
	else
	{
		M[s - 1] = 0;
	}
	s--;

	proximaInstrucao( );
}

void
Mepa::DISJ( )
{
	if(M[s - 1] == 1 || M[s] == 1)
	{
		M[s - 1] = 1;
	}
	else
	{
		M[s - 1] = 0;
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
Mepa::DSVS( std::string label )
{
	proximaInstrucao( this->labels[label] );
}

void
Mepa::DSVF( std::string label )
{
	if(M[s] == 0)
	{
		proximaInstrucao( this->labels[label] );
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
	D[0]    = 0;

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
Mepa::CHPR( std::string label )
{
	s++;
	M[s] = i + 1;
	i = this->labels[label];
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
	i = M[s - 1];
	s -= (n+2);
}


void
Mepa::CRVI( int k, int n )
{
	s++;
	M[s] = M[ M[ D[k] + n ] ];

	proximaInstrucao( );
}

void
Mepa::ARMI( int k, int n )
{
	M[ M[ D[k] + n ] ] = M[s];
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
