#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>

class neuron{
	protected:
	int activation;
	friend class network;
	public:
	int weightv[4];
	neuron(){};
	neuron(int *j);
	int act(int,int *);
};

class network{
	public:
		neuron nrn[4];
		int output[4];
		int threshld(int);
		void activation(int j[4]);
		network(int*,int*,int*,int*);
};

neuron::neuron(int *j){
	int i;
	int a = 0;
	for(i = 0; i < 4; i++){
		weightv[i] = *(j+1);
	}
}

int neuron::act(int m, int *x){
	int i;
	int a = 0;
	for(i = 0; i < m; i++){
		a+= x[i]*weightv[i];
	}
	return a;
}

int network::threshld(int k){
	if(k > 0){
		return 1;
	}else{
		return 0;
	}
}

network::network(int a[4],int b[4],int c[4],int d[4]){
	nrn[0] = neuron(a);
	nrn[1] = neuron(b);
	nrn[2] = neuron(c);
	nrn[3] = neuron(d);
}

void network::activation(int *patrn){
	int i,j;
	for(i = 0; i<4; i++){
		printf("\nNeuron[%d].Weightv[%d] is: %d ",i,j,nrn[i].weightv[j]);
	}
	nrn[i].activation = nrn[i].act(4,patrn);
	printf("\nActivation is : %d",nrn[i].activation);
	output[i]=threshld(nrn[i].activation);
	printf("\nOutput value is : %d \n ",output[i]);
	getch();	
}

int main(){
	int patrn1[] = {1,0,1,0},i;
	int wt1[] = {0,-2,2,-2};
	int wt2[] = {-2,0,-2,2};
	int wt3[] = {2,-2,0,-2};
	int wt4[] = {-2,2,-2,0};
	printf("-----------------------------------------------------------\n");
	printf("----------------------Made by C code champ-----------------\n");
	printf("-----------------------------------------------------------\n\n");
	printf("\t\tHOPFILED NETWORK ALGORITHM\n\n\n\n");
	/*create the network by calling its constructor.
	the constructor calls neuron constructor as many times as the number of
	neurons in the network.*/
	network h1(wt1,wt2,wt3,wt4);
	printf("\n\n\tPattern for 1010 :\n\n");
	/*Present a pattern to the network and get the activations of the neurons*/
	h1.activation(patrn1);
	/*check if the pattern given is correctly recalled and give message*/
	for(i = 0; i<4;i++){
		if(h1.output[i] == patrn1[i]){
			printf("\nPattern = %d output = %d component matches",patrn1[i],h1.output[i]);
		}else{
			printf("\nPattern= %d  output = %d  discrepancy occurred",patrn1[i],h1.output[i]);
		}
	}
	getch();
	printf("\n\n\n");
	int patrn2[]= {0,1,0,1};
	printf("\n\n\tPattern for 0101 :\n\n");
	h1.activation(patrn2);
	for(i = 0; i<4; i++){
		if(h1.output[i] == patrn2[i]){
			printf("\nPattern = %d output = %d component matches",patrn2[i],h1.output[i]);

		}else{
			printf("\nPattern= %d  output = %d  discrepancy occurred",patrn2[i],h1.output[i]);
		}
	}

}