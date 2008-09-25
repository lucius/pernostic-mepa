#include <iostream>
#include <string>
#include <vector>

#include "../includes/structP.h"



#ifndef MEPA_H_
#define MEPA_H_

enum
{
	crct, crvl, soma, subt, mult, divi, cmig, cmma, cmme, cmag, cmeg, cmdg, conj, disj,
	nega, invr, armz, leit, impr, nada, dsvs, dsvf, inpp, amem, dmem, para, chpr, enpr,
	rtpr, crvi, armi, cren
};

class Mepa
{
	public:
		Mepa( );

		~Mepa( );

	protected:

	private:
		std::vector<structP>
		P;

		std::vector<int>
		M;

		std::vector<int>
		D;

		int
		i;

		int
		s;

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
		DSVS( int );

		void
		DSVF( int );

		void
		INPP( );

		void
		AMEM( int );

		void
		DMEM( int );

		void
		PARA( );

		void
		CHPR( int );

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
