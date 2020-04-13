#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ConvertBinaryNumberToDecimal(int binary);
//programar um conversor de até 8 digitos binarios para decimal
int main()
{

    int num_bin;
    int num_dec;

    printf("Insira um numero binario:\n");
    //repetição para receber o retorno da função inteira(-1 ou o numero decimal natural)
    do
    {
        scanf("%i", &num_bin);

        num_dec = ConvertBinaryNumberToDecimal(num_bin);

    }while (num_dec == -1);

    printf("%i\n", num_dec);

    system("pause");
    return 0;
}

//função para achar quantos digitos são
//sendo passado como parametro um int binary que vai ser visto quantos
//digitos serão e retornando o valor em decimal
int ConvertBinaryNumberToDecimal(int binary)
{

    int number = 0;
    int count_digit = 0;
    int compare_number = binary;

    int i;

    //repetição para achar o número de digitos
    do
    {
        count_digit++;
        compare_number /= 10;
    } while (compare_number != 0);

    //repetição pra saber se tem algum
    //digito menos que 0 e maior que 1
    //se tiver ele retorna -1 para ler o numero de novo
    for (i = 0; i <= count_digit; i++)
    {
        if ((((int)(binary / pow(10, i)) % 10)) < 0 || (((int)(binary / pow(10, i)) % 10)) > 1)
        {
            printf("O numero contem digitos invalidos(so podem 0 ou 1)\n");
            return -1;
        }
    }

    //se ele estiver passado da repetição anterior
    //ele irá para essa repetição para atribuir uma operação
    //que transforma o numero binário em decimal
    for (i = 0; i <= count_digit; i++)
    {
        number += (int)(((int)(binary / pow(10, i)) % 10) * pow(2, i));
    }

    //retorna o numero binario em decimal em N
    return number;
}