// Gustavo Blois nUSP = 13688162
// Pedro Moracci nUSP = 8556418

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int main(){

    /*declarando variáveis */
int geracoes;
int individuos;
int a, b, c, d, e, f;
int chance;
float distancia;
float melhor_distancia = 99;
float dist;
float me_dist;
/* fim da declaração de variáveis*/

srand(time(NULL)); //srand 

/*pedindo ao usuário detalhes sobre o AG */
printf("Insira o número de gerações: ");
scanf("%d",&geracoes);
printf("\nInsira o número de individuos por geração: ");
scanf("%d",&individuos);
//Declarando arrays agora que o tamanho é existente
int matriz_individuos[geracoes][individuos];
int melhor_x[geracoes];
int melhor_x_de_todos = 999;
float resultado_individuo[individuos];
//voltando a interagir com  o usuário
printf("Muito Bem! Este algoritmo pretende buscar as raízes de uma equação de quinto grau com o seguinte formato:\n ax^5 + bx^4 + cx^3 + dx^2 + ex + f\n");
printf("\nInsira o coeficiente a:");
scanf("%d",&a);
printf("\nInsira o coeficiente b:");
scanf("%d",&b);
printf("\nInsira o coeficiente c:");
scanf("%d",&c);
printf("\nInsira o coeficiente d:");
scanf("%d",&d);
printf("\nInsira o coeficiente e:");
scanf("%d",&e);
printf("\nInsira o coeficiente f:");
scanf("%d",&f);
printf("\n\nPor favor, insira a chance de mutação (um valor inteiro entre 0 e 100):");
scanf("%d",&chance);

printf("\nA equacao gerada eh %dx^5 + %dx^4 + %dx^3 + %dx^2 + %dx + %d\n",a,b,c,d,e,f);

//Gerando individuos
for(int i = 0; i < individuos;i++){
    matriz_individuos[0][i] = (rand() % 20) - 10;
    printf("individuo[%d] da geracao 0 = %d\n",i,matriz_individuos[0][i]);
    }

for(int ger = 0; ger < geracoes; ger++){
    for(int ind = 0; ind < individuos; ind++){
        resultado_individuo[ind] = a*pow(matriz_individuos[ger][ind],5) + b*pow(matriz_individuos[ger][ind],4) + c*pow(matriz_individuos[ger][ind],3) + d*pow(matriz_individuos[ger][ind],2) + e*matriz_individuos[ger][ind] + f;
        distancia = 0 - resultado_individuo[ind];
        if(distancia < 0){
            distancia *= -1;
        }
        if(distancia < melhor_distancia){
            melhor_distancia = distancia;
            melhor_x[ger] = matriz_individuos[ger][ind];
        } 
    }
    for(int m = 0; m < individuos; m++){
        matriz_individuos[ger+1][m] = matriz_individuos[ger][m] & melhor_x[ger];
            if((rand()%100) <= chance){
                 matriz_individuos[ger+1][m] =  matriz_individuos[ger+1][m] >> 1;
            } 
    }
    printf("O melhor individuo da geracao %d representa o valor %d\n",ger,melhor_x[ger]);
}

for(int i = 0; i < geracoes; i++){
    resultado_individuo[i] = a*pow(melhor_x[i],5) + b*pow(melhor_x[i],4) + c*pow(melhor_x[i],3) + d*pow(melhor_x[i],2) + e*melhor_x[i] + f;
    dist = 0 - resultado_individuo[i];
    if(dist < 0){
        dist *= -1;
    }
    if(i == 0){
        melhor_x_de_todos = melhor_x[i];
        me_dist = dist;
    }
    else if(dist < me_dist){
        melhor_x_de_todos = melhor_x[i];
        me_dist = dist;
        }
}

printf("O MELHOR VALOR DE X É %d!!!\n",melhor_x_de_todos);


return 0;
}