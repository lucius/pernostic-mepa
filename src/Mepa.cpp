#include "../includes/Mepa.h"
#include "../includes/structP.h"



Mepa::Mepa( const char* vNomeEntrada, int tamD, int tamP, int tamM )
{
	D.resize(tamD,VAZIO);
	P.resize(tamP);
	M.resize(tamM,VAZIO);

	this->i =  0;
	this->s  = -1;

	this->pRelatorio = new Printer( vNomeEntrada );

	this->mArqEntrada.open( vNomeEntrada, std::fstream::in );
	this->mArqEntrada.seekg( 0, std::ios_base::beg );
}

Mepa::Mepa( const char* vNomeEntrada, const char* vNomeSaida, int tamD, int tamP, int tamM )
{
	D.resize(tamD,VAZIO);
	P.resize(tamP);
	M.resize(tamM,VAZIO);

	this->i =  0;
	this->s = -1;

	this->pRelatorio = new Printer( vNomeEntrada, vNomeSaida );

	this->mArqEntrada.open( vNomeEntrada, std::fstream::in );
	this->mArqEntrada.seekg( 0, std::ios_base::beg );
}

Mepa::~Mepa()
{
	this->mArqEntrada.close();

	delete this->pRelatorio;
}

void Mepa::executa( )
{
	bool
	Para = false;

	std::string
	teste;

	this->carregaP( );

	while( !Para )
	{
//		std::cout << "*************************************" << std::endl;
//		std::cout << P[this->i].comando << std::endl;
//		std::cout << P[this->i].label << std::endl;
//		std::cout << P[this->i].argumentos[0] << std::endl;
//		std::cout << P[this->i].argumentos[1] << std::endl;
//		std::cout << "*************************************" << std::endl << std::endl;
//
//		std::cin >> teste;
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
	std::cout << std::endl << std::endl << "End ^^" << std::endl;
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

	while ( (this->mArqEntrada.good()) && (linha <= P.size()) )
	{
		linhaExtraida.clear( );

		this->mArqEntrada >> linhaExtraida;

//		std::cout << "*************************************" << std::endl;
//		std::cout << linha+1 << " - " << linhaExtraida << std::endl;

		if ( linhaExtraida == "AMEM" )
		{
			P[linha].comando = amem;

			this->mArqEntrada >> arg;
			P[linha].argumentos.push_back( arg );
		}
		else if ( linhaExtraida == "ARMI" )
		{
			P[linha].comando = armi;

			this->mArqEntrada >> linhaExtraida;
			P[linha].argumentos.push_back( this->convertePrimeiroArgumento( linhaExtraida ) );
			this->mArqEntrada >> arg;
			P[linha].argumentos.push_back( arg );
		}
		else if ( linhaExtraida == "ARMZ" )
		{
			P[linha].comando = armz;

			this->mArqEntrada >> linhaExtraida;
			P[linha].argumentos.push_back( this->convertePrimeiroArgumento( linhaExtraida ) );
			this->mArqEntrada >> arg;
			P[linha].argumentos.push_back( arg );
		}
		else if ( linhaExtraida == "CHPR" )
		{
			P[linha].comando = chpr;

			this->mArqEntrada >> linhaExtraida;
			P[linha].label = linhaExtraida;
		}
		else if ( linhaExtraida == "CMAG" )
		{
			P[linha].comando = cmag;
		}
		else if ( linhaExtraida == "CMDG" )
		{
			P[linha].comando = cmdg;
		}
		else if ( linhaExtraida == "CMEG" )
		{
			P[linha].comando = cmeg;
		}
		else if ( linhaExtraida == "CMIG" )
		{
			P[linha].comando = cmig;
		}
		else if ( linhaExtraida == "CMMA" )
		{
			P[linha].comando = cmma;
		}
		else if ( linhaExtraida == "CMME" )
		{
			P[linha].comando = cmme;
		}
		else if ( linhaExtraida == "CONJ" )
		{
			P[linha].comando = conj;
		}
		else if ( linhaExtraida == "CRCT" )
		{
			P[linha].comando = crct;

			this->mArqEntrada >> arg;
			P[linha].argumentos.push_back( arg );
		}
		else if ( linhaExtraida == "CREN" )
		{
			P[linha].comando = cren;

			this->mArqEntrada >> linhaExtraida;
			P[linha].argumentos.push_back( this->convertePrimeiroArgumento( linhaExtraida ) );
			this->mArqEntrada >> arg;
			P[linha].argumentos.push_back( arg );
		}
		else if ( linhaExtraida == "CRVI" )
		{
			P[linha].comando = crvi;

			this->mArqEntrada >> linhaExtraida;
			P[linha].argumentos.push_back( this->convertePrimeiroArgumento( linhaExtraida ) );
			this->mArqEntrada >> arg;
			P[linha].argumentos.push_back( arg );
		}
		else if ( linhaExtraida == "CRVL" )
		{
			P[linha].comando = crvl;

			this->mArqEntrada >> linhaExtraida;
			P[linha].argumentos.push_back( this->convertePrimeiroArgumento( linhaExtraida ) );
			this->mArqEntrada >> arg;
			P[linha].argumentos.push_back( arg );
		}
		else if ( linhaExtraida == "DISJ" )
		{
			P[linha].comando = disj;
		}
		else if ( linhaExtraida == "DIVI" )
		{
			P[linha].comando = divi;
		}
		else if ( linhaExtraida == "DMEM" )
		{
			P[linha].comando = dmem;

			this->mArqEntrada >> arg;
			P[linha].argumentos.push_back( arg );
		}
		else if ( linhaExtraida == "DSVF" )
		{
			P[linha].comando = dsvf;

			this->mArqEntrada >> linhaExtraida;
			P[linha].label = linhaExtraida;
		}
		else if ( linhaExtraida == "DSVS" )
		{
			P[linha].comando = dsvs;

			this->mArqEntrada >> linhaExtraida;
			P[linha].label = linhaExtraida;
		}
		else if ( linhaExtraida == "ENPR" )
		{
			P[linha].comando = enpr;

			mArqEntrada >> arg;
			P[linha].argumentos.push_back( arg );
		}
		else if ( linhaExtraida == "IMPR" )
		{
			P[linha].comando = impr;
		}
		else if ( linhaExtraida == "INPP" )
		{
			P[linha].comando = inpp;
		}
		else if ( linhaExtraida == "INVR" )
		{
			P[linha].comando = invr;
		}
		else if ( linhaExtraida == "LEIT" )
		{
			P[linha].comando = leit;
		}
		else if ( linhaExtraida == "MULT" )
		{
			P[linha].comando = mult;
		}
		else if ( linhaExtraida == "NADA" )
		{
			P[linha].comando = nada;
		}
		else if ( linhaExtraida == "NEGA" )
		{
			P[linha].comando = nega;
		}
		else if ( linhaExtraida == "PARA" )
		{
			P[linha].comando = para;
		}
		else if ( linhaExtraida == "RTPR" )
		{
			P[linha].comando = rtpr;

			this->mArqEntrada >> linhaExtraida;
			P[linha].argumentos.push_back( this->convertePrimeiroArgumento( linhaExtraida ) );
			this->mArqEntrada >> arg;
			P[linha].argumentos.push_back( arg );
		}
		else if ( linhaExtraida == "SOMA" )
		{
			P[linha].comando = soma;
		}
		else if ( linhaExtraida == "SUBT" )
		{
			P[linha].comando = subt;
		}
		else
		{
			this->labels[linhaExtraida] = linha;
			linha--;
		}

//		std::cout << "-------------------------------------" << std::endl;
//		std::cout << P[linha].comando << std::endl;
//		std::cout << P[linha].label << std::endl;
//		std::cout << P[linha].argumentos[0] << std::endl;
//		std::cout << P[linha].argumentos[1] << std::endl;
//		std::cout << "*************************************" << std::endl << std::endl;

		linha++;
	}
}

const int
Mepa::convertePrimeiroArgumento( std::string vString )
{
	int
	valorInteiro;

	valorInteiro = atoi( vString.substr(0, (vString.size()-1)).c_str() );

	return valorInteiro;
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

	this->proximaInstrucao( );
}

void
Mepa::SOMA( )
{
	M[s - 1] += M[s];
	s--;

	this->proximaInstrucao( );
}

void
Mepa::SUBT( )
{
	M[s - 1] = M[s - 1] - M[s];
	s--;

	this->proximaInstrucao( );
}

void
Mepa::MULT( )
{
	M[s - 1] *= M[s];
	s--;

	this->proximaInstrucao( );
}

void
Mepa::DIVI( )
{
	M[s - 1] = M[s - 1] / M[s];
	s--;

	this->proximaInstrucao( );
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

	this->proximaInstrucao( );
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

	this->proximaInstrucao( );
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

	this->proximaInstrucao( );
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

	this->proximaInstrucao( );
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

	this->proximaInstrucao( );
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

	this->proximaInstrucao( );
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

	this->proximaInstrucao( );
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

	this->proximaInstrucao( );
}

void
Mepa::NEGA( )
{
	M[s] = 1 - M[s];

	this->proximaInstrucao( );
}

void
Mepa::INVR( )
{
	M[s] = - M[s];

	this->proximaInstrucao( );
}


void
Mepa::ARMZ( int k, int n )
{
	M[D[k]+n] = M[s];
	s--;

	this->proximaInstrucao( );
}

void
Mepa::LEIT( )
{
	s++;
	std::cin >> M[s];

	this->proximaInstrucao( );
}

void
Mepa::IMPR( )
{
	std::cout << M[s];
	s--;

	this->proximaInstrucao( );
}

void
Mepa::NADA( )
{
	this->proximaInstrucao( );
}

void
Mepa::DSVS( std::string label )
{
	this->proximaInstrucao( this->labels[label] );
}

void
Mepa::DSVF( std::string label )
{
	if(M[s] == 0)
	{
		this->proximaInstrucao( this->labels[label] );
	}
	else
	{
		this->proximaInstrucao( );
	}
	s--;
}

void
Mepa::INPP( )
{
	this->s = -1;
	D[0]    = 0;

	this->proximaInstrucao( );
}

void
Mepa::AMEM( int m )
{
	s += m;

	this->proximaInstrucao( );
}

void
Mepa::DMEM( int n )
{
	s -= n;

	this->proximaInstrucao( );
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

	this->proximaInstrucao( );
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

	this->proximaInstrucao( );
}

void
Mepa::ARMI( int k, int n )
{
	M[ M[ D[k] + n ] ] = M[s];
	s--;

	this->proximaInstrucao( );
}

void
Mepa::CREN( int k, int n )
{
	s++;
	M[s] = D[k] + n;

	this->proximaInstrucao( );
}
