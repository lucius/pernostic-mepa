#include <iostream>
#include <string>


#include "./includes/Mepa.h"

int main(int argc, char *argv[])
{
	if ( argc < 2 )
	{
		std::cout << "Numero insuficiente de parametros. " <<
				"Digite 'mepa -?' para a lista completa de opcoes." << std::endl;
		return 0;
	}
	int
	tamD = 10;

	int
	tamP = 50;

	int
	tamM = 20;

	int
	numDoArqEntrada;

	int
	numDoArqSaida = 0;

	Mepa*
	mepa;

	for ( int i = 1; i < argc; i++ )
	{
		if ( argv[i][0] == '-' )
		{
			switch ( argv[i][1] )
			{
				case 'J':
					std::cout << "Opcao nao implementada, foi mal! :)" << std::endl;
					break;

				case 'D':
					i++;
					if ( !(i < argc -1) )
					{
						std::cout << "Numero insuficiente de parametros. " <<
							"Digite 'mepa -?' para a lista completa de opcoes." << std::endl;
						return 0;
					}
					if ( !atoi(argv[i]) )
					{
						std::cout
						<< "O parametro " << i+1 << " precisa ser um numero. " <<
							"Digite 'mepa -?' para a lista completa de opcoes." << std::endl;
						return 0;
					}
					tamD = atoi(argv[i]);
					break;

				case 'P':
					i++;
					if ( !(i < argc -1) )
					{
						std::cout << "Numero insuficiente de parametros. " <<
							"Digite 'mepa -?' para a lista completa de opcoes." << std::endl;
						return 0;
					}
					if ( !atoi(argv[i]) )
					{
						std::cout
						<< "O parametro " << i+1 << " precisa ser um numero. " <<
							"Digite 'mepa -?' para a lista completa de opcoes." << std::endl;
						return 0;
					}
					tamP = atoi(argv[i]);
					break;

				case 'M':
					i++;
					if ( !(i < argc -1) )
					{
						std::cout << "Numero insuficiente de parametros. " <<
							"Digite 'mepa -?' para a lista completa de opcoes." << std::endl;
						return 0;
					}
					if ( !atoi(argv[i]) )
					{
						std::cout
						<< "O parametro " << i+1 << " precisa ser um numero. " <<
							"Digite 'mepa -?' para a lista completa de opcoes." << std::endl;
						return 0;
					}
					tamM = atoi(argv[i]);
					break;

				case '@':
					std::cout
					<< "Pedro de Lari!" << std::endl;
					return 0;

				case 'I':
					std::cout
					<< "Alunos:" << std::endl
					<< '\t' << "Evandro Couto Mantese" << std::endl
					<< '\t' << "Marcus Vinicius Ventura Bortolotti" << std::endl
					<< '\t' << "Rafael de Paula Herrera" << std::endl;
					return 0;

				case '?':
					std::cout
					<< "Uso: mepa [opcoes] arquivo.mep" << std::endl
					<< "Exemplo: mepa -D 5 foo.mep" << std::endl
					<< std::endl
					<< "Opcoes:" << std::endl
					<< "-@" << "\t" << "|o|" << std::endl
					<< "-D n" << "\t" << "Numero n de registradores base" << std::endl
					<< "-P n" << "\t" << "Tamanho n em palavras de 16 bits da memoria de programa" << std::endl
					<< "-M n" << "\t" << "Tamanho n em palavras de 16 bits da memoria de dados" << std::endl
					<< "-I" << "\t" << "Identificacao da equipe" << std::endl
					<< "-?" << "\t" << "Lista completa dos comandos" << std::endl
					<< "-R foo" << "\t" << "Salvar no arquivo foo o resultado da instrucao MOSM. " << std::endl
								<< '\t' << "Caso nao seja utilizado, o resultado e mostrado na saida padrao" << std::endl;

					return 0;

				case 'R':
					i++;
					if ( !(i < argc -1) )
					{
						std::cout << "Numero insuficiente de parametros. " <<
							"Digite 'mepa -?' para a lista completa de opcoes." << std::endl;
						return 0;
					}
					numDoArqSaida = i;
					break;

				default:
					std::cout << "Parametro " << i + 1 << " desconhecido. " <<
							"Digite 'mepa -?' para a lista completa de opcoes." << std::endl;
					return 0;

			}
		}
		else
		{
			if ( 1 )
			{
				if ( argc != i + 1 )
				{
					std::cout << "Numero excedente de parametros. " <<
						"Digite 'mepa -?' para a lista completa de opcoes." << std::endl;
					return 0;
				}

				numDoArqEntrada = i;
			}
			else
			{
				std::cout << "Tipo de arquivo invalido. " <<
					"Digite 'mepa -?' para a lista completa de opcoes." << std::endl;
				return 0;
			}
		}
	}

	if( numDoArqSaida == 0 )
	{
		mepa = new Mepa( argv[numDoArqEntrada], tamD, tamP, tamM );
	}
	else
	{
		mepa = new Mepa( argv[numDoArqEntrada], argv[numDoArqSaida], tamD, tamP, tamM );
	}

	mepa->executa();

	delete mepa;

	return 0;
}
