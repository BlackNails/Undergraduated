#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <math.h>
#include <fstream>

using namespace std;

#define POP_SIZE        50
#define GA_MAXITER      100
#define GA_MUTATIONRATE 0.01f
#define GA_MUTATION     RAND_MAX*GA_MUTATIONRATE
#define STR_SIZE        48
#define GRID_SIZE       24
#define ELITERATE 		0.1f
struct ga_struct{
    string str;
    double fitness;
};

typedef vector<ga_struct> ga_vector;

void init_population(ga_vector &population){
    for(int i = 0 ; i < POP_SIZE ; i++){
        ga_struct citizen;
        citizen.fitness = 0;
        for(int j = 0 ; j < STR_SIZE ; j++)
            citizen.str += (rand()%2)+48;
        population.push_back(citizen);
    }
}

int binToDec(string bin){
    int dec = 0;
    for(int i = 0 ; i < STR_SIZE/2 ; i++)
        if(bin[i] == '1')
            dec += pow(2,STR_SIZE/2-(i+1));
    return dec;
}

double calcPoint(string bin){
    double point;
    point = 20/(pow(2,GRID_SIZE)-1);
    point *= (binToDec(bin)*1.0);
    point-=10;
    return point;
}

void calc_fitness(ga_vector &population){
    double fitness;
    double x,y;
    string stry;
    for(int i=0;i<POP_SIZE;i++){
        x = calcPoint(population[i].str.substr(0,STR_SIZE/2));
        stry = population[i].str.substr(STR_SIZE/2,STR_SIZE/2);
        y = calcPoint(stry);
      //  cout << x << " " << y << " " <<stry << " "<< endl;
        fitness = pow(sin(sqrt(pow(x,2)+pow(y,2))),2);
        fitness *=(-1);
        fitness++;
        fitness/=(1+0.001*(pow(x,2)+pow(y,2)));
        population[i].fitness = fitness;
    }
}

void mutate(ga_struct &member){
    int i = rand()%STR_SIZE;
    if(member.str[i] == '0')
        member.str[i] = '1';
    else
        member.str[i] = '0';
}

void getMax(double &max,ga_vector &population){
    if(population[POP_SIZE-1].fitness>max)
        max = population[POP_SIZE-1].fitness;
}

bool fitness_sort(ga_struct x , ga_struct y){
    return (x.fitness < y.fitness);
}

inline void sort_by_fitness(ga_vector &population){
    sort(population.begin(),population.end(),fitness_sort);
}

void crossOver(ga_vector &population){

    int i1,i2,i;
    
    string str1;
    int esize = ELITERATE * POP_SIZE;
    
    i1 = rand()%(POP_SIZE - esize) + esize;
    i2 = rand()%(POP_SIZE - esize) + esize;
    i = rand()%(STR_SIZE/2);
    
    
    //CrossOver x 
    str1 = population[i1].str.substr(i,STR_SIZE/2-i);
    
    population[i1].str = population[i1].str.substr(0,i)
        +population[i2].str.substr(i,STR_SIZE/2-i)
        +population[i1].str.substr(STR_SIZE/2,STR_SIZE/2);

    population[i2].str = population[i2].str.substr(0,i)+str1
        +population[i2].str.substr(STR_SIZE/2,STR_SIZE/2);
    
    //CrossOver y
    i = rand()%(STR_SIZE/2)+STR_SIZE/2;
    str1 = population[i1].str.substr(i,STR_SIZE-i);
    
    population[i1].str = population[i1].str.substr(0,i)
        +population[i2].str.substr(i,STR_SIZE-i);
    population[i2].str = population[i2].str.substr(0,i)
        +str1;

}
int main(){
    
    srand(unsigned(time(NULL)));

    int i1 , i2;

    double max = 0 , x , y;
    
    int esize = POP_SIZE * ELITERATE;

    string str1 , str2;

    ga_vector population;

    ofstream points;

    init_population(population);
    
    calc_fitness(population);

    /*file that contains the begining points*/

    points.open("begining.txt");

    for(int i = 0 ; i < POP_SIZE ; i++){
        x = calcPoint(population[i].str.substr(0,STR_SIZE/2));
        str1 = population[i].str.substr(STR_SIZE/2,STR_SIZE/2);
        y = calcPoint(str1);
        points << x << " " << y << " " << population[i].fitness << endl;
    }
    points.close();


/*    cout << "Initial population" << endl;

    for(int i = 0; i < POP_SIZE ; i++)
        cout << "Individuo" << i << " " << population[i].str << endl;*/

    for(int i = 0 ; i < GA_MAXITER ; i++){

        cout << "--------------------------------------------------" << endl;
        cout << "Generation " << i << endl;

        for(int i = 0 ; i < POP_SIZE ; i++)
            cout << "Individuo " << i << " " << population[i].str << 
                " Fitness " << population[i].fitness << endl;
        sort_by_fitness(population);
        //CrossOver and elitism
		
		
        for(int i = esize ; i < POP_SIZE ; i++)
            crossOver(population);
        
        calc_fitness(population);
        //Mutation
        
        for(int i = 0; i < POP_SIZE ; i++)
            if(rand() < GA_MUTATION){
                mutate(population[i]);
            }
        //selection
        sort_by_fitness(population);

        //Getting the max value of a generation
        getMax(max,population);
        
    }
    
    /*Last points obtained*/
    points.open("end.txt");

    for(int i = 0 ; i < POP_SIZE ; i++){

        x = calcPoint(population[i].str.substr(0,STR_SIZE/2));
       
        str1 = population[i].str.substr(STR_SIZE/2,STR_SIZE/2);
        
        y = calcPoint(str1);
        
        points << x << " " << y  << " " << population[i].fitness << endl;
    
   // points.close();

    //cout << endl << "MAx value of function is " << max << endl;
    }

points.close();
cout << endl << "Max value of functions is " << max << endl;
}
