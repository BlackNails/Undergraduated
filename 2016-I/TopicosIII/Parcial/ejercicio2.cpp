#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <math.h>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

#define POP_SIZE        250
#define GA_MAXITER      1000
#define GA_MUTATIONRATE 0.01f
#define GA_MUTATION     RAND_MAX*GA_MUTATIONRATE
#define VOPT        	675
#define PELITE			0.2f
#define NVAR			1000
#define PESOLIM			50
#define PXOVER			0.35f

struct carga{
	double peso[NVAR];
	double valor[NVAR];
	bool elegido[NVAR];
	int fitness;
};

typedef vector<carga> cargaVector;

/* Escoge quienes son elegidos con una probabilidad*/
void elegidos(bool elegido[NVAR]){

	for(int i = 0 ; i < NVAR ; i++){
		double val = (double)rand()/RAND_MAX;
		elegido[i] = false;
		if(val < 0.01)
			elegido[i] = true;
	}
			
}

/*Inicializa la poblacion de cargas*/
void init_population(cargaVector &population){

	double pesos[NVAR];
	double valores[NVAR];
	
	ifstream valFile;
	ifstream pesoFile;
	
	double valor;
	double peso;
	
	int i = 0;
	
	//bool elegidos[NVAR];
	
	valFile.open("valores.txt");
    pesoFile.open("pesos.txt");
    
    
    if(valFile.is_open()){
    	while(valFile >> valor && pesoFile >> peso){
    		pesos[i] = peso;
    		valores[i]  = valor;
    		i++;
    	}
    	valFile.close();
    }
    
    for(int i = 0 ; i < POP_SIZE ; i++){
        carga citizen;
        citizen.fitness = 0;
        for(int j = 0 ;j < NVAR ;j++){
        	citizen.peso[j] = pesos[j];
        	citizen.valor[j] = valores[j];
        	citizen.elegido[j] = false;
        }
        elegidos(citizen.elegido);
        
        population.push_back(citizen);
    }
}


int fitness(carga &cargaActual){
	int fit=0;
	int pesos = 0;
	int desc;
	for(int i = 0 ; i < NVAR ; i++){
		if(cargaActual.elegido[i] == true){
			fit+=cargaActual.valor[i];
			pesos+=(cargaActual.peso[i]);
		}
	}
	if(pesos > PESOLIM){
		desc = 7*(pesos - PESOLIM);
		fit -=desc;
	}
	cargaActual.fitness = fit;
	return fit;

}

void crossOver(carga& c1, carga& c2 , carga& c3, const int randcross = rand()%NVAR+1 ){
	for(int i = 0 ; i < NVAR ; i++){
		if(i<randcross)
			c3.elegido[i] = c1.elegido[i];
		else
			c3.elegido[i] = c2.elegido[i];
	
	}
}

void mutate(cargaVector &population){
	int start = POP_SIZE*PELITE;
	for(int j = start ; j < POP_SIZE ; j++)
		for(int i = 0 ; i < NVAR ; i++)
			population[j].elegido[i] = !population[j].elegido[i];
    
}

bool fitness_sort(carga x , carga y){
    return (x.fitness > y.fitness);
}

inline void sort_by_fitness(cargaVector &population){
    sort(population.begin(),population.end(),fitness_sort);
}


int main(){
	clock_t begin;
	clock_t end;
    /*Nuestra poblacion total*/
    cargaVector cargaTotal;
    srand(time(NULL));

	 /*inicializa poblacion*/
    init_population(cargaTotal);
		
	/*Calcular el fitness inicial*/	
	for(int i = 0 ; i < POP_SIZE ; i++)
		fitness(cargaTotal[i]);
		
	/*ORdenamos los valores*/
	sort_by_fitness(cargaTotal);
	cout << " Calculando..." << endl;
	begin = clock();
	/*Iteramos en 1000 generaciones*/
	for(int i = 0 ; i < NVAR;i++){
		int start = POP_SIZE*PELITE;	
		/*Cross over con probabilidad*/
		for( int j = start ; j < POP_SIZE ; j++ ){
			int i1 = rand()% start;
			int i2 = rand()% start;
			double pcross = (double)rand()/RAND_MAX ;
			if(pcross< PXOVER ){
				crossOver(cargaTotal[i1],cargaTotal[i2],cargaTotal[j]);
				//cout << "Se cruzo " << endl;
			}
		}
		for(int i = 0 ; i < POP_SIZE;i++)
			fitness(cargaTotal[i]);

		
		mutate(cargaTotal);
		sort_by_fitness(cargaTotal);
	}
	
	end = clock();
	
	cout << "Terminado en "<< (double)(end - begin)/1000000 <<" segundos "<< " El valor optimo es :";
	cout << cargaTotal[0].fitness << endl;
}
