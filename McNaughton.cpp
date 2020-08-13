#include <iostream>
#include<algorithm> 
#include <cmath>
using namespace std;

int numberOfProcessors;
int numberOfTasks;
double duration;
double *tasks;
double Cmax;
double CalculateCMax(int numOfT, double numOfP);
void StartAlgorythm();

double CalculateCMax(int numOfT, double numOfP) {
	numOfT = numberOfTasks;
	numOfP = numberOfProcessors;
	double tempsum = 0;
	for (int i = 0; i < numOfT; i++) {
		tempsum += tasks[i];
	 }
	double tempMax = tasks[0];
	for (int i = 0; i < numOfT; i++) {
		if (tasks[i] > tempMax)
			tempMax = tasks[i];
	}
	double avr = (tempsum/numOfP);
	Cmax = max(tempMax,avr);
	cout << "Cmax: " << Cmax << endl;
	return Cmax;
}

void StartAlgorythm() {
	
	//double tempduration = 0;
	int j = 0;
	int jcopy = 0;
	
	for (int i = 0; i < numberOfProcessors; i++) {

		
			double tempduration = 0.0;
			j = jcopy;
			cout << endl;
			cout << "Processor " << i + 1 <<endl<< "tasks: " << endl;

			for (j; j < numberOfTasks; j++)
			{
				double tmpDur = tempduration + tasks[j];

				if (tmpDur > Cmax)
				{
					double difference;
					difference= tasks[j] - (tmpDur - Cmax);
					double tmptask = difference;
					tasks[j] = tasks[j] - difference;
					
					cout << "Task " << j+1 <<" duration: " <<tmptask << endl;

					jcopy = j;
					j = numberOfTasks; // wyjscie z petli taskows
				}

				

				else
				{
					if (tasks[j] == 0) {
						continue;
					}
					tempduration += tasks[j];

					cout <<"Task "<< j+1 << " duration: " << tasks[j] << endl;

					
					if (abs(tempduration - Cmax) < 0.001)
					{
						jcopy = j + 1;
						j = numberOfTasks; 
					}

				}
			}		
	}

}



int main()
{
   cout << "Write number of processors: \n";
   cin >> numberOfProcessors;
   cout << "Write number of tasks: \n";
   cin >> numberOfTasks;
   tasks = new double[numberOfTasks];
   
   for (int i = 0; i < numberOfTasks; i++) {
	   cout << "Write duration of  " << i+1 <<" task:      ";
	   cin >> duration;
	   tasks[i] = duration;

   }

   CalculateCMax(numberOfTasks, numberOfProcessors);
   StartAlgorythm();
}
