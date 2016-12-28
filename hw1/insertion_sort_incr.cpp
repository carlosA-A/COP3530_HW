#include <vector>
#include <iostream>
using namespace std;

void printVector (vector <unsigned int> &vec);
void insertionSort(vector <unsigned int> &vec);

int main()
{	
//	std::ios_base::sync_with_stdio(false);


	vector <unsigned int> vec;
	int cases;
	cin >>cases;

	for (int i = 0,num; i < cases; i++)
	{
		cin >> num;	
		vec.push_back(num);
	}

	insertionSort(vec);
	printVector (vec);
	return 0;
}

void insertionSort (vector <unsigned int> &vec)
{
	for (int i =1; i<vec.size(); i++)
	{
		int key = vec[i];
		int j;
		for (j = i-1; vec[j]>key && j >= 0; j--)
			vec[j+1] = vec[j];

		vec[j+1]=key;
				
	}
	

}
void printVector (vector <unsigned int> &vec)
{
	for (int x:vec){
	
		std::cout <<x<<endl;
	}
	std::cout<<std::endl;
}
