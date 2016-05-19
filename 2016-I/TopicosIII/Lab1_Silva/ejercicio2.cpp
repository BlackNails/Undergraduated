#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<math.h>

using namespace std;

#define POP_SIZE                6            // ga population size
#define GA_MAXITER              50           // maximum iterations
#define GA_MUTATIONRATE 		0.005f       // mutation rate
#define GA_MUTATION             RAND_MAX * GA_MUTATIONRATE
#define STR_SIZE				16			//size of the individual
#define GRID_SIZE				16
struct ga_struct
{
    string str;
	double fitness; 
};

typedef vector<ga_struct> ga_vector;

void init_population(ga_vector &population){
        
	for (int i=0; i<POP_SIZE; i++) {
		
        ga_struct citizen;

        citizen.fitness = 0;
	// Initializing the string with '1's and '0's 
		for (int j=0; j<STR_SIZE; j++)
             citizen.str += (rand() % 2) + 48;
	
       population.push_back(citizen);
    
    }
     
}

int binToDec( string bin){
	
	int dec = 0;
	
	for(int i = 0 ; i < STR_SIZE ; i++ ){
		if(bin[i] == '1')
			dec += pow(2,STR_SIZE-(i+1));
	}
	return dec;
	
}

double calcPoint(string bin){
	double point;
	
	point = 2/(pow(2,GRID_SIZE)-1);
	point *= (binToDec(bin)*1.0);
	point--; 
	return point;
}


void calc_fitness(ga_vector &population){
	
	double fitness;
	double point ;
    for (int i=0; i<POP_SIZE; i++) {
    	point = calcPoint(population[i].str);
		fitness = exp(-1*pow(point,2));
		fitness *= cos(36*point);
		fitness ++;
        
        population[i].fitness = fitness;
        }
        

    }


//mutate 1 character to it's opposite
void mutate(ga_struct &member){
	int i = rand()%STR_SIZE;
	if(member.str[i] == '0')
		member.str[i] = '1';
    else
		member.str[i] = '0';
}

//Get the max Value in one Generation

void getMax(double &max,ga_vector &population){
	if(population[POP_SIZE-1].fitness > max)
	max = population[POP_SIZE-1].fitness;	
}
 
 bool fitness_sort(ga_struct x, ga_struct y){ return (x.fitness < y.fitness); }
 
 inline void sort_by_fitness(ga_vector &population)
 { sort(population.begin(), population.end(), fitness_sort); }

void crossOver(ga_vector &population){
	int i1,i2,i;
	string str1;
	i1 = rand()%(POP_SIZE/2);
	i2 = rand()%(POP_SIZE/2);
	i = rand()%(STR_SIZE-1);
	str1 = population[i1].str.substr(i,STR_SIZE-i);
	population[i1].str = population[i1].str.substr(0,i)
					+ population[i2].str.substr(i,STR_SIZE-i);
	population[i2].str = population[i2].str.substr(0,i)+ str1;
}

int main(){
	
    srand(unsigned(time(NULL)));
	
	int i1,i2;
	
	double max = 0;
	
	//aux strings
    string str1,str2 ;
    
    //population vector
    ga_vector population;
	
    init_population(population);
	
    cout << "Initial population" << endl;
   
    for(int i = 0 ; i < POP_SIZE ; i++)
        cout << "Individuo " << i << " " << population[i].str << endl;
    

	
	  
    for (int i=0; i<GA_MAXITER; i++) {

		calc_fitness(population);        
        
        cout << "----------------------------------------------------------" << endl;
       
        cout << "Generacion " << i << endl;
       
        for(int i = 0 ; i < POP_SIZE ; i++)
       		cout << "Individuo " << i << " " << population[i].str << " Fitness "
       		<< population[i].fitness << endl;
       

        
        		
        /*for(int i= 0 ; i<POP_SIZE;i++)
			cout << endl << "Individuo " << i << " " << population[i].str << endl;*/
		       
		
		//crossOver
		
		for(int i=0;i<POP_SIZE;i++)
			crossOver(population);
		
        //mutation
        for(int i=0;i<POP_SIZE;i++)
			if (rand() < GA_MUTATION){
                //cout << "Individuo " << i << " " << "muto" << endl;
                mutate(population[i]);
            }
        
        //selection
        sort_by_fitness(population);
		
		//Getting the max value of a generation		
        getMax(max,population);
        
      // 	cout << " Maximo : " << max << endl;	
    }
	
	/*for(int i = 0; i < POP_SIZE ; i++)
		cout << population[i].fitness << endl;*/
	
	cout << endl <<  "Valor maximo de la funcion es " << " " << max <<  endl;
	
	return 0;
}
