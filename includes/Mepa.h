#ifndef MEPA_H_
#define MEPA_H_



#define VAZIO -1



#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "../includes/Printer.h"
#include "../includes/structP.h"



enum
{
	crct, crvl, soma, subt, mult, divi, cmig, cmma, cmme, cmag, cmeg, cmdg, conj, disj,
	nega, invr, armz, leit, impr, nada, dsvs, dsvf, inpp, amem, dmem, para, chpr, enpr,
	rtpr, crvi, armi, cren
};



class Mepa
{
	public:
		Mepa( const char*, const char*, int, int, int );

		Mepa( const char*, int, int, int );

		virtual
		~Mepa( );

		void
		executa( );

	protected:
		std::vector<structP>
		P;

		std::vector<int>
		M;

		std::vector<int>
		D;

		std::map<std::string, int>
		labels;

		int
		i;

		int
		s;

		std::ifstream
		mArqEntrada;

		Printer*
		pRelatorio;

		void
		carregaP( );

		void
		proximaInstrucao( );

		void
		proximaInstrucao( int );

		void
		CRCT( int );

		void
		CRVL( int, int );

		void
		SOMA( );

		void
		SUBT( );

		void
		MULT( );

		void
		DIVI( );

		void
		CMIG( );

		void
		CMMA( );

		void
		CMME( );

		void
		CMAG( );

		void
		CMEG( );

		void
		CMDG( );

		void
		CONJ( );

		void
		DISJ( );

		void
		NEGA( );

		void
		INVR( );

		void
		ARMZ( int, int );

		void
		LEIT( );

		void
		IMPR( );

		void
		NADA( );

		void
		DSVS( std::string );

		void
		DSVF( std::string );

		void
		INPP( );

		void
		AMEM( int );

		void
		DMEM( int );

		void
		PARA( );

		void
		CHPR( std::string );

		void
		ENPR( int );

		void
		RTPR( int, int );

		void
		CRVI( int, int );

		void
		ARMI( int, int );

		void
		CREN( int, int );

};

#endif /* MEPA_H_ */
