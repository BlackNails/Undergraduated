#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<math.h>

using namespace std;

#define POP_SIZE                4            // ga population size
#define GA_MAXITER              10           // maximum iterations
#define GA_MUTATIONRATE 		0.001f       // mutation rate
#define GA_MUTATION             RAND_MAX * GA_MUTATIONRATE
#define STR_SIZE				5			//size of the individual

struct ga_struct
{
    string str;
	unsigned int fitness; 
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


void calc_fitness(ga_vector &population){
	
	unsigned int fitness;

    for (int i=0; i<POP_SIZE; i++) {
		
        fitness = 0;
        //calculate the fitness passing to dec value
        for(int j=0; j<STR_SIZE; j++) {
			if(population[i].str[j]=='1')
				fitness += pow(2,STR_SIZE -(j+1));
        }
        
        population[i].fitness = fitness*fitness;
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

void getMax(int &max,ga_vector &population){
	if(population[POP_SIZE-1].fitness > max)
	max = population[POP_SIZE-1].fitness;	
}
 
 bool fitness_sort(ga_struct x, ga_struct y){ return (x.fitness < y.fitness); }
 
 inline void sort_by_fitness(ga_vector &population)
 { sort(population.begin(), population.end(), fitness_sort); }


int main(){
	
    srand(unsigned(time(NULL)));
	
	int i1,i2,max=0;
	
	//aux strings
    string str1,str2 ;
    
    //population vector
    ga_vector population;
	
    init_population(population);
	
    cout << "Initial population" << endl;
    
    for(int i = 0 ; i < POP_SIZE ; i++)
        cout << "Individuo " << i << " " << population[i].str << endl;
    
    //cout << "----------------------------------------------------------" << endl;
	
	  
    for (int i=0; i<GA_MAXITER; i++) {
        
        cout << endl << "---------------------------------------------------------"<< endl;
        
        cout << "Generation i: "<< i <<endl;
        
        //cout << "Calculating Fitness Generation " << i << endl;
        
        calc_fitness(population);
        
         for(int i= 0 ; i<POP_SIZE;i++)
			cout << "Individuo " << i << " " << population[i].str << 
			" Fitness " << population[i].fitness << endl;
       /* for(int i = 0 ; i < POP_SIZE ; i++)
            cout << "Fitness " << i << " " << population[i].fitness << endl;*/
		
        i1 = rand()%4;
		 
		str1 = population[0].str.substr(i1,STR_SIZE-i1);

		// Crossing over 2 by 2
		
		population[0].str = population[0].str.substr(0,i1)
							+ population[1].str.substr(i1,STR_SIZE-i1);
		population[1].str = population[1].str.substr(0,i1)
							+ str1;
        //population[1].str.substr(i1+1,STR_SIZE-i1)= str1;
    
        //for(int i = i1+1,j = 0 ; i < STR_SIZE ; i++,j++)
           // population[1].str[i] = str1[j];
        //cout << "Crossing generations" << endl;
		
        i2 = rand()%4;
        
		str2 = population[2].str.substr(i2,STR_SIZE-i2);		
		
        population[2].str = population[2].str.substr(0,i2)
							+ population[3].str.substr(i2,STR_SIZE-i2);
		population[3].str = population[3].str.substr(0,i2)
							+ str2;
		
       // cout << "After Crossing" << endl;

       /* for(int i= 0 ; i<POP_SIZE;i++)
			cout << "Individuo " << i << " " << population[i].str << endl;*/
		
        
		
		//mutation
        for(int i=0;i<POP_SIZE;i++)
			if (rand() < GA_MUTATION){
                cout << "Individuo " << i << " " << "muto" << endl;
                mutate(population[i]);
            }
        
        //selection
        sort_by_fitness(population);
		
		//Getting the max value of a generation		
        getMax(max,population);
    }
	
	
	cout << endl <<  "Valor maximo " << max <<  endl;
	
	return 0;
}
