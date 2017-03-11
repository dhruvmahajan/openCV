#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

class class1{
	public:
	static int var1;

};

int class1::var1(1);


void *fun(void *arg){
	while(1){
		usleep(1000000);
		class1::var1=rand()%100;
		cout<<"Thread"<<endl;
	}

}

int main(){
	pthread_t thread;
	class1 one;
	pthread_create(&thread, NULL, fun, NULL);

	while(1){
		usleep(1000000);
		cout<<"Main: "<<class1::var1<<endl;
	
	}


}
