/*
UNIVERSIDADE CATÓLICA DE BRASÍLIA
CURSO: ANÁLISE E DESENVOLVIMENTO DE SISTEMAS
DISCIPLINA: PROGRAMAÇÃO ESTRUTURADA
DOCENTE: JOYCE SIQUEIRA
DISCENTE: RAFAEL RIKI OGAWA OSIRO (UC21100716)

Exercício: 1. Desenvolva um programa em C utilizando registro que permita a entrada de nome, endereço e 
telefone de 3 pessoas e os imprima ao final.
*/

// !LIBRARIES _________________________________________________________________________________________________
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<stdbool.h>
#include<ctype.h>

//! STRUCTS ___________________________________________________________________________________________________
struct Pessoa
{
    char fullName[50];
    char addres[50];
    int phoneNumber;
};

//! MESSAGES OF THE SYSTEM ____________________________________________________________________________________
void messageTitle();
void messageMenu();
void messageNameInput(int index, int option);
void messageConfirmExit();
void messageExit();
void messageName(struct Pessoa *pessoas, int size);


//! ERROR MESSAGES OF THE SYSTEM ______________________________________________________________________________
void errorMessageInput(int quantityOfError, int option);
void errorExit();

//! VALIDATION INPUT __________________________________________________________________________________________
bool validationString(char *string);
bool validationNumber(int number);

//! FUNCTION OF THE SYSTEM ____________________________________________________________________________________
int functionOptionInput();
void functionInputString(struct Pessoa *pessoa, int size);


int main()
{
    int option, quantityOfError = 0, size;
    struct Pessoa pessoas[3];
    bool validation = false, exitValidation = false;

    size = sizeof(pessoas)/sizeof(pessoas[0]);

    do
    {
        messageTitle();
        messageMenu();
        option = functionOptionInput();

        switch (option)
        {
        case 1:
            system("cls");
            quantityOfError = 0;
            
            functionInputString(pessoas, size);
            messageName(pessoas, size);
            break;
        
        case 2:
            system("cls");
            quantityOfError = 0;
            
            do
            {
                messageConfirmExit();
                option = functionOptionInput();

                if (option == 1)
                {
                    exitValidation = true;
                    validation = true; 
                }
                else if(option == 2)
                {
                    exitValidation = true;
                    validation = false;
                }
                else
                {
                    exitValidation = false;
                    system("cls");
                    quantityOfError++;
                    errorMessageInput(quantityOfError, 1);

                    if (quantityOfError == 3)
                    {
                        errorExit();
                        exit(EXIT_FAILURE);
                    }    
                }

            } while (exitValidation == false);


            system("cls");
            quantityOfError = 0;
            
            break;

        default:
            system("cls");
            quantityOfError++;
            errorMessageInput(quantityOfError, 1);

            if (quantityOfError == 3)
            {
                errorExit();
                exit(EXIT_FAILURE);
            }
            break;
        }
    
    } while (validation == false);
    
    messageExit();
    exit(EXIT_SUCCESS);
}

//! MESSAGES OF THE SYSTEM ____________________________________________________________________________________

//  MESSAGE TITLE OF THE SYSTEM
void messageTitle()
{
    printf("SISTEMA PARA FORMATAR OS NOMES\n\n\n");
}

//  MESSAGE MENU
void messageMenu()
{
    printf("---------------------------------\n");
    printf("[1] ENTRADA DE NOMES E FORMATA\200\307O\n");
    printf("[2] SAIR DO PROGRAMA\n");
    printf("---------------------------------\n\n");
    printf("DIGITE A OP\200\307O DESEJADA: ");
}

//  MESSAGE ASK NAME INPUT
void messageNameInput(int index, int option)
{
    switch (option)
    {
    case 1:
        printf("DIGITE O NOME DO USU\265RIO %d: ", index);
        break;
    
    case 2:
        printf("DIGITE O ENDERE\200O DO USU\265RIO %d: ", index);
        break;

    case 3:
        printf("DIGITE O TELEFONE DO USU\265RIO %d: ", index);
        break;

    default:
        break;
    }
}

//  MESSAGE ASK CONFIRM EXIT OF THE SYSTEM
void messageConfirmExit()
{
    printf("DESEJA CONFIRMAR A SA\326DA DO SISTEMA?\n\n");
    printf("-------\n");
    printf("[1] SIM\n");
    printf("[2] N\307O\n");
    printf("-------\n\n");
    printf("DIGITE A OP\200\307O DESEJADA: ");
}

//  MESSAGE TO EXIT SYSTEM
void messageExit()
{
    printf("O SISTEMA IR\265 FINALIZAR\n");
}

//  MESSAGE TO PRINT THE NAMES
void messageName(struct Pessoa *pessoas, int size)
{
    for (int i = 0; i <= size; i++)
    {
        printf("PESSOA %d", i+1);
        printf("Nome: %s\n", pessoas[i].fullName);
        printf("Endere\207o: %s\n", pessoas[i].addres);
        printf("Telefone: %d", pessoas[i].phoneNumber);
    }
}

//! ERROR MESSAGES OF THE SYSTEM ______________________________________________________________________________

//  ERROR MESSAGE INPUT
void errorMessageInput(int quantityOfError, int option)
{
    switch (option)
    {
    case 1:
        printf("ERRO %d de 3!\n", quantityOfError);
        printf("DIGITE UMA OP\200\307O V\265LIDA\n\n\n");
        break;
    
    case 2:
        printf("ERRO %d de 3!\n", quantityOfError);
        printf("DIGITE UM NOME V\265LIDO\n\n\n");
        break;

    case 3:
        printf("ERRO %d de 3!\n", quantityOfError);
        printf("DIGITE UM N\351MERO V\265LIDO COM 9 D\326GITOS!\n\n\n");
        break;

    default:
        break;
    }
}

//  ERROR EXIT SYSTEM
void errorExit()
{
    printf("QUANTIDADE DE ERROS ATINGIDO!\n");
    printf("O SISTEMA IR\265 FINALIZAR!\n\n\n");
}

//! VALIDATION INPUT __________________________________________________________________________________________

//  FUNCTION TO VALIDATE A STRING
bool validationString(char *string)
{
    int index = 0;

    if (strlen(string) == 1)
    {
        if (string[index] == "\n" || string[index] == " " || string[index] == '\0' || string[index] == '\r' || 
        string[index] == '\r\n' || !isalpha(string[index] || !isdigit(string[index])))
        {
            return false;
        }
    }
    else
    {
        while (index < strlen(string))
        {
            if (string[index] != "\n" && string[index] != " " && string[index] != '\0' && string[index] != '\r' && 
            string[index] != '\r\n' && !isspace(string[index]) && (isalpha(string[index]) || isdigit(string[index])))
            {
                return true;
            }
            index++;
        }

        return false;
    }

    return false;
}

//  FUNCTION TO VALIDATE A NUMBER
bool validationNumber(int number)
{
    if (number < 0)
    {
        return false;
    }
    else if (number >= 0 && number < 100000000)
    {
        return false;
    }
    else if (number < 1000000000)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//! FUNCTION OF THE SYSTEM ____________________________________________________________________________________

//  FUNCTION OPTION INPUT
int functionOptionInput()
{
    int number;

    fflush(stdin);
    scanf("%d", &number);

    return number;
}

//  FUNCTION INPUT STRING
void functionInputString(struct Pessoa *pessoa, int size)
{
    int quantityOfError = 0, count = 0;
    bool validation = false;

    for (int i = 0; i <= size; i++)
    {
        messageTitle();
        while (validation == false)
        {
            messageNameInput(i+1, 1);
            fflush(stdin);
            fgets(pessoa[i].fullName, sizeof(pessoa[i].fullName), stdin);
            validation = validationString(pessoa[i].fullName);

            if (strlen(pessoa[i].fullName) == sizeof(pessoa[i].fullName))
            {
                char charactere;
                while ((charactere = getchar()) != '\n' && charactere != EOF);
            }

            if (validation == false)
            {
                system("cls");
                quantityOfError++;
                errorMessageInput(quantityOfError, 2);

                if (quantityOfError == 3)
                {
                    errorExit();
                    exit(EXIT_FAILURE);
                }
            }
        }

        system("cls");
        count = 0;
        validation = false;

        messageTitle();
        while (validation == false)
        {
            messageNameInput(i+1, 2);
            fflush(stdin);
            fgets(pessoa[i].addres, sizeof(pessoa[i].addres), stdin);
            validation = validationString(pessoa[i].addres);

            if (strlen(pessoa[i].fullName) == sizeof(pessoa[i].fullName))
            {
                char charactere;
                while ((charactere = getchar()) != '\n' && charactere != EOF);
            }

            if (validation == false)
            {
                system("cls");
                quantityOfError++;
                errorMessageInput(quantityOfError, 2);

                if (quantityOfError == 3)
                {
                    errorExit();
                    exit(EXIT_FAILURE);
                }
            }
        }

        system("cls");
        count = 0;
        validation = false;
        
        while (validation == false)
        {
            messageNameInput(i+1, 3);
            fflush(stdin);
            scanf("%d", &pessoa[i].phoneNumber);

            validation = validationNumber(pessoa[i].phoneNumber);
            if (validation == false)
            {
                system("cls");
                quantityOfError++;
                errorMessageInput(quantityOfError, 3);

                if (quantityOfError == 3)
                {
                    errorExit();
                    exit(EXIT_FAILURE);
                }
            }
        }
    }
}