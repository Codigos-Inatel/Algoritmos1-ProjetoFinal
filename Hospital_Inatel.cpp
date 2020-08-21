#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <fstream>
#include <windows.h>

using namespace std;

fstream arquivo;
fstream arquivo2;

struct cad
{
	char nome[100],
		 tel[50],
		 opCadPac,
		 nomeEnd[100],
		 sexo,
		 bairroEnd[50];


	int idade,
		dia,
		mes,
		ano,
		id,
		numEnd,
		contPac;


	bool excluido;

} paciente;

struct atendimento
{
	char
	diag[200], retorno_cons;
	int
	dia_cons,
	ID,
	mes_cons,
	ano_cons,
	dia_ret,
	mes_ret,
	ano_ret,
	pulseira;
	float
	contRed,
	contOrange,
	contYellow,
	contGreen,
	contBlue,
	contTOTAL;

	bool excluido_atend;

} atend ;


bool verificanome( char nome[])
{
	bool respNome = false;
	int tam ;

	tam = strlen(nome);

	for ( int i = 0; i < tam ; i++)
	{
		if ( isdigit(nome[i]))
			respNome = true;
	}

	return respNome ;

}

bool verificatel ( char tel[] )
{
	bool respTel = false;
	int tam;

	tam = strlen (tel);

	if ( tam == 9 && tel[0] == '9')
	{
		for ( int i = 0 ; i < tam ; i++)
		{
			if ( isdigit(tel[i]) == 0)
				respTel = true;
		}

	}

	else
	{
		respTel = true;
	}

	return respTel;
}


void CadPaciente ()
{
	char opCadPac, resp;

	system("cls");

	do
	{
		system("cls");

		cout << "\t\t|************************************************|" << endl;
		cout << "\t\t|*                                              *|" << endl;
		cout << "\t\t|*             Hospital Inatel                  *|" << endl;
		cout << "\t\t|*                                              *|" << endl;
		cout << "\t\t|*       Seção de Cadastro de Paciente          *|" << endl;
		cout << "\t\t|*                                              *|" << endl;
		cout << "\t\t ************************************************" << endl;

		cout << endl << endl ;

		cin.ignore();
		do
		{
			cout << "Nome: " ;
			cin.getline(paciente.nome, 150);
			cout << endl;
		}
		while ( verificanome (paciente.nome));

		do
		{
			cout << " Sexo(F ou M): " ;
			cin >> paciente.sexo;
			paciente.sexo = towupper (paciente.sexo);

		}
		while (paciente.sexo != 'F' && paciente.sexo != 'M' );

		cout << endl;
		do
		{
			cout << "O paciente é menor de um ano?(S ou N): " ;
			cin >> resp ;
			resp = towupper(resp);
		}
		while ( resp != 'S' && resp != 'N' );

		cout << endl;

		if ( resp == 'S' || resp == 's' )
		{
			do
			{
				cout << "Quantos meses a criança tem? " << endl;
				cin >> paciente.idade;
			}
			while( paciente.idade <= 0 || paciente.idade > 11);
		}

		else
		{
			do
			{
				cout << "Idade: ";
				cin >> paciente.idade;
			}
			while ( paciente.idade <= 0 || paciente.idade > 115);
		}

		cin.ignore();
		cout << endl;
		do
		{
			cout << "Data de nascimento: " ;
			cin >> paciente.dia >> paciente.mes >> paciente.ano;
		}
		while ( paciente.dia < 0 || paciente.dia > 31 || paciente.mes < 0 || paciente.mes > 12 || paciente.ano < 1897 || paciente.ano > 2017 );

		cin.ignore();
		cout << endl;
		cout << "Endereco: ";
		cin.getline ( paciente.nomeEnd, 100);
		do
		{
			cout << "Número: ";
			cin >> paciente.numEnd;
		}
		while ( paciente.numEnd < 0 );
		cout << "Bairro: " ;
		cin.ignore();
		cin.getline (paciente.bairroEnd, 50);
		cout << endl;

		do
		{
			cout << "Telefone: ";
			cin.getline ( paciente.tel, 50);

		}
		while ( verificatel(paciente.tel)) ;

		cout << endl;

		do
		{

			cout << "Número do cadastro do paciente: " ;
			cin >> paciente.id;
			cout << endl;

		}
		while ( paciente.id < 0 );

		paciente.excluido = false ;
		arquivo.seekp (0, arquivo.end);
		arquivo.write ( ( char *) &paciente, sizeof(paciente));

		do
		{
			cout << "Deseja realizar novo cadastro de paciente?(S ou N)" << endl;
			cin >> opCadPac;
			opCadPac = towupper(opCadPac);

		}
		while ( opCadPac == 'S' && opCadPac == 'N' ) ;

	}
	while ( opCadPac != 'N');
}

void atendimento ()
{
	char opAtend;

	system ( "cls");


	do
	{
		system ("cls");

		cout << "\t\t|************************************************|" << endl;
		cout << "\t\t|*                                              *|" << endl;
		cout << "\t\t|*             Hospital Inatel                  *|" << endl;
		cout << "\t\t|*                                              *|" << endl;
		cout << "\t\t|*      Seção de Cadastro de Atendimento        *|" << endl;
		cout << "\t\t|*                                              *|" << endl;
		cout << "\t\t ************************************************" << endl;

		cout << endl << endl << endl;

		cout << "\t\t|************************************************|" << endl;
		cout << "\t\t|*                                              *|" << endl;
		cout << "\t\t|*      Quadro de Gravidade do Paciente:        *|" << endl;
		cout << "\t\t|*                                              *|" << endl;
		cout << "\t\t|*             1 - Vermelho                     *|" << endl;
		cout << "\t\t|*             2 - Laranja                      *|" << endl;
		cout << "\t\t|*             3 - Amarelo                      *|" << endl;
		cout << "\t\t|*             4 - Verde                        *|" << endl;
		cout << "\t\t|*             5 - Azul                         *|" << endl;
		cout << "\t\t|*                                              *|" << endl;
		cout << "\t\t|*                                              *|" << endl;
		cout << "\t\t ************************************************" << endl;

		cout << endl << endl << endl;


		cout << "Qual o número de cadastro do paciente?" << endl << " ID = " ;
		cin >> atend.ID;

		cout << endl;

		cin.ignore();

		do
		{
			cout << "Pulseira recebida: " ;
			cin >> atend.pulseira;

		}
		while (atend.pulseira < 1 && atend.pulseira > 6);

		switch (atend.pulseira)
		{
		case (1):
			atend.contRed++;
			break;
		case (2):
			atend.contOrange++;
			break;
		case (3):
			atend.contYellow++;
			break;
		case (4):
			atend.contGreen++;
			break;
		case (5):
			atend.contBlue++;
			break;

		}
		atend.contTOTAL++;
		cin.ignore();

		cout << endl;
		cout << "Diagnóstico final: ";
		cin.getline(atend.diag, 200);

		cout << endl;

		do
		{
			cout << "Data: " ;
			cin >> atend.dia_cons ;
			cin >> atend.mes_cons;
			cin >> atend.ano_cons;
		}
		while (atend.dia_cons < 0 || atend.dia_cons > 31 || atend.mes_cons < 0 || atend.mes_cons > 12 ||  atend.ano_cons < 2017);

		cout << endl;

		do
		{
			cout << "O paciente marcou retorno? " << endl;
			cin >> atend.retorno_cons;
			atend.retorno_cons = towupper(atend.retorno_cons);
		}
		while ( atend.retorno_cons != 'S' && atend.retorno_cons != 'N') ;

		if(atend.retorno_cons == 'S' )
		{
			cout << endl;
			do
			{
				cout << "Qual a data do retorno? " << endl;
				cin >> atend.dia_ret >> atend.mes_ret >> atend.ano_ret;
			}
			while ( atend.dia_ret < 0 || atend.dia_ret > 31 || atend.mes_ret < 0 || atend.mes_ret > 12 ||  atend.ano_ret < 2017 );
		}


		atend.excluido_atend = false;
		arquivo2.seekp (0, arquivo2.end);
		arquivo2.write ( ( char*)&atend, sizeof(atend));

		cout << endl;
		do
		{
			cout << "Deseja realizar novo cadastro de atendimento?(S ou N)" << endl;
			cin >> opAtend;
			opAtend = towupper(opAtend);

		}
		while ( opAtend == 'S' && opAtend == 'N' ) ;

	}
	while (opAtend != 'N');
}


void pesquisar ()
{
	system ( "cls" );
	char opPesq ;
	int id, op_pesq;
	bool encontradoPac = false , encontradoAtend = false ;


	do
	{
		cout << "\t\t|************************************************|" << endl;
		cout << "\t\t|*                                              *|" << endl;
		cout << "\t\t|*             Hospital Inatel                  *|" << endl;
		cout << "\t\t|*                                              *|" << endl;
		cout << "\t\t|*             Seção de Pesquisa                *|" << endl;
		cout << "\t\t|*                                              *|" << endl;
		cout << "\t\t ************************************************" << endl;

		cout << endl << endl << endl;


		cout << "\t\t|************************************************|" << endl;
		cout << "\t\t|*                                              *|" << endl;
		cout << "\t\t|*              Pesquisar:                      *|" << endl;
		cout << "\t\t|*                                              *|" << endl;
		cout << "\t\t|*          1 - Paciente                        *|" << endl;
		cout << "\t\t|*          2 - Atendimento                     *|" << endl;
		cout << "\t\t|*                                              *|" << endl;
		cout << "\t\t ************************************************" << endl;
		cout << endl;
		cout << "\t\t               Escolha uma opção: ";
		cin >> op_pesq;



	}
	while ( op_pesq < 1 && op_pesq > 2 );


	if ( op_pesq == 1)
	{

		do
		{
			system("cls");
			cout << endl;
			cout << "\tPESQUISAR PACIENTE" << endl << endl;

			cout << "Entre com o numero do paciente: "  ;
			cin >> id;
			cout << endl;

			arquivo.seekg( 0, arquivo.beg);

			while ( !arquivo.eof())
			{
				arquivo.read( (char *) &paciente, sizeof(paciente)) ;

				if ( !arquivo.eof() && id == paciente.id && !paciente.excluido)
				{
					cout << " Nome: " << paciente.nome << endl;
					cout << " Sexo: " << paciente.sexo << endl;
					if(paciente.idade >= 1)
					{
						cout << " Idade: " << paciente.idade << " ano(s)" << endl;
					}
					else
					{
						cout << " Idade: " << paciente.idade << " meses " << endl;
					}

					cout << " Data de Nascimento: " << paciente.dia << "/" << paciente.mes << "/" << paciente.ano << endl;
					cout << " Telefone: " << paciente.tel << endl;
					cout << " Endereço: " << paciente.nomeEnd << " Nº: " <<  paciente.numEnd << " Bairro: " << paciente.bairroEnd << endl;

					encontradoPac = true;
				}
				

			}

			cout << endl;
			arquivo.clear();
			if ( !encontradoPac )
			{
				cout << "Paciente não encontrado" << endl;
			}
			
			do
			{
				cout << "Deseja realizar nova pesquisa de paciente? (S ou N) " << endl;
				cin >> opPesq;
				opPesq = towupper(opPesq);

			}
			while ( opPesq == 'S' && opPesq == 'N' ) ;


		}
		while (opPesq != 'N' ) ;

		cout << endl;
		cout << "Em execução ..." << endl;
		system ( "pause");
	}

	if ( op_pesq == 2)
	{
		do
		{
			system("cls");
			cout << endl;
			cout << "\tPESQUISAR ATENDIMENTO" << endl << endl;

			cout << "Entre com o numero do atendimento: "  ;
			cin >> id;
			cout << endl;

			arquivo2.seekg( 0, arquivo2.beg);

			while ( !arquivo2.eof())
			{
				arquivo2.read( (char *) &atend, sizeof(atend)) ;

				if ( !arquivo2.eof() && id == atend.ID && !atend.excluido_atend)
				{

					cout << " Número do Atendimento: " << atend.ID << endl;
					cout << " Pulseira recebida: " << atend.pulseira << endl;
					cout << " Diagnóstico: " << atend.diag << endl;
					cout << " Dia da Consulta: " << atend.dia_cons << "/" <<  atend.mes_cons << "/" << atend.ano_cons << endl;
					if(atend.retorno_cons == 'S' )
						cout << " Dia do Retorno: " << atend.dia_ret << "/" <<   atend.mes_ret <<  "/" <<  atend.ano_ret << endl;
					else
						cout << "Sem retorno" << endl;

					system ("pause");
					encontradoAtend = true;
				}
			}

			cout << endl;
			arquivo2.clear();

			if ( !encontradoAtend)
			{
				cout << "Atendimento não encontrado" << endl;
			}

			do
			{
				cout << "Deseja realizar nova pesquisa de atendimento? (S ou N)" << endl;
				cin >> opPesq;
				opPesq = towupper(opPesq);

			}
			while ( opPesq == 'S' && opPesq == 'N' ) ;


		}
		while (opPesq != 'N' ) ;

		cout << endl;
		cout << " Em execução..." << endl;
		system ( "pause");

	}

	return;

}

void listarCod()
{
	int op_listarCod;
	system ( "cls" );

	cout << "\t\t|************************************************|" << endl;
	cout << "\t\t|*                                              *|" << endl;
	cout << "\t\t|*             Hospital Inatel                  *|" << endl;
	cout << "\t\t|*                                              *|" << endl;
	cout << "\t\t|*   Seção de Listagem de Número de Cadastro    *|" << endl;
	cout << "\t\t|*                                              *|" << endl;
	cout << "\t\t ************************************************" << endl;

	cout << endl << endl << endl;

	arquivo.seekg(0, arquivo.beg);

	while (arquivo.read((char*)&paciente, sizeof(paciente)))
	{
		if (!arquivo.eof() &&  !paciente.excluido)
		{
			cout << endl << "Número de Cadastro:  " << paciente.id <<  "   Nome: " << paciente.nome << endl;
		}
	}

	cout << endl;
	system("pause");

}

void  listar()
{
	int op_listar;
	system ( "cls" );

	do
	{
		cout << "\t\t|************************************************|" << endl;
		cout << "\t\t|*                                              *|" << endl;
		cout << "\t\t|*             Hospital Inatel                  *|" << endl;
		cout << "\t\t|*                                              *|" << endl;
		cout << "\t\t|*            Seção de Listagem                 *|" << endl;
		cout << "\t\t|*                                              *|" << endl;
		cout << "\t\t ************************************************" << endl;

		cout << endl << endl << endl;

		cout << "\t\t|************************************************|" << endl;
		cout << "\t\t|*                                              *|" << endl;
		cout << "\t\t|*              Listar:                         *|" << endl;
		cout << "\t\t|*                                              *|" << endl;
		cout << "\t\t|*          1 - Paciente                        *|" << endl;
		cout << "\t\t|*          2 - Atendimento                     *|" << endl;
		cout << "\t\t|*                                              *|" << endl;
		cout << "\t\t ************************************************" << endl;
		cout << endl;
		cout << "\t\t               Escolha uma opção: ";
		cin >> op_listar;

	}
	while ( op_listar < 1 && op_listar > 2 );


	if ( op_listar == 1)
	{
		system("cls");

		cout << endl;
		cout << "\tLISTA DE PACIENTES" << endl << endl;

		arquivo.seekg(0, arquivo.beg);
		while (arquivo.read ((char*) &paciente, sizeof(paciente)) )
		{
			if (!arquivo.eof() &&  !paciente.excluido)
			{
				cout << " Número do Paciente: "  << paciente.id << endl;
				cout << " Nome: " << paciente.nome << endl;
				cout << " Sexo: " << paciente.sexo << endl;
				if(paciente.idade >= 1)
				{
					cout << " Idade: " << paciente.idade << " ano(s)" << endl;
				}
				else
				{
					cout << " Idade: " << paciente.idade << " meses " << endl;
				}

				cout << " Data de Nascimento: " << paciente.dia << "/" << paciente.mes << "/" << paciente.ano << endl;
				cout << " Telefone: " << paciente.tel << endl;
				cout << " Endereço: " << paciente.nomeEnd << " Nº: " <<  paciente.numEnd << " Bairro: " << paciente.bairroEnd << endl;

				cout << endl << endl;

			}
		}

		arquivo.clear();
		system ("pause");


	}
	if ( op_listar == 2)
	{
		system ("cls");

		cout << endl;
		cout << "\tLISTA DE ATENDIMENTOS" << endl << endl;

		arquivo2.seekg(0, arquivo2.beg);
		while (arquivo2.read ((char*) &atend, sizeof(atend)) )
		{
			if (!arquivo2.eof() &&  !atend.excluido_atend)
			{
				cout << " Número do Atendimento: " << atend.ID << endl;
				cout << " Pulseira recebida: " << atend.pulseira << endl;
				cout << " Diagnóstico : " << atend.diag << endl;
				if(atend.retorno_cons == 'S' )
					cout << " Dia do Retorno : " << atend.dia_ret << " / " <<   atend.mes_ret <<  " / " <<  atend.ano_ret << endl;

			}

			else
				cout << "Sem retorno" << endl;

			cout << endl << endl;
		}

	}
	arquivo2.clear();
	system ("pause");

}


void editar ()
{
	system("cls");
	int op_editar, opEdPac, id;
	char resp;

	do
	{
		cout << "\t\t|************************************************|" << endl;
		cout << "\t\t|*                                              *|" << endl;
		cout << "\t\t|*             Hospital Inatel                  *|" << endl;
		cout << "\t\t|*                                              *|" << endl;
		cout << "\t\t|*             Seção de Edição                  *|" << endl;
		cout << "\t\t|*                                              *|" << endl;
		cout << "\t\t ************************************************" << endl;

		cout << endl << endl << endl;

		cout << "\t\t|************************************************|" << endl;
		cout << "\t\t|*                                              *|" << endl;
		cout << "\t\t|*              Editar:                         *|" << endl;
		cout << "\t\t|*                                              *|" << endl;
		cout << "\t\t|*          1 - Paciente                        *|" << endl;
		cout << "\t\t|*          2 - Atendimento                     *|" << endl;
		cout << "\t\t|*                                              *|" << endl;
		cout << "\t\t ************************************************" << endl;
		cout << endl;
		cout << "\t\t               Escolha uma opção: ";
		cin >> op_editar;

	}
	while ( op_editar < 1 && op_editar > 2 );

	if ( op_editar == 1)
	{
		system ("cls");
		cout << endl;
		cout << "\tEDITAR CADASTRO PACIENTE" << endl << endl;

		do
		{
			cout << "Entre com o numero do paciente: ";
			cin >> id;
		}
		while ( id < 0);
		cout << endl;

		arquivo.seekg(0, arquivo.beg);
		arquivo.read((char *) &paciente, sizeof(paciente));

		while (arquivo.read ((char*) &paciente, sizeof(paciente)) )
		{
			if (!arquivo.eof() && id == paciente.id && !paciente.excluido)
			{
				cin.ignore();
				do
				{
					cout << "Nome: " ;
					cin.getline(paciente.nome, 150);
					cout << endl;
				}
				while ( verificanome (paciente.nome));

				do
				{
					cout << "Sexo(F ou M): " ;
					cin >> paciente.sexo;
					paciente.sexo = towupper (paciente.sexo);
					cout << endl;

				}
				while (paciente.sexo != 'F' && paciente.sexo != 'M' );

				do
				{
					cout << "O paciente é menor de um ano? (S ou N): " ;
					cin >> resp ;
					resp = towupper(resp);
				}
				while ( resp != 'S' && resp != 'N' );

				cout << endl;

				if ( resp == 'S' || resp == 's' )
				{
					do
					{
						cout << "Quantos meses a criança tem? " << endl;
						cin >> paciente.idade;
					}
					while( paciente.idade <= 0 || paciente.idade > 11);
				}
				else
				{
					do
					{
						cout << "Idade: ";
						cin >> paciente.idade;
					}
					while ( paciente.idade <= 0 || paciente.idade > 115);
				}

				cin.ignore();
				cout << endl;

				do
				{
					cout << "Data de nascimento: " ;
					cin >> paciente.dia >> paciente.mes >> paciente.ano;
				}
				while ( paciente.dia < 0 || paciente.dia > 31 || paciente.mes < 0 || paciente.mes > 12 || paciente.ano < 1897 || paciente.ano > 2017 );

				cin.ignore();
				cout << endl;
				cout << "Endereco: ";
				cin.getline ( paciente.nomeEnd, 100);
				do
				{
					cout << "Número: ";
					cin >> paciente.numEnd;
				}
				while ( paciente.numEnd < 0 );
				cout << "Bairro: " ;
				cin.ignore();
				cin.getline (paciente.bairroEnd, 50);
				cout << endl;

				do
				{
					cout << "Telefone: ";
					cin.getline ( paciente.tel, 50);

				}
				while ( verificatel(paciente.tel)) ;

				cout << endl;

				paciente.excluido = false ;

				arquivo.seekp(arquivo.tellp() - sizeof(paciente), arquivo.beg);
				arquivo.write((char *) &paciente, sizeof(paciente));
			}
		}

		if (!paciente.excluido)
		{
			cout << "Paciente não encontrado" << endl ;

		}

	}

	if ( op_editar == 2)
	{
		system ("cls");
		cout << endl;
		cout << "\tEDITAR CADASTRO ATENDIMENTO" << endl << endl;

		do
		{
			cout << "Entre com o numero do paciente: ";
			cin >> id;
		}
		while ( id < 0);

		cout << endl;

		arquivo2.seekg(0, arquivo2.beg);
		arquivo2.read((char *) &atend, sizeof(atend));

		while (arquivo2.read ((char*) &atend, sizeof(atend)) )
		{
			if (!arquivo2.eof() && id == atend.ID && !atend.excluido_atend)
			{
				char opAtend;

				system ( "cls");

				cin.ignore();

				cout << "Diagnóstico final : ";
				cin.getline(atend.diag, 200);

				cout << endl;

				do
				{
					cout << "Data: " ;
					cin >> atend.dia_cons ;
					cin >> atend.mes_cons;
					cin >> atend.ano_cons;
				}
				while (atend.dia_cons < 0 || atend.dia_cons > 31 || atend.mes_cons < 0 || atend.mes_cons > 12 ||  atend.ano_cons < 2017);

				cout << endl;

				do
				{
					cout << "O paciente marcou retorno? " << endl;
					cin >> atend.retorno_cons;
					atend.retorno_cons = towupper(atend.retorno_cons);
				}
				while ( atend.retorno_cons != 'S' && atend.retorno_cons != 'N') ;

				if(atend.retorno_cons == 'S' )
				{
					cout << endl;
					do
					{
						cout << "Qual a data do retorno? " << endl;
						cin >> atend.dia_ret >> atend.mes_ret >> atend.ano_ret;
					}
					while ( atend.dia_ret < 0 || atend.dia_ret > 31 || atend.mes_ret < 0 || atend.mes_ret > 12 ||  atend.ano_ret < 2017 );
				}


				atend.excluido_atend = false;

				arquivo2.seekp(arquivo2.tellp() - sizeof(atend), arquivo2.beg);
				arquivo2.write((char *) &atend, sizeof(atend));


			}
		}

		if (!atend.excluido_atend)
		{
			cout << "Atendimento não encontrado" << endl ;

		}


	}
}



void excluir ()
{

	system("cls");
	int op_excluir, id;

	do
	{
		cout << "\t\t|************************************************|" << endl;
		cout << "\t\t|*                                              *|" << endl;
		cout << "\t\t|*             Hospital Inatel                  *|" << endl;
		cout << "\t\t|*                                              *|" << endl;
		cout << "\t\t|*             Seção de Exclusão                *|" << endl;
		cout << "\t\t|*                                              *|" << endl;
		cout << "\t\t ************************************************" << endl;

		cout << endl << endl << endl;


		cout << "\t\t|************************************************|" << endl;
		cout << "\t\t|*                                              *|" << endl;
		cout << "\t\t|*              Excluir:                         *|" << endl;
		cout << "\t\t|*                                              *|" << endl;
		cout << "\t\t|*          1 - Paciente                        *|" << endl;
		cout << "\t\t|*          2 - Atendimento                     *|" << endl;
		cout << "\t\t|*                                              *|" << endl;
		cout << "\t\t ************************************************" << endl;
		cout << endl;
		cout << "\t\t               Escolha uma opção: ";
		cin >> op_excluir;

	}
	while ( op_excluir < 1 && op_excluir > 2 );


	if ( op_excluir == 1)
	{

		system ("cls");

		cout << endl;
		cout << "\tEXCLUIR CADASTRO DE PACIENTE" << endl << endl;

		cout << "Entre com o numero do paciente: ";
		cin >> id;
		cout << endl;

		arquivo.seekg(0, arquivo.beg);
		arquivo.read((char *) &paciente, sizeof(paciente));

		while (arquivo.read ((char*) &paciente, sizeof(paciente)) )
		{

			if (!arquivo.eof() && id == paciente.id && !paciente.excluido)
			{

				paciente.excluido = true;

				cout << " Cadastro excluído com sucesso " << endl ;

				system ("pause");

				arquivo.seekp(arquivo.tellp() - sizeof(paciente), arquivo.beg);
				arquivo.write((char *) &paciente, sizeof(paciente));
			}
		}

		arquivo2.clear();
		system ("pause");

	}

	if ( op_excluir == 2)
	{
		system ( "cls");

		cout << endl;
		cout << "\tEXCLUIR CADASTRO DE ATENDIMENTO" << endl << endl;

		cout << "Entre com o numero do paciente: ";
		cin >> id;
		cout << endl;

		arquivo2.seekg(0, arquivo2.beg);
		arquivo2.read((char *) &atend, sizeof(atend));

		while (arquivo2.read ((char*) &atend, sizeof(atend)) )
		{
			if (!arquivo2.eof() && id == atend.ID && !atend.excluido_atend)
			{

				atend.excluido_atend = true;

				cout << " Atendimento excluido com sucesso " << endl;

				system( "pause");

				arquivo2.seekp(arquivo2.tellp() - sizeof(atend), arquivo2.beg);
				arquivo2.write((char *) &atend, sizeof(atend));

			}
		}

		arquivo2.clear();
		system ("pause");
	}

}

void extra()
{
	system ("cls");

	cout << "\t\t|************************************************|" << endl;
	cout << "\t\t|*                                              *|" << endl;
	cout << "\t\t|*             Hospital Inatel                  *|" << endl;
	cout << "\t\t|*                                              *|" << endl;
	cout << "\t\t|*           Seção de Estatística               *|" << endl;
	cout << "\t\t|*                                              *|" << endl;
	cout << "\t\t ************************************************" << endl;

	cout << endl << endl << endl;


	float calcRed, calcOrange, calcYellow, calcGreen, calcBlue;

	calcRed = (atend.contRed / atend.contTOTAL) * 100 ;

	calcOrange = (atend.contOrange / atend.contTOTAL) * 100 ;

	calcYellow = (atend.contYellow / atend.contTOTAL) * 100 ;

	calcGreen = (atend.contGreen / atend.contTOTAL) * 100 ;

	calcBlue = (atend.contBlue / atend.contTOTAL) * 100 ;

	cout << fixed << setprecision(2) << "\t Porcentagem de uso de cada pulseira : " << endl << endl;
	cout << fixed << setprecision(2) << " Vermelha = " << calcRed << "%" << endl;
	cout << fixed << setprecision(2) << " Laranja  = " << calcOrange << "%" << endl;
	cout << fixed << setprecision(2) << " Amarelo  = " << calcYellow << "%" << endl;
	cout << fixed << setprecision(2) << " Verde    = " << calcGreen << "%" << endl;
	cout << fixed << setprecision(2) << " Azul     = " << calcBlue << "%" << endl;

	system ("pause");

}

void sair()
{
	system("cls");
	cout << endl;
	cout << " Criado por Vanessa Swerts e Karyn Talyne" << endl;

}

int main ()
{

	setlocale(LC_ALL, "Portuguese");


	arquivo.open ("hospital.txt", ios::in | ios::out | ios::binary  );

	if (!arquivo.is_open())
	{
		arquivo.open ("hospital.txt", ios::in | ios::trunc | ios::out | ios::binary  );
		cout << "Erro no banco de dados!" << endl;

	}


	arquivo2.open ( "atendimento.txt", ios::in | ios::out | ios::binary );

	if (!arquivo2.is_open())
	{
		arquivo2.open ("atendimento.txt", ios::in | ios::trunc | ios::out | ios::binary );

	}

	int op_menu;

	while ( op_menu != 0)
	{
		do
		{
			system("cls");
			system("color f0");
			cout << "\t\t | ************************************************ | " << endl;
			cout << "\t\t | *                                              * | " << endl;
			cout << "\t\t | *              SEJA BEM VINDO!                 * | " << endl;
			cout << "\t\t | *                                              * | " << endl;
			cout << "\t\t | *              Hospital Inatel                 * | " << endl;
			cout << "\t\t | *                                              * | " << endl;
			cout << "\t\t | *---------------------Menu---------------------* | " << endl;
			cout << "\t\t | *                                              * | " << endl;
			cout << "\t\t | *          1 - Cadastrar                       * | " << endl;
			cout << "\t\t | *          2 - Atendimento                     * | " << endl;
			cout << "\t\t | *          3 - Listar Número de Cadastro       * | " << endl;
			cout << "\t\t | *          4 - Listar                          * | " << endl;
			cout << "\t\t | *          5 - Pesquisar                       * | " << endl;
			cout << "\t\t | *          6 - Editar                          * | " << endl;
			cout << "\t\t | *          7 - Excluir                         * | " << endl;
			cout << "\t\t | *          8 - Extra                           * | " << endl;
			cout << "\t\t | *          0 - Sair                            * | " << endl;
			cout << "\t\t | *                                              * | " << endl;
			cout << "\t\t  ************************************************   " << endl;
			cout << endl;
			cout << "\t\t               Escolha uma opção : ";
			cin >> op_menu;

		}
		while(op_menu < 1 && op_menu > 8);

		switch( op_menu)
		{
		case 1:
			CadPaciente();
			break;
		case 2:
			atendimento();
			break;
		case 3:
			listarCod();
			break;
		case 4:
			listar();
			break;
		case 5:
			pesquisar();
			break;
		case 6:
			editar();
			break;
		case 7:
			excluir();
			break;
		case 8:
			extra();
			break;
		default :
			sair();
			break;
		}

	}
	arquivo.close();
	arquivo2.close();
	return 0;
}
